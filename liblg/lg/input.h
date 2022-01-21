/**********************
 * LGS Input
 */

#ifndef _LG_INPUT_H
#define _LG_INPUT_H

#if _MSC_VER > 1000
#pragma once
#endif

#include <lg/objstd.h>
#include <lg/iiddef.h>


extern "C" {
extern  const GUID  IID_IInputDevice;
}

extern "C" {
extern  const GUID  IID_IInputBinder;
}

struct _ui_event
{
};

struct _intrnl_var_channel
{
};

struct _Region
{
};

struct _IB_var
{
};

struct _sBindContext
{
};

struct sInputDeviceInfo
{
};

struct sJoyState
{
};

typedef unsigned char (__cdecl *InputHandlerFunc)(_ui_event*,_Region*,void*);
typedef int (__cdecl *InputBindFilter)(char*,char*,void*);
typedef void (__cdecl *InputPostBind)(int);
typedef int (__cdecl *MasterAggregationFunc)(_intrnl_var_channel**,long,char*);
typedef char* (__cdecl *MasterProcessCallbackFunc)(char*,char*,int);

interface  IInputBinder : IUnknown
{
	STDMETHOD_(char*,Init)(_IB_var*,char*) PURE;
	STDMETHOD_(char*,Term)(void) PURE;
	STDMETHOD_(void,GetHandler)(InputHandlerFunc*) PURE;
	STDMETHOD_(void,SetValidEvents)(unsigned long) PURE;
	STDMETHOD_(unsigned long,GetValidEvents)(void) PURE;
	STDMETHOD_(int,Bind)(char*,char*) PURE;
	STDMETHOD_(int,Unbind)(char*) PURE;
	STDMETHOD_(void,QueryBind)(char*,char*,long) PURE;
	STDMETHOD_(void,GetVarValue)(char*,char*,long) PURE;
	STDMETHOD_(char*,ProcessCmd)(char*) PURE;
	STDMETHOD_(void,TrapBind)(char*,InputBindFilter,InputPostBind,void*) PURE;
	STDMETHOD_(char*,Update)(void) PURE;
	STDMETHOD_(void,PollAllKeys)(void) PURE;
	STDMETHOD_(void,RegisterJoyProcObj)(void*) PURE;
	STDMETHOD_(void,LoadBndContexted)(char*) PURE;
	STDMETHOD_(void,ContextAssociate)(_sBindContext*) PURE;
	STDMETHOD_(char*,LoadBndFile)(char*,unsigned long,char*) PURE;
	STDMETHOD_(char*,SaveBndFile)(char*,char*) PURE;
	STDMETHOD_(int,VarSet)(_IB_var*) PURE;
	STDMETHOD_(int,VarSetn)(_IB_var*,long) PURE;
	STDMETHOD_(char*,VarUnset)(char**,int) PURE;
	STDMETHOD_(char*,VarUnsetn)(char**,long,int) PURE;
	STDMETHOD_(char*,VarUnsetAll)(void) PURE;
	STDMETHOD_(int,SetContext)(unsigned long,int) PURE;
	STDMETHOD_(void,GetContext)(unsigned long*) PURE;
	STDMETHOD_(void,SetMasterAggregation)(MasterAggregationFunc) PURE;
	STDMETHOD_(void,SetMasterProcessCallback)(MasterProcessCallbackFunc) PURE;
	STDMETHOD_(char*,GetControlFromCmdStart)(char*,char*) PURE;
	STDMETHOD_(char*,GetControlFromCmdNext)(char*) PURE;
	STDMETHOD_(void,SetResPath)(char*) PURE;
	STDMETHOD_(char*,DecomposeControl)(char*,char*[32],long*) PURE;
	STDMETHOD_(void,Reset)(void) PURE;
};
DEFINE_IIDSTRUCT(IInputBinder,IID_IInputBinder)

interface IJoystick : IUnknown
{
	STDMETHOD_(long,GetInfo)(sInputDeviceInfo*) PURE;
	STDMETHOD_(long,GetState)(sJoyState*) PURE;
	STDMETHOD_(long,SetAxisRange)(int,long,long) PURE;
	STDMETHOD_(long,GetAxisRange)(int,long*,long*) PURE;
	STDMETHOD_(long,SetAxisDeadZone)(int,unsigned long) PURE;
	STDMETHOD_(long,SetCooperativeLevel)(int,int) PURE;
};

#endif // _LG_INPUT_H
