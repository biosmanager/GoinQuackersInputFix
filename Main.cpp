#include "GoinQuackersInputFix_DirectInputA.hpp"

#include "WindowsUtils.hpp"

HRESULT WINAPI DirectInputCreateA(HINSTANCE hinst, DWORD dwVersion,
	LPDIRECTINPUTA* ppDI, LPUNKNOWN punkOuter)
{
	Debug("DirectInputCreateA called\n");
	Debug("dwVersion == 0x%X\n", dwVersion);

	HRESULT hr;

	*ppDI = NULL;

	GoinQuackersInputFix_DirectInputA* result = NULL;
	hr = GoinQuackersInputFix_DirectInputA::Create(hinst, &result);
	if (SUCCEEDED(hr))
	{
		Debug("GoinQuackersInputFix DirectInput interface created. Initializing...\n");
		hr = result->Initialize(hinst, dwVersion);
		Debug("(Initialize called)\n");
		if (SUCCEEDED(hr)) {
			Debug("Initialized successfully\n");
			*ppDI = result;
		}
	}

	return hr;
}
