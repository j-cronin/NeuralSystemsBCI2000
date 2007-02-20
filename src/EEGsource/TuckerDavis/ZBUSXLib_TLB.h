/* (C) 2000-2007, BCI2000 Project
/* http://www.bci2000.org
/*/
// ************************************************************************ //
// WARNING                                                                    
// -------                                                                    
// The types declared in this file were generated from data read from a       
// Type Library. If this type library is explicitly or indirectly (via        
// another type library referring to this type library) re-imported, or the   
// 'Refresh' command of the Type Library Editor activated while editing the   
// Type Library, the contents of this file will be regenerated and all        
// manual modifications will be lost.                                         
// ************************************************************************ //

// C++ TLBWRTR : $Revision$
// File generated on 7/8/2005 9:11:44 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\TDT\ActiveX\zBUSx.ocx (1)
// LIBID: {10055D3E-3938-4652-B6A2-6A6A4184D18D}
// LCID: 0
// Helpfile: c:\TDT\ActiveX\zBUSx.hlp
// HelpString: zBUSx ActiveX Control module
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\system32\stdole2.tlb)
// ************************************************************************ //
#ifndef   ZBUSXLib_TLBH
#define   ZBUSXLib_TLBH

#pragma option push -b -w-inl

#include <utilcls.h>
#if !defined(__UTILCLS_H_VERSION) || (__UTILCLS_H_VERSION < 0x0600)
//
// The code generated by the TLIBIMP utility or the Import|TypeLibrary 
// and Import|ActiveX feature of C++Builder rely on specific versions of
// the header file UTILCLS.H found in the INCLUDE\VCL directory. If an 
// older version of the file is detected, you probably need an update/patch.
//
#error "This file requires a newer version of the header UTILCLS.H" \
       "You need to apply an update/patch to your copy of C++Builder"
#endif
#include <olectl.h>
#include <ocidl.h>
#if defined(USING_ATLVCL) || defined(USING_ATL)
#if !defined(__TLB_NO_EVENT_WRAPPERS)
#include <atl/atlmod.h>
#endif
#endif


// *********************************************************************//
// Forward reference of some VCL types (to avoid including STDVCL.HPP)    
// *********************************************************************//
namespace Stdvcl {class IStrings; class IStringsDisp;}
using namespace Stdvcl;
typedef TComInterface<IStrings> IStringsPtr;
typedef TComInterface<IStringsDisp> IStringsDispPtr;

