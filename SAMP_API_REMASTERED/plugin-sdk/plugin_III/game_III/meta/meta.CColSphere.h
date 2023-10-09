/*
    Plugin-SDK (Grand Theft Auto 3) header file
    Authors: GTA Community. See more here
    https://github.com/DK22Pac/plugin-sdk
    Do not delete this comment block. Respect others' work!
*/
#include "PluginBase.h"

namespace plugin {

CTOR_META_BEGIN(CColSphere)
static int address;
static int global_address;
static const int id = 0x411520;
static const bool is_virtual = false;
static const int vtable_index = -1;
using mv_addresses_t = MvAddresses<0x411520, 0x411520, 0x411520>;
// total references count: 10en (12), 11en (12), steam (12)
using refs_t = RefList<0x410C12,100,2,0,1, 0x413682,100,2,0,1, 0x41369A,100,2,0,1, 0x4136B2,100,2,0,1, 0x4136CA,100,2,0,1, 0x4136E2,100,2,0,1, 0x4136FA,100,2,0,1, 0x413712,100,2,0,1, 0x41372A,100,2,0,1, 0x413742,100,2,0,1, 0x41375A,100,2,0,1, 0x413772,100,2,0,1, 0x410C12,110,2,0,1, 0x413682,110,2,0,1, 0x41369A,110,2,0,1, 0x4136B2,110,2,0,1, 0x4136CA,110,2,0,1, 0x4136E2,110,2,0,1, 0x4136FA,110,2,0,1, 0x413712,110,2,0,1, 0x41372A,110,2,0,1, 0x413742,110,2,0,1, 0x41375A,110,2,0,1, 0x413772,110,2,0,1, 0x410C12,120,2,0,1, 0x413682,120,2,0,1, 0x41369A,120,2,0,1, 0x4136B2,120,2,0,1, 0x4136CA,120,2,0,1, 0x4136E2,120,2,0,1, 0x4136FA,120,2,0,1, 0x413712,120,2,0,1, 0x41372A,120,2,0,1, 0x413742,120,2,0,1, 0x41375A,120,2,0,1, 0x413772,120,2,0,1>;
using def_t = CColSphere *(CColSphere *);
static const int cb_priority = PRIORITY_BEFORE; 
using calling_convention_t = CallingConventions::Thiscall;
using args_t = ArgPick<ArgTypes<CColSphere *>, 0>;
META_END

META_BEGIN(CColSphere::Set)
static int address;
static int global_address;
static const int id = 0x411E40;
static const bool is_virtual = false;
static const int vtable_index = -1;
using mv_addresses_t = MvAddresses<0x411E40, 0x411E40, 0x411E40>;
// total references count: 10en (25), 11en (25), steam (25)
using refs_t = RefList<0x412192,100,0,0x412160,1, 0x412215,100,0,0x412160,2, 0x412298,100,0,0x412160,3, 0x412321,100,0,0x412160,4, 0x4123C2,100,0,0x412160,5, 0x412469,100,0,0x412160,6, 0x4125C0,100,0,0x412160,7, 0x412723,100,0,0x412160,8, 0x4128BC,100,0,0x412160,9, 0x412A1F,100,0,0x412160,10, 0x412BB8,100,0,0x412160,11, 0x412D51,100,0,0x412160,12, 0x412EEA,100,0,0x412160,13, 0x413083,100,0,0x412160,14, 0x4131CC,100,0,0x412160,15, 0x413315,100,0,0x412160,16, 0x41345E,100,0,0x412160,17, 0x478CD5,100,0,0x478C20,1, 0x510724,100,0,0x5104D0,1, 0x53BFE9,100,0,0x53BF70,1, 0x53C010,100,0,0x53BF70,2, 0x53C037,100,0,0x53BF70,3, 0x53C05E,100,0,0x53BF70,4, 0x53C092,100,0,0x53BF70,5, 0x53C0B9,100,0,0x53BF70,6, 0x412192,110,0,0x412160,1, 0x412215,110,0,0x412160,2, 0x412298,110,0,0x412160,3, 0x412321,110,0,0x412160,4, 0x4123C2,110,0,0x412160,5, 0x412469,110,0,0x412160,6, 0x4125C0,110,0,0x412160,7, 0x412723,110,0,0x412160,8, 0x4128BC,110,0,0x412160,9, 0x412A1F,110,0,0x412160,10, 0x412BB8,110,0,0x412160,11, 0x412D51,110,0,0x412160,12, 0x412EEA,110,0,0x412160,13, 0x413083,110,0,0x412160,14, 0x4131CC,110,0,0x412160,15, 0x413315,110,0,0x412160,16, 0x41345E,110,0,0x412160,17, 0x478CD5,110,0,0x478C20,1, 0x510914,110,0,0x5106C0,1, 0x53C229,110,0,0x53C1B0,1, 0x53C250,110,0,0x53C1B0,2, 0x53C277,110,0,0x53C1B0,3, 0x53C29E,110,0,0x53C1B0,4, 0x53C2D2,110,0,0x53C1B0,5, 0x53C2F9,110,0,0x53C1B0,6, 0x412192,120,0,0x412160,1, 0x412215,120,0,0x412160,2, 0x412298,120,0,0x412160,3, 0x412321,120,0,0x412160,4, 0x4123C2,120,0,0x412160,5, 0x412469,120,0,0x412160,6, 0x4125C0,120,0,0x412160,7, 0x412723,120,0,0x412160,8, 0x4128BC,120,0,0x412160,9, 0x412A1F,120,0,0x412160,10, 0x412BB8,120,0,0x412160,11, 0x412D51,120,0,0x412160,12, 0x412EEA,120,0,0x412160,13, 0x413083,120,0,0x412160,14, 0x4131CC,120,0,0x412160,15, 0x413315,120,0,0x412160,16, 0x41345E,120,0,0x412160,17, 0x478CD5,120,0,0x478C20,1, 0x5108A4,120,0,0x510650,1, 0x53C1D9,120,0,0x53C160,1, 0x53C200,120,0,0x53C160,2, 0x53C227,120,0,0x53C160,3, 0x53C24E,120,0,0x53C160,4, 0x53C282,120,0,0x53C160,5, 0x53C2A9,120,0,0x53C160,6>;
using def_t = void(CColSphere *, float, CVector &, unsigned char, unsigned char);
static const int cb_priority = PRIORITY_BEFORE; 
using calling_convention_t = CallingConventions::Thiscall;
using args_t = ArgPick<ArgTypes<CColSphere *,float,CVector &,unsigned char,unsigned char>, 0,1,2,3,4>;
META_END

}
