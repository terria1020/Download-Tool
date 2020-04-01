#include "header\Winfiledown.h"

int downloadFile(const char * server, const char * filename) {
	HINTERNET hinet, hurl;

	DWORD size, readsize;
	TCHAR *buffer;
	FILE * wfp;

	hinet = InternetOpen("HTTPS",
		INTERNET_OPEN_TYPE_DIRECT,
		NULL,
		NULL,
		0);
	if (hinet == NULL) return GetLastError();

	hurl = InternetOpenUrl(hinet,
		server,
		NULL,
		0,
		INTERNET_FLAG_KEEP_CONNECTION,
		0);

	if (hurl == NULL) {
		InternetCloseHandle(hinet);
		return GetLastError();
	}

	wfp = fopen(filename, "wb");
	if (wfp == NULL) {
		InternetCloseHandle(hurl);
		InternetCloseHandle(hinet);
		return GetLastError();
	}

	buffer = (TCHAR*)malloc(sizeof(TCHAR) * SIZE_BUF);

	do  {
		InternetQueryDataAvailable(hurl, &size, 0, 0);
		//if (size > 1024 * 1024) size = 1024 * 1024;
		InternetReadFile(hurl, buffer, size, &readsize);
		fwrite(buffer, size, 1, wfp);
	} while (size != 0);

	InternetCloseHandle(hurl);
	InternetCloseHandle(hinet);

	hurl = NULL;
	hinet = NULL;
	fclose(wfp);

	free(buffer);
	return 0;
}