namespace Zbusxlib_tlb
{

// *********************************************************************//
// HelpString: zBUSx ActiveX Control module
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:        
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLSID_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
extern "C" const __declspec(selectany) GUID LIBID_ZBUSXLib = {0x10055D3E, 0x3938, 0x4652,{ 0xB6, 0xA2, 0x6A,0x6A, 0x41, 0x84,0xD1, 0x8D} };
extern "C" const __declspec(selectany) GUID DIID__DZBUSx = {0x9F05A891, 0xD2B9, 0x41AF,{ 0x8C, 0x8E, 0x3F,0x42, 0x45, 0x26,0x14, 0x83} };
extern "C" const __declspec(selectany) GUID DIID__DZBUSxEvents = {0x575833D5, 0x0B5E, 0x4759,{ 0xB3, 0x70, 0x40,0xFA, 0x23, 0xD4,0x09, 0xE5} };
extern "C" const __declspec(selectany) GUID CLSID_ZBUSx = {0x79734A6C, 0x8E6E, 0x4998,{ 0xB8, 0x34, 0x3E,0x4E, 0x48, 0x12,0x32, 0xB0} };

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                    
// *********************************************************************//
interface DECLSPEC_UUID("{9F05A891-D2B9-41AF-8C8E-3F4245261483}") _DZBUSx;
typedef TComInterface<_DZBUSx, &DIID__DZBUSx> _DZBUSxPtr;

interface DECLSPEC_UUID("{575833D5-0B5E-4759-B370-40FA23D409E5}") _DZBUSxEvents;
typedef TComInterface<_DZBUSxEvents, &DIID__DZBUSxEvents> _DZBUSxEventsPtr;


// *********************************************************************//
// Declaration of CoClasses defined in Type Library                       
// (NOTE: Here we map each CoClass to its Default Interface)              
//                                                                        
// The LIBID_OF_ macro(s) map a LIBID_OF_CoClassName to the GUID of this  
// TypeLibrary. It simplifies the updating of macros when CoClass name    
// change.                                                                
// *********************************************************************//
typedef _DZBUSx ZBUSx;
typedef _DZBUSxPtr ZBUSxPtr;

#define LIBID_OF_ZBUSx (&LIBID_ZBUSXLib)
// *********************************************************************//
// Interface: _DZBUSx
// Flags:     (4112) Hidden Dispatchable
// GUID:      {9F05A891-D2B9-41AF-8C8E-3F4245261483}
// *********************************************************************//
interface _DZBUSx : public TDispWrapper<IDispatch>
{
  long __fastcall Connect(long Interface)
  {
    _TDispID _dispid(/* Connect */ DISPID(1));
    TAutoArgs<1> _args;
    _args[1] = Interface /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetDeviceAddr(long DevType, long DevNum)
  {
    _TDispID _dispid(/* GetDeviceAddr */ DISPID(2));
    TAutoArgs<2> _args;
    _args[1] = DevType /*[VT_I4:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetDeviceVersion(long DevType, long DevNum)
  {
    _TDispID _dispid(/* GetDeviceVersion */ DISPID(3));
    TAutoArgs<2> _args;
    _args[1] = DevType /*[VT_I4:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall HardwareReset(long RackNum)
  {
    _TDispID _dispid(/* HardwareReset */ DISPID(4));
    TAutoArgs<1> _args;
    _args[1] = RackNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall FlushIO(long RackNum)
  {
    _TDispID _dispid(/* FlushIO */ DISPID(5));
    TAutoArgs<1> _args;
    _args[1] = RackNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall zBusTrigA(long RackNum, long zTrgMode, long Delay)
  {
    _TDispID _dispid(/* zBusTrigA */ DISPID(6));
    TAutoArgs<3> _args;
    _args[1] = RackNum /*[VT_I4:0]*/;
    _args[2] = zTrgMode /*[VT_I4:0]*/;
    _args[3] = Delay /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall zBusTrigB(long RackNum, long zTrgMode, long Delay)
  {
    _TDispID _dispid(/* zBusTrigB */ DISPID(7));
    TAutoArgs<3> _args;
    _args[1] = RackNum /*[VT_I4:0]*/;
    _args[2] = zTrgMode /*[VT_I4:0]*/;
    _args[3] = Delay /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall zBusSync(long RackMask)
  {
    _TDispID _dispid(/* zBusSync */ DISPID(8));
    TAutoArgs<1> _args;
    _args[1] = RackMask /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall KillCode(long DevType, long DevNum, long MagicCode)
  {
    _TDispID _dispid(/* KillCode */ DISPID(9));
    TAutoArgs<3> _args;
    _args[1] = DevType /*[VT_I4:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    _args[3] = MagicCode /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  BSTR __fastcall GetError()
  {
    _TDispID _dispid(/* GetError */ DISPID(10));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  BSTR __fastcall GetDeviceAt(long RackNum, long PosNum, long* DevID, long* DevNum)
  {
    _TDispID _dispid(/* GetDeviceAt */ DISPID(11));
    TAutoArgs<4> _args;
    _args[1] = RackNum /*[VT_I4:0]*/;
    _args[2] = PosNum /*[VT_I4:0]*/;
    _args[3] = DevID /*[VT_I4:1]*/;
    _args[4] = DevNum /*[VT_I4:1]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectZBUS(BSTR IntName)
  {
    _TDispID _dispid(/* ConnectZBUS */ DISPID(12));
    TAutoArgs<1> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  void __fastcall AboutBox()
  {
    _TDispID _dispid(/* AboutBox */ DISPID(-552));
    OleProcedure(_dispid);
  }


};
// *********************************************************************//
// Interface: _DZBUSxEvents
// Flags:     (4096) Dispatchable
// GUID:      {575833D5-0B5E-4759-B370-40FA23D409E5}
// *********************************************************************//
interface _DZBUSxEvents : public TDispWrapper<IDispatch>
{

};
#if !defined(__TLB_NO_INTERFACE_WRAPPERS)
// *********************************************************************//
// DispIntf:  _DZBUSx
// Flags:     (4112) Hidden Dispatchable
// GUID:      {9F05A891-D2B9-41AF-8C8E-3F4245261483}
// *********************************************************************//
template<class T>
class _DZBUSxDispT : public TAutoDriver<_DZBUSx>
{
public:
  _DZBUSxDispT(){}

  _DZBUSxDispT(_DZBUSx *pintf)
  {
    TAutoDriver<_DZBUSx>::Bind(pintf, false);
  }

  _DZBUSxDispT(_DZBUSxPtr pintf)
  {
    TAutoDriver<_DZBUSx>::Bind(pintf, true);
  }

  _DZBUSxDispT& operator=(_DZBUSx *pintf)
  {
    TAutoDriver<_DZBUSx>::Bind(pintf, false);
    return *this;
  }

  _DZBUSxDispT& operator=(_DZBUSxPtr pintf)
  {
    TAutoDriver<_DZBUSx>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_ZBUSx));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_ZBUSx);
  }

  long            __fastcall Connect(long Interface);
  long            __fastcall GetDeviceAddr(long DevType, long DevNum);
  long            __fastcall GetDeviceVersion(long DevType, long DevNum);
  long            __fastcall HardwareReset(long RackNum);
  long            __fastcall FlushIO(long RackNum);
  long            __fastcall zBusTrigA(long RackNum, long zTrgMode, long Delay);
  long            __fastcall zBusTrigB(long RackNum, long zTrgMode, long Delay);
  long            __fastcall zBusSync(long RackMask);
  long            __fastcall KillCode(long DevType, long DevNum, long MagicCode);
  BSTR            __fastcall GetError();
  BSTR            __fastcall GetDeviceAt(long RackNum, long PosNum, long* DevID, long* DevNum);
  long            __fastcall ConnectZBUS(BSTR IntName);
  void            __fastcall AboutBox();

};
typedef _DZBUSxDispT<_DZBUSx> _DZBUSxDisp;

// *********************************************************************//
// DispIntf:  _DZBUSxEvents
// Flags:     (4096) Dispatchable
// GUID:      {575833D5-0B5E-4759-B370-40FA23D409E5}
// *********************************************************************//
template <class T>
class _DZBUSxEventsDispT : public TAutoDriver<_DZBUSxEvents>
{
public:
  _DZBUSxEventsDispT(){}

