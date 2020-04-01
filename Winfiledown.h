#pragma once

#include <stdio.h>
#include <wininet.h>
#include <windows.h>
#include <tchar.h>

#define SIZE_BUF 1024*1024*1024


int downloadFile(const char * server, const char * filename);

