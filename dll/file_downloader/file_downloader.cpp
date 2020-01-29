#include <Windows.h>

#define CURL_STATICLIB
#include "../dependencies/curl/curl.h"
#include "file_downloader.h"

static size_t write_callback( void* contents, size_t size, size_t nmemb, void* userp ) {
	reinterpret_cast<std::string*>( userp )->append( reinterpret_cast<char*>( contents, size * nmemb ) );
	return size * nmemb;
}

bool n_file_downloader::download_file( std::string file ) {
	printf_s( "starting download for %s", file.c_str( ) );

	CURL* curl;

	curl = curl_easy_init( );

	printf_s( "initialized curl" );

	if ( !curl )
		return false;

	FILE* file_to_write = fopen("file.exe", "wb");

	// curl setup
	curl_easy_setopt( curl, CURLOPT_URL, "" );

	return true;
}