  void Attach(LPUNKNOWN punk)
  { m_Dispatch = static_cast<T*>(punk); }


};
typedef _DZBUSxEventsDispT<_DZBUSxEvents> _DZBUSxEventsDisp;

// *********************************************************************//
// DispIntf:  _DZBUSx
// Flags:     (4112) Hidden Dispatchable
// GUID:      {9F05A891-D2B9-41AF-8C8E-3F4245261483}
// *********************************************************************//
template <class T> long __fastcall
_DZBUSxDispT<T>::Connect(long Interface)
{
  _TDispID _dispid(*this, OLETEXT("Connect"), DISPID(1));
  TAutoArgs<1> _args;
  _args[1] = Interface /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::GetDeviceAddr(long DevType, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("GetDeviceAddr"), DISPID(2));
  TAutoArgs<2> _args;
  _args[1] = DevType /*[VT_I4:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::GetDeviceVersion(long DevType, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("GetDeviceVersion"), DISPID(3));
  TAutoArgs<2> _args;
  _args[1] = DevType /*[VT_I4:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::HardwareReset(long RackNum)
{
  _TDispID _dispid(*this, OLETEXT("HardwareReset"), DISPID(4));
  TAutoArgs<1> _args;
  _args[1] = RackNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::FlushIO(long RackNum)
{
  _TDispID _dispid(*this, OLETEXT("FlushIO"), DISPID(5));
  TAutoArgs<1> _args;
  _args[1] = RackNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::zBusTrigA(long RackNum, long zTrgMode, long Delay)
{
  _TDispID _dispid(*this, OLETEXT("zBusTrigA"), DISPID(6));
  TAutoArgs<3> _args;
  _args[1] = RackNum /*[VT_I4:0]*/;
  _args[2] = zTrgMode /*[VT_I4:0]*/;
  _args[3] = Delay /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::zBusTrigB(long RackNum, long zTrgMode, long Delay)
{
  _TDispID _dispid(*this, OLETEXT("zBusTrigB"), DISPID(7));
  TAutoArgs<3> _args;
  _args[1] = RackNum /*[VT_I4:0]*/;
  _args[2] = zTrgMode /*[VT_I4:0]*/;
  _args[3] = Delay /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::zBusSync(long RackMask)
{
  _TDispID _dispid(*this, OLETEXT("zBusSync"), DISPID(8));
  TAutoArgs<1> _args;
  _args[1] = RackMask /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::KillCode(long DevType, long DevNum, long MagicCode)
{
  _TDispID _dispid(*this, OLETEXT("KillCode"), DISPID(9));
  TAutoArgs<3> _args;
  _args[1] = DevType /*[VT_I4:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  _args[3] = MagicCode /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> BSTR __fastcall
_DZBUSxDispT<T>::GetError()
{
  _TDispID _dispid(*this, OLETEXT("GetError"), DISPID(10));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> BSTR __fastcall
_DZBUSxDispT<T>::GetDeviceAt(long RackNum, long PosNum, long* DevID, long* DevNum)
{
  _TDispID _dispid(*this, OLETEXT("GetDeviceAt"), DISPID(11));
  TAutoArgs<4> _args;
  _args[1] = RackNum /*[VT_I4:0]*/;
  _args[2] = PosNum /*[VT_I4:0]*/;
  _args[3] = DevID /*[VT_I4:1]*/;
  _args[4] = DevNum /*[VT_I4:1]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DZBUSxDispT<T>::ConnectZBUS(BSTR IntName)
{
  _TDispID _dispid(*this, OLETEXT("ConnectZBUS"), DISPID(12));
  TAutoArgs<1> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> void __fastcall
_DZBUSxDispT<T>::AboutBox()
{
  _TDispID _dispid(*this, OLETEXT("AboutBox"), DISPID(-552));
  OleProcedure(_dispid);
}

// *********************************************************************//
// DispIntf:  _DZBUSxEvents
// Flags:     (4096) Dispatchable
// GUID:      {575833D5-0B5E-4759-B370-40FA23D409E5}
// *********************************************************************//
#endif  //   __TLB_NO_INTERFACE_WRAPPERS


#if !defined(__TLB_NO_EVENT_WRAPPERS) && defined(USING_ATLVCL)
// *********************************************************************//
// CONNECTIONPOINT/EVENT PROXY
// CoClass         : ZBUSx
// Event Interface : _DZBUSxEvents
// *********************************************************************//
template <class T>
class TEvents_ZBUSx : public IConnectionPointImpl<T,
                                                 &DIID__DZBUSxEvents,
                                                 CComUnkArray<CONNECTIONPOINT_ARRAY_SIZE> >
 /* Note: if encountering problems with events, please change CComUnkArray to CComDynamicUnkArray in the line above. */
{
public:
protected:
  _DZBUSxEventsDisp m_EventIntfObj;
};

#endif  //   __TLB_NO_EVENT_WRAPPERS

};     // namespace Zbusxlib_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Zbusxlib_tlb;
#endif

#pragma option pop

#endif // ZBUSXLib_TLBH


