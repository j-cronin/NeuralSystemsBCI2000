/* (C) 2000-2008, BCI2000 Project
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
// File generated on 3/18/2005 11:28:44 AM from Type Library described below.

// ************************************************************************  //
// Type Lib: c:\TDT\ActiveX\RPcoX.ocx (1)
// LIBID: {D323A622-1D13-11D4-8858-444553540000}
// LCID: 0
// Helpfile: c:\TDT\ActiveX\RPcoX.hlp
// HelpString: RPcoX ActiveX Control module
// DepndLst: 
//   (1) v2.0 stdole, (C:\WINDOWS\System32\stdole2.tlb)
// ************************************************************************ //
#ifndef   RPCOXLib_TLBH
#define   RPCOXLib_TLBH

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

namespace Rpcoxlib_tlb
{

// *********************************************************************//
// HelpString: RPcoX ActiveX Control module
// Version:    1.0
// *********************************************************************//


// *********************************************************************//
// GUIDS declared in the TypeLibrary. Following prefixes are used:        
//   Type Libraries     : LIBID_xxxx                                      
//   CoClasses          : CLSID_xxxx                                      
//   DISPInterfaces     : DIID_xxxx                                       
//   Non-DISP interfaces: IID_xxxx                                        
// *********************************************************************//
extern __declspec (package) const GUID LIBID_RPCOXLib;
extern __declspec (package) const GUID DIID__DRPcoX;
extern __declspec (package) const GUID DIID__DRPcoXEvents;
extern __declspec (package) const GUID CLSID_RPcoX;

// *********************************************************************//
// Forward declaration of types defined in TypeLibrary                    
// *********************************************************************//
interface DECLSPEC_UUID("{D323A623-1D13-11D4-8858-444553540000}") _DRPcoX;
typedef TComInterface<_DRPcoX, &DIID__DRPcoX> _DRPcoXPtr;

interface DECLSPEC_UUID("{D323A624-1D13-11D4-8858-444553540000}") _DRPcoXEvents;
typedef TComInterface<_DRPcoXEvents, &DIID__DRPcoXEvents> _DRPcoXEventsPtr;


// *********************************************************************//
// Declaration of CoClasses defined in Type Library                       
// (NOTE: Here we map each CoClass to its Default Interface)              
//                                                                        
// The LIBID_OF_ macro(s) map a LIBID_OF_CoClassName to the GUID of this  
// TypeLibrary. It simplifies the updating of macros when CoClass name    
// change.                                                                
// *********************************************************************//
typedef _DRPcoX RPcoX;
typedef _DRPcoXPtr RPcoXPtr;

