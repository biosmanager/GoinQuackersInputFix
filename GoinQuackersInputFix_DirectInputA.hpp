#ifndef _GOINQUACKERSINPUTFIX_DIRECTINPUTA_HPP
#define _GOINQUACKERSINPUTFIX_DIRECTINPUTA_HPP

#include <InitGuid.h>
#define DIRECTINPUT_VERSION 0x0700
#include <dinput.h>

class GoinQuackersInputFix_DirectInputA : public IDirectInputA
{

public:

	static HRESULT Create(HINSTANCE hinst, GoinQuackersInputFix_DirectInputA** ppDI);

    /*** IUnknown methods ***/
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID * ppvObj);
    STDMETHOD_(ULONG,AddRef)(THIS);
    STDMETHOD_(ULONG,Release)(THIS);

    /*** IDirectInputA methods ***/
    STDMETHOD(CreateDevice)(THIS_ REFGUID,LPDIRECTINPUTDEVICEA *,LPUNKNOWN);
    STDMETHOD(EnumDevices)(THIS_ DWORD,LPDIENUMDEVICESCALLBACKA,LPVOID,DWORD);
    STDMETHOD(GetDeviceStatus)(THIS_ REFGUID);
    STDMETHOD(RunControlPanel)(THIS_ HWND,DWORD);
    STDMETHOD(Initialize)(THIS_ HINSTANCE,DWORD);

private:

	GoinQuackersInputFix_DirectInputA();
	~GoinQuackersInputFix_DirectInputA();

	HRESULT CreateInternal(HINSTANCE hinst);

	ULONG m_refCount;
	HMODULE m_realDInputDll;
	IDirectInputA* m_realDirectInput;

};

#endif
