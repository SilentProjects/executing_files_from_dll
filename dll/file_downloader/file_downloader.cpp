#include "file_downloader.h"

bool n_file_downloader::download_file( std::string file ) {
	auto result = URLDownloadToFile( NULL, _T( file.c_str( ) ), _T( "file.exe" ), 0, NULL );
	return ( result == S_OK );
}