#define LIBID_OF_RPcoX (&LIBID_RPCOXLib)
// *********************************************************************//
// Interface: _DRPcoX
// Flags:     (4112) Hidden Dispatchable
// GUID:      {D323A623-1D13-11D4-8858-444553540000}
// *********************************************************************//
interface _DRPcoX : public TDispWrapper<IDispatch>
{
  BSTR __fastcall GetError()
  {
    _TDispID _dispid(/* GetError */ DISPID(1));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall Connect(long Interface, long DevNum)
  {
    _TDispID _dispid(/* Connect */ DISPID(2));
    TAutoArgs<2> _args;
    _args[1] = Interface /*[VT_I4:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall SetTagVal(BSTR Name, float Val)
  {
    _TDispID _dispid(/* SetTagVal */ DISPID(3));
    TAutoArgs<2> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = Val /*[VT_R4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall LoadCOF(BSTR FileName)
  {
    _TDispID _dispid(/* LoadCOF */ DISPID(4));
    TAutoArgs<1> _args;
    _args[1] = FileName /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall Run()
  {
    _TDispID _dispid(/* Run */ DISPID(5));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall Halt()
  {
    _TDispID _dispid(/* Halt */ DISPID(6));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall SoftTrg(long Trg_Bitn)
  {
    _TDispID _dispid(/* SoftTrg */ DISPID(7));
    TAutoArgs<1> _args;
    _args[1] = Trg_Bitn /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  float __fastcall GetTagVal(BSTR Name)
  {
    _TDispID _dispid(/* GetTagVal */ DISPID(8));
    TAutoArgs<1> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ReadTag(BSTR Name, float* pBuf, long nOS, long nWords)
  {
    _TDispID _dispid(/* ReadTag */ DISPID(9));
    TAutoArgs<4> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = pBuf /*[VT_R4:1]*/;
    _args[3] = nOS /*[VT_I4:0]*/;
    _args[4] = nWords /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall WriteTag(BSTR Name, float* pBuf, long nOS, long nWords)
  {
    _TDispID _dispid(/* WriteTag */ DISPID(10));
    TAutoArgs<4> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = pBuf /*[VT_R4:1]*/;
    _args[3] = nOS /*[VT_I4:0]*/;
    _args[4] = nWords /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall SendParTable(BSTR Name, float IndexID)
  {
    _TDispID _dispid(/* SendParTable */ DISPID(11));
    TAutoArgs<2> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = IndexID /*[VT_R4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall SendSrcFile(BSTR Name, long SeekOS, long nWords)
  {
    _TDispID _dispid(/* SendSrcFile */ DISPID(12));
    TAutoArgs<3> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = SeekOS /*[VT_I4:0]*/;
    _args[3] = nWords /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetNames(BSTR NameList, long MaxNames, long ObjType)
  {
    _TDispID _dispid(/* GetNames */ DISPID(13));
    TAutoArgs<3> _args;
    _args[1] = NameList /*[VT_BSTR:0]*/;
    _args[2] = MaxNames /*[VT_I4:0]*/;
    _args[3] = ObjType /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  VARIANT __fastcall ReadTagV(BSTR Name, long nOS, long nWords)
  {
    _TDispID _dispid(/* ReadTagV */ DISPID(14));
    TAutoArgs<3> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = nOS /*[VT_I4:0]*/;
    _args[3] = nWords /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall WriteTagV(BSTR Name, long nOS, VARIANT Buf)
  {
    _TDispID _dispid(/* WriteTagV */ DISPID(15));
    TAutoArgs<3> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = nOS /*[VT_I4:0]*/;
    _args[3] = Buf /*[VT_VARIANT:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetTagSize(BSTR Name)
  {
    _TDispID _dispid(/* GetTagSize */ DISPID(16));
    TAutoArgs<1> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetTagType(BSTR Name)
  {
    _TDispID _dispid(/* GetTagType */ DISPID(17));
    TAutoArgs<1> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall SetSrcFileName(BSTR Name, BSTR FileName)
  {
    _TDispID _dispid(/* SetSrcFileName */ DISPID(18));
    TAutoArgs<2> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = FileName /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetNumOf(BSTR ObjTypeName)
  {
    _TDispID _dispid(/* GetNumOf */ DISPID(19));
    TAutoArgs<1> _args;
    _args[1] = ObjTypeName /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  BSTR __fastcall GetNameOf(BSTR ObjTypeName, long Index)
  {
    _TDispID _dispid(/* GetNameOf */ DISPID(20));
    TAutoArgs<2> _args;
    _args[1] = ObjTypeName /*[VT_BSTR:0]*/;
    _args[2] = Index /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ReadCOF(BSTR FileName)
  {
    _TDispID _dispid(/* ReadCOF */ DISPID(21));
    TAutoArgs<1> _args;
    _args[1] = FileName /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRP2(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRP2 */ DISPID(22));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRL2(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRL2 */ DISPID(23));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRA16(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRA16 */ DISPID(24));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  VARIANT __fastcall ReadTagVEX(BSTR Name, long nOS, long nWords, BSTR SrcType, BSTR DstType, 
                                long nChans)
  {
    _TDispID _dispid(/* ReadTagVEX */ DISPID(25));
    TAutoArgs<6> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = nOS /*[VT_I4:0]*/;
    _args[3] = nWords /*[VT_I4:0]*/;
    _args[4] = SrcType /*[VT_BSTR:0]*/;
    _args[5] = DstType /*[VT_BSTR:0]*/;
    _args[6] = nChans /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetStatus()
  {
    _TDispID _dispid(/* GetStatus */ DISPID(26));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetCycUse()
  {
    _TDispID _dispid(/* GetCycUse */ DISPID(27));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ClearCOF()
  {
    _TDispID _dispid(/* ClearCOF */ DISPID(28));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall WriteTagVEX(BSTR Name, long nOS, BSTR DstType, VARIANT Buf)
  {
    _TDispID _dispid(/* WriteTagVEX */ DISPID(29));
    TAutoArgs<4> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    _args[2] = nOS /*[VT_I4:0]*/;
    _args[3] = DstType /*[VT_BSTR:0]*/;
    _args[4] = Buf /*[VT_VARIANT:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ZeroTag(BSTR Name)
  {
    _TDispID _dispid(/* ZeroTag */ DISPID(30));
    TAutoArgs<1> _args;
    _args[1] = Name /*[VT_BSTR:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  float __fastcall GetSFreq()
  {
    _TDispID _dispid(/* GetSFreq */ DISPID(31));
    TAutoArgs<0> _args;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRV8(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRV8 */ DISPID(32));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall GetDevCfg(long Addr, long Width32)
  {
    _TDispID _dispid(/* GetDevCfg */ DISPID(33));
    TAutoArgs<2> _args;
    _args[1] = Addr /*[VT_I4:0]*/;
    _args[2] = Width32 /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall SetDevCfg(long Addr, long Val, long Width32)
  {
    _TDispID _dispid(/* SetDevCfg */ DISPID(34));
    TAutoArgs<3> _args;
    _args[1] = Addr /*[VT_I4:0]*/;
    _args[2] = Val /*[VT_I4:0]*/;
    _args[3] = Width32 /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall LoadCOFsf(BSTR FileName, float SampFreq)
  {
    _TDispID _dispid(/* LoadCOFsf */ DISPID(35));
    TAutoArgs<2> _args;
    _args[1] = FileName /*[VT_BSTR:0]*/;
    _args[2] = SampFreq /*[VT_R4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall DefStatus(long DefID)
  {
    _TDispID _dispid(/* DefStatus */ DISPID(36));
    TAutoArgs<1> _args;
    _args[1] = DefID /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  VARIANT __fastcall GetDefData(long DefID)
  {
    _TDispID _dispid(/* GetDefData */ DISPID(37));
    TAutoArgs<1> _args;
    _args[1] = DefID /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  void __fastcall AboutBox()
  {
    _TDispID _dispid(/* AboutBox */ DISPID(-552));
    OleProcedure(_dispid);
  }

  long __fastcall ConnectRM1(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRM1 */ DISPID(38));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRM2(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRM2 */ DISPID(39));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRX5(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRX5 */ DISPID(40));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRX6(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRX6 */ DISPID(41));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }

  long __fastcall ConnectRX7(BSTR IntName, long DevNum)
  {
    _TDispID _dispid(/* ConnectRX7 */ DISPID(42));
    TAutoArgs<2> _args;
    _args[1] = IntName /*[VT_BSTR:0]*/;
    _args[2] = DevNum /*[VT_I4:0]*/;
    OleFunction(_dispid, _args);
    return _args.GetRetVariant();
  }


};
// *********************************************************************//
// Interface: _DRPcoXEvents
// Flags:     (4096) Dispatchable
// GUID:      {D323A624-1D13-11D4-8858-444553540000}
// *********************************************************************//
interface _DRPcoXEvents : public TDispWrapper<IDispatch>
{
  void __fastcall DefComplete(long DefID)
  {
    _TDispID _dispid(/* DefComplete */ DISPID(1));
    TAutoArgs<1> _args;
    _args[1] = DefID /*[VT_I4:0]*/;
    OleProcedure(_dispid, _args);
  }


};
#if !defined(__TLB_NO_INTERFACE_WRAPPERS)
// *********************************************************************//
// DispIntf:  _DRPcoX
// Flags:     (4112) Hidden Dispatchable
// GUID:      {D323A623-1D13-11D4-8858-444553540000}
// *********************************************************************//
template<class T>
class _DRPcoXDispT : public TAutoDriver<_DRPcoX>
{
public:
  _DRPcoXDispT(){}

  _DRPcoXDispT(_DRPcoX *pintf)
  {
    TAutoDriver<_DRPcoX>::Bind(pintf, false);
  }

  _DRPcoXDispT(_DRPcoXPtr pintf)
  {
    TAutoDriver<_DRPcoX>::Bind(pintf, true);
  }

  _DRPcoXDispT& operator=(_DRPcoX *pintf)
  {
    TAutoDriver<_DRPcoX>::Bind(pintf, false);
    return *this;
  }

  _DRPcoXDispT& operator=(_DRPcoXPtr pintf)
  {
    TAutoDriver<_DRPcoX>::Bind(pintf, true);
    return *this;
  }

  HRESULT BindDefault()
  {
    return OLECHECK(Bind(CLSID_RPcoX));
  }

  HRESULT BindRunning()
  {
    return BindToActive(CLSID_RPcoX);
  }

  BSTR            __fastcall GetError();
  long            __fastcall Connect(long Interface, long DevNum);
  long            __fastcall SetTagVal(BSTR Name, float Val);
  long            __fastcall LoadCOF(BSTR FileName);
  long            __fastcall Run();
  long            __fastcall Halt();
  long            __fastcall SoftTrg(long Trg_Bitn);
  float           __fastcall GetTagVal(BSTR Name);
  long            __fastcall ReadTag(BSTR Name, float* pBuf, long nOS, long nWords);
  long            __fastcall WriteTag(BSTR Name, float* pBuf, long nOS, long nWords);
  long            __fastcall SendParTable(BSTR Name, float IndexID);
  long            __fastcall SendSrcFile(BSTR Name, long SeekOS, long nWords);
  long            __fastcall GetNames(BSTR NameList, long MaxNames, long ObjType);
  VARIANT         __fastcall ReadTagV(BSTR Name, long nOS, long nWords);
  long            __fastcall WriteTagV(BSTR Name, long nOS, VARIANT Buf);
  long            __fastcall GetTagSize(BSTR Name);
  long            __fastcall GetTagType(BSTR Name);
  long            __fastcall SetSrcFileName(BSTR Name, BSTR FileName);
  long            __fastcall GetNumOf(BSTR ObjTypeName);
  BSTR            __fastcall GetNameOf(BSTR ObjTypeName, long Index);
  long            __fastcall ReadCOF(BSTR FileName);
  long            __fastcall ConnectRP2(BSTR IntName, long DevNum);
  long            __fastcall ConnectRL2(BSTR IntName, long DevNum);
  long            __fastcall ConnectRA16(BSTR IntName, long DevNum);
  VARIANT         __fastcall ReadTagVEX(BSTR Name, long nOS, long nWords, BSTR SrcType, BSTR DstType
                                        , long nChans);
  long            __fastcall GetStatus();
  long            __fastcall GetCycUse();
  long            __fastcall ClearCOF();
  long            __fastcall WriteTagVEX(BSTR Name, long nOS, BSTR DstType, VARIANT Buf);
  long            __fastcall ZeroTag(BSTR Name);
  float           __fastcall GetSFreq();
  long            __fastcall ConnectRV8(BSTR IntName, long DevNum);
  long            __fastcall GetDevCfg(long Addr, long Width32);
  long            __fastcall SetDevCfg(long Addr, long Val, long Width32);
  long            __fastcall LoadCOFsf(BSTR FileName, float SampFreq);
  long            __fastcall DefStatus(long DefID);
  VARIANT         __fastcall GetDefData(long DefID);
  void            __fastcall AboutBox();
  long            __fastcall ConnectRM1(BSTR IntName, long DevNum);
  long            __fastcall ConnectRM2(BSTR IntName, long DevNum);
  long            __fastcall ConnectRX5(BSTR IntName, long DevNum);
  long            __fastcall ConnectRX6(BSTR IntName, long DevNum);
  long            __fastcall ConnectRX7(BSTR IntName, long DevNum);

};
typedef _DRPcoXDispT<_DRPcoX> _DRPcoXDisp;

// *********************************************************************//
// DispIntf:  _DRPcoXEvents
// Flags:     (4096) Dispatchable
// GUID:      {D323A624-1D13-11D4-8858-444553540000}
// *********************************************************************//
template <class T>
class _DRPcoXEventsDispT : public TAutoDriver<_DRPcoXEvents>
{
public:
  _DRPcoXEventsDispT(){}

  void Attach(LPUNKNOWN punk)
  { m_Dispatch = static_cast<T*>(punk); }

  void            __fastcall DefComplete(long DefID);

};
typedef _DRPcoXEventsDispT<_DRPcoXEvents> _DRPcoXEventsDisp;

// *********************************************************************//
// DispIntf:  _DRPcoX
// Flags:     (4112) Hidden Dispatchable
// GUID:      {D323A623-1D13-11D4-8858-444553540000}
// *********************************************************************//
template <class T> BSTR __fastcall
_DRPcoXDispT<T>::GetError()
{
  _TDispID _dispid(*this, OLETEXT("GetError"), DISPID(1));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::Connect(long Interface, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("Connect"), DISPID(2));
  TAutoArgs<2> _args;
  _args[1] = Interface /*[VT_I4:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::SetTagVal(BSTR Name, float Val)
{
  _TDispID _dispid(*this, OLETEXT("SetTagVal"), DISPID(3));
  TAutoArgs<2> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = Val /*[VT_R4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::LoadCOF(BSTR FileName)
{
  _TDispID _dispid(*this, OLETEXT("LoadCOF"), DISPID(4));
  TAutoArgs<1> _args;
  _args[1] = FileName /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::Run()
{
  _TDispID _dispid(*this, OLETEXT("Run"), DISPID(5));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::Halt()
{
  _TDispID _dispid(*this, OLETEXT("Halt"), DISPID(6));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::SoftTrg(long Trg_Bitn)
{
  _TDispID _dispid(*this, OLETEXT("SoftTrg"), DISPID(7));
  TAutoArgs<1> _args;
  _args[1] = Trg_Bitn /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> float __fastcall
_DRPcoXDispT<T>::GetTagVal(BSTR Name)
{
  _TDispID _dispid(*this, OLETEXT("GetTagVal"), DISPID(8));
  TAutoArgs<1> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ReadTag(BSTR Name, float* pBuf, long nOS, long nWords)
{
  _TDispID _dispid(*this, OLETEXT("ReadTag"), DISPID(9));
  TAutoArgs<4> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = pBuf /*[VT_R4:1]*/;
  _args[3] = nOS /*[VT_I4:0]*/;
  _args[4] = nWords /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::WriteTag(BSTR Name, float* pBuf, long nOS, long nWords)
{
  _TDispID _dispid(*this, OLETEXT("WriteTag"), DISPID(10));
  TAutoArgs<4> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = pBuf /*[VT_R4:1]*/;
  _args[3] = nOS /*[VT_I4:0]*/;
  _args[4] = nWords /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::SendParTable(BSTR Name, float IndexID)
{
  _TDispID _dispid(*this, OLETEXT("SendParTable"), DISPID(11));
  TAutoArgs<2> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = IndexID /*[VT_R4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::SendSrcFile(BSTR Name, long SeekOS, long nWords)
{
  _TDispID _dispid(*this, OLETEXT("SendSrcFile"), DISPID(12));
  TAutoArgs<3> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = SeekOS /*[VT_I4:0]*/;
  _args[3] = nWords /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetNames(BSTR NameList, long MaxNames, long ObjType)
{
  _TDispID _dispid(*this, OLETEXT("GetNames"), DISPID(13));
  TAutoArgs<3> _args;
  _args[1] = NameList /*[VT_BSTR:0]*/;
  _args[2] = MaxNames /*[VT_I4:0]*/;
  _args[3] = ObjType /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> VARIANT __fastcall
_DRPcoXDispT<T>::ReadTagV(BSTR Name, long nOS, long nWords)
{
  _TDispID _dispid(*this, OLETEXT("ReadTagV"), DISPID(14));
  TAutoArgs<3> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = nOS /*[VT_I4:0]*/;
  _args[3] = nWords /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::WriteTagV(BSTR Name, long nOS, VARIANT Buf)
{
  _TDispID _dispid(*this, OLETEXT("WriteTagV"), DISPID(15));
  TAutoArgs<3> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = nOS /*[VT_I4:0]*/;
  _args[3] = Buf /*[VT_VARIANT:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetTagSize(BSTR Name)
{
  _TDispID _dispid(*this, OLETEXT("GetTagSize"), DISPID(16));
  TAutoArgs<1> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetTagType(BSTR Name)
{
  _TDispID _dispid(*this, OLETEXT("GetTagType"), DISPID(17));
  TAutoArgs<1> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::SetSrcFileName(BSTR Name, BSTR FileName)
{
  _TDispID _dispid(*this, OLETEXT("SetSrcFileName"), DISPID(18));
  TAutoArgs<2> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = FileName /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetNumOf(BSTR ObjTypeName)
{
  _TDispID _dispid(*this, OLETEXT("GetNumOf"), DISPID(19));
  TAutoArgs<1> _args;
  _args[1] = ObjTypeName /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> BSTR __fastcall
_DRPcoXDispT<T>::GetNameOf(BSTR ObjTypeName, long Index)
{
  _TDispID _dispid(*this, OLETEXT("GetNameOf"), DISPID(20));
  TAutoArgs<2> _args;
  _args[1] = ObjTypeName /*[VT_BSTR:0]*/;
  _args[2] = Index /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ReadCOF(BSTR FileName)
{
  _TDispID _dispid(*this, OLETEXT("ReadCOF"), DISPID(21));
  TAutoArgs<1> _args;
  _args[1] = FileName /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRP2(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRP2"), DISPID(22));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRL2(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRL2"), DISPID(23));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRA16(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRA16"), DISPID(24));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> VARIANT __fastcall
_DRPcoXDispT<T>::ReadTagVEX(BSTR Name, long nOS, long nWords, BSTR SrcType, BSTR DstType, 
                            long nChans)
{
  _TDispID _dispid(*this, OLETEXT("ReadTagVEX"), DISPID(25));
  TAutoArgs<6> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = nOS /*[VT_I4:0]*/;
  _args[3] = nWords /*[VT_I4:0]*/;
  _args[4] = SrcType /*[VT_BSTR:0]*/;
  _args[5] = DstType /*[VT_BSTR:0]*/;
  _args[6] = nChans /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetStatus()
{
  _TDispID _dispid(*this, OLETEXT("GetStatus"), DISPID(26));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetCycUse()
{
  _TDispID _dispid(*this, OLETEXT("GetCycUse"), DISPID(27));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ClearCOF()
{
  _TDispID _dispid(*this, OLETEXT("ClearCOF"), DISPID(28));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::WriteTagVEX(BSTR Name, long nOS, BSTR DstType, VARIANT Buf)
{
  _TDispID _dispid(*this, OLETEXT("WriteTagVEX"), DISPID(29));
  TAutoArgs<4> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  _args[2] = nOS /*[VT_I4:0]*/;
  _args[3] = DstType /*[VT_BSTR:0]*/;
  _args[4] = Buf /*[VT_VARIANT:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ZeroTag(BSTR Name)
{
  _TDispID _dispid(*this, OLETEXT("ZeroTag"), DISPID(30));
  TAutoArgs<1> _args;
  _args[1] = Name /*[VT_BSTR:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> float __fastcall
_DRPcoXDispT<T>::GetSFreq()
{
  _TDispID _dispid(*this, OLETEXT("GetSFreq"), DISPID(31));
  TAutoArgs<0> _args;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRV8(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRV8"), DISPID(32));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::GetDevCfg(long Addr, long Width32)
{
  _TDispID _dispid(*this, OLETEXT("GetDevCfg"), DISPID(33));
  TAutoArgs<2> _args;
  _args[1] = Addr /*[VT_I4:0]*/;
  _args[2] = Width32 /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::SetDevCfg(long Addr, long Val, long Width32)
{
  _TDispID _dispid(*this, OLETEXT("SetDevCfg"), DISPID(34));
  TAutoArgs<3> _args;
  _args[1] = Addr /*[VT_I4:0]*/;
  _args[2] = Val /*[VT_I4:0]*/;
  _args[3] = Width32 /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::LoadCOFsf(BSTR FileName, float SampFreq)
{
  _TDispID _dispid(*this, OLETEXT("LoadCOFsf"), DISPID(35));
  TAutoArgs<2> _args;
  _args[1] = FileName /*[VT_BSTR:0]*/;
  _args[2] = SampFreq /*[VT_R4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::DefStatus(long DefID)
{
  _TDispID _dispid(*this, OLETEXT("DefStatus"), DISPID(36));
  TAutoArgs<1> _args;
  _args[1] = DefID /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> VARIANT __fastcall
_DRPcoXDispT<T>::GetDefData(long DefID)
{
  _TDispID _dispid(*this, OLETEXT("GetDefData"), DISPID(37));
  TAutoArgs<1> _args;
  _args[1] = DefID /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> void __fastcall
_DRPcoXDispT<T>::AboutBox()
{
  _TDispID _dispid(*this, OLETEXT("AboutBox"), DISPID(-552));
  OleProcedure(_dispid);
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRM1(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRM1"), DISPID(38));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRM2(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRM2"), DISPID(39));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRX5(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRX5"), DISPID(40));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRX6(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRX6"), DISPID(41));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

template <class T> long __fastcall
_DRPcoXDispT<T>::ConnectRX7(BSTR IntName, long DevNum)
{
  _TDispID _dispid(*this, OLETEXT("ConnectRX7"), DISPID(42));
  TAutoArgs<2> _args;
  _args[1] = IntName /*[VT_BSTR:0]*/;
  _args[2] = DevNum /*[VT_I4:0]*/;
  OleFunction(_dispid, _args);
  return _args.GetRetVariant();
}

// *********************************************************************//
// DispIntf:  _DRPcoXEvents
// Flags:     (4096) Dispatchable
// GUID:      {D323A624-1D13-11D4-8858-444553540000}
// *********************************************************************//
template <class T> void __fastcall
_DRPcoXEventsDispT<T>::DefComplete(long DefID)
{
  _TDispID _dispid(/* DefComplete */ DISPID(1));
  TAutoArgs<1> _args;
  _args[1] = DefID /*[VT_I4:0]*/;
  OleProcedure(_dispid, _args);
}

#endif  //   __TLB_NO_INTERFACE_WRAPPERS


#if !defined(__TLB_NO_EVENT_WRAPPERS) && defined(USING_ATLVCL)
// *********************************************************************//
// CONNECTIONPOINT/EVENT PROXY
// CoClass         : RPcoX
// Event Interface : _DRPcoXEvents
// *********************************************************************//
template <class T>
class TEvents_RPcoX : public IConnectionPointImpl<T,
                                                 &DIID__DRPcoXEvents,
                                                 CComUnkArray<CONNECTIONPOINT_ARRAY_SIZE> >
 /* Note: if encountering problems with events, please change CComUnkArray to CComDynamicUnkArray in the line above. */
{
public:
  void            Fire_DefComplete(long DefID);
protected:
  _DRPcoXEventsDisp m_EventIntfObj;
};

template <class T> void
TEvents_RPcoX<T>::Fire_DefComplete(long DefID)
{
  T * pT = (T*)this;
  pT->Lock();
  IUnknown ** pp = m_vec.begin();
  while (pp < m_vec.end())
  {
    if (*pp != NULL)
    {
      m_EventIntfObj.Attach(*pp);
      m_EventIntfObj.DefComplete(DefID);
      m_EventIntfObj.Attach(0);
    }
    pp++;
  }
  pT->Unlock();
}

#endif  //   __TLB_NO_EVENT_WRAPPERS

};     // namespace Rpcoxlib_tlb

#if !defined(NO_IMPLICIT_NAMESPACE_USE)
using  namespace Rpcoxlib_tlb;
#endif

#pragma option pop

#endif // RPCOXLib_TLBH