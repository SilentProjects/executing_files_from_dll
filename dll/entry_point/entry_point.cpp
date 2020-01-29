#include <Windows.h>
#include <iostream>

void start( ) {
	AllocConsole( );
	freopen_s( ( FILE** )stdin, "CONIN$", "r", stdin );
	freopen_s( ( FILE** )stdout, "CONOUT$", "w", stdout );

	printf_s( "DLL Injected" );
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved ) {
	if ( reason == DLL_PROCESS_ATTACH ) {
		if ( auto handle = CreateThread( 0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( start ), 0, 0, 0 ) )
			CloseHandle( handle );
	}

	return TRUE;
}