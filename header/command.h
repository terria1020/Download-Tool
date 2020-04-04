#pragma once
#include <stdbool.h>

char * command;
char * arg;

void extract7Z(const char * zipname, const char * foldername);

static void getZPackage();
static void rmZPackage();
static void makeLnk(const char * path, const char * lnkname);

typedef bool(*CMD) (void);

bool endder();
bool downFBT(void);
bool downEBT(void);
bool down7zip(void);
bool downHxd(void);
bool resel(void);