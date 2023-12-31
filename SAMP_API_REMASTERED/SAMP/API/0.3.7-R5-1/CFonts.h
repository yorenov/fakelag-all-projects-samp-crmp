/*
	This is a SAMP (0.3.7-R5) API project file.
	Developers: LUCHARE <luchare.dev@gmail.com>, Northn
	
	See more here https://github.com/LUCHARE/SAMP-API
	
	Copyright (c) 2018 BlastHack Team <BlastHack.Net>. All rights reserved.
*/

#pragma once

#include "../sampapi.h"
#include "../CRect.h"
#include "CFont.h"

#undef DrawText

SAMPAPI_BEGIN_PACKED_V037R5_1

class SAMPAPI_EXPORT CFonts {
public:
    CFont*            m_pFont;
    CFont*            m_pLittleFont;
    CFont*            m_pShadow;
    CFont*            m_pLittleShadow;
    CFont*            m_pLicensePlateFont;
    ID3DXSprite*      m_pDefaultSprite;
    IDirect3DDevice9* m_pDevice;
    char*             m_szTempBuffer;
    int               m_nCharHeight;
    int               m_nLittleCharHeight;

    CFonts(IDirect3DDevice9* pDevice);
    ~CFonts();

    void OnLostDevice();
    void OnResetDevice();
    void GetTextScreenSize(void* pSize, const char* szText, int nFormat);
    void GetLittleTextScreenSize(void* pSize, const char* szText, int nFormat);
    void DrawText(ID3DXSprite* pSprite, const char* szText, CRect rect, D3DCOLOR color, BOOL bShadow);
    void DrawLittleText(ID3DXSprite* pSprite, const char* szText, CRect rect, int nFormat, D3DCOLOR color, BOOL bShadow);
    void DrawLicensePlateText(const char* szText, CRect rect, D3DCOLOR color);
    void Reset();
};

SAMPAPI_EXPORT SAMPAPI_VAR CFonts*& RefFontRenderer();

SAMPAPI_END_PACKED
