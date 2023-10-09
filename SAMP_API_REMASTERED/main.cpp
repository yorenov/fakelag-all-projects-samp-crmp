#include "main.h"

bool bIsPluginInitialized = false;

bool menustate, activew;
int id_p = 100;
bool skip = false;

auto __stdcall RakClientSendHook(SAMP::CallBacks::HookedStructs::stRakClientSend* params) -> bool
{
	if (skip)
	{
		stOnFootData data;
		memset(&data, 0, sizeof(stOnFootData));
		byte packet;

		params->bitStream->ResetReadPointer();
		params->bitStream->Read(packet);
		params->bitStream->Read((PCHAR)&data, sizeof(stOnFootData));

		static ULONGLONG dwSyncTick = GetTickCount();
		if (GetTickCount() - dwSyncTick > (ULONGLONG)id_p)
			dwSyncTick = GetTickCount();
		else if (!data.stSampKeys.keys_aim == 1)
			return false;
	}
	return true;
}

auto __stdcall WndProcCallBack(SAMP::CallBacks::HookedStructs::stWndProcParams* params) -> LRESULT
{
	if (!bIsPluginInitialized)
		return 0;

	if (ImGui_ImplWin32_WndProcHandler(params->hWnd, params->uMsg, params->wParam, params->lParam))
		return 1;

	return 0;
}

auto __stdcall D3DPresentHook(SAMP::CallBacks::HookedStructs::stPresentParams* params) -> HRESULT
{
	if (!bIsPluginInitialized)
		return D3D_OK;

	ImGui_ImplDX9_NewFrame();
	ImGui_ImplWin32_NewFrame();
	ImGui::NewFrame();

	if (activew)
	{
		ImGui::Begin(xorstr(u8"fakelag by edgekich"), 0, ImGuiWindowFlags_AlwaysAutoResize | ImGuiWindowFlags_NoSavedSettings);
		ImGui::Text(xorstr(u8"Author: https://www.youtube.com/@edgekich"));
		ImGui::Checkbox(xorstr(u8"Включить"), &skip);
		ImGui::SliderInt(xorstr(u8"Задержка"), &id_p, 1, 2000);
		ImGui::End();
	}

	ImGui::EndFrame();
	ImGui::Render();
	ImGui_ImplDX9_RenderDrawData(ImGui::GetDrawData());

	return D3D_OK;
}

auto __stdcall D3DResetHook(SAMP::CallBacks::HookedStructs::stResetParams* params) -> HRESULT
{
	if (!bIsPluginInitialized)
		return D3D_OK;

	ImGui_ImplDX9_InvalidateDeviceObjects();

	return D3D_OK;
}

auto __cdecl cmd(const char* szParams) {
	activew ^= true;
}

auto __stdcall GameLoop(void) -> void
{
	if (!bIsPluginInitialized)
	{
		if (SAMP::pSAMP->LoadAPI())
		{
			ImGui::CreateContext();
			ImGuiIO& io = ImGui::GetIO();
			char font_dir[MAX_PATH] = { 0 };
			sprintf(font_dir, "%s\\Windows\\Fonts\\Arial.ttf", getenv("SystemDrive"));
			io.Fonts->AddFontFromFileTTF(font_dir, 16, NULL, ImGui::GetIO().Fonts->GetGlyphRangesCyrillic());
			(void)io;
			ImGui_ImplWin32_Init(GetActiveWindow());
			ImGui_ImplDX9_Init(SAMP::CallBacks::pCallBackRegister->GetIDirect3DDevice9());
			ImGui::GetIO().ConfigFlags |= ImGuiConfigFlags_NoMouseCursorChange;

			*SAMP::CallBacks::pCallBackRegister += RakClientSendHook; // registering an outgoing packet handler
			SAMP::pSAMP->addClientCommand("fakelag", cmd);

			bIsPluginInitialized = true;
		}
	}
	else
	{
		if (menustate != activew) {
			showCursor(activew);
			menustate = activew;
		}
	}
}

int __stdcall DllMain(HMODULE hModule, DWORD dwReason, LPVOID lpReserved)
{
	switch (dwReason)
	{
		case DLL_PROCESS_ATTACH:
		{
			SAMP::samp_ver ver = SAMP::GetSAMPVer();
			switch (ver)
			{
				case SAMP::samp_ver::v037r1:
				case SAMP::samp_ver::v037r31:
				case SAMP::samp_ver::v037r51:
					break;
				default: 
				{
					char path[MAX_PATH] = { 0 };
					GetModuleFileNameA(hModule, path, MAX_PATH);
					char* szFileName = PathFindFileNameA(path);
					char message[64] = { 0 };
					sprintf(message, "SA-MP %s is not supported", SAMP::str_samp_ver[ver].c_str());
					MessageBoxA(0, message, szFileName, 0);
					return FALSE;
				}
			}

			SAMP::Init();
			*SAMP::CallBacks::pCallBackRegister += GameLoop;
			*SAMP::CallBacks::pCallBackRegister += WndProcCallBack;
			*SAMP::CallBacks::pCallBackRegister += D3DPresentHook;
			*SAMP::CallBacks::pCallBackRegister += D3DResetHook;

			printf("\n -> Plugin loaded (%llu)\n", GetTickCount64());
			break;
		}
		case DLL_PROCESS_DETACH:
		{
			SAMP::ShutDown();

			ImGui_ImplDX9_Shutdown();
			ImGui_ImplWin32_Shutdown();
			ImGui::DestroyContext();

			printf("\n -> Plugin unloaded (%llu)\n", GetTickCount64());
			break;
		}
	}
	return TRUE;
}