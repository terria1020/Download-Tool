#include "header\command.h"
#include "header\Winfiledown.h"
#include "header\server.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <Windows.h>

char * con;
char * myusername = NULL;
char * currpath = NULL;
DWORD myusernamelen = BUFFSIZE + 1;

bool endder() {
	free(myusername);
	free(currpath);
	printf("program exit.\n");
	exit(0);

}
bool downFBT(void) {
	int i = 0;
	while (i < 7) {
		printf("%s download..", file[i]);
		downloadFile(server[i], file[i]);
		printf("\t\t success.\n");
		i++;
	}
	printf("\n%s download..", file[7]);
	downloadFile(server[7], file[7]);
	printf("\t\t success.\n");

	getZPackage();

	printf("\nMinGW unzipping..\n");
	extract7Z(file[0], "MinGW");

	printf("\nSublime Text 3 unzipping..\n");
	extract7Z(file[7], "Sublime3");

	rmZPackage();

	i = 0;
	con = (char*)malloc(sizeof(char) * BUFFSIZE);
	while (i < 8) {
		sprintf(con, "del %s", file[i]);
		system(con);
		i++;
	}
	free(con);
	printf("make symbolic link..");
	
	makeLnk("Sublime3\\sublime_text.exe", "Sublime3.lnk");
	printf("\t\tsuccess.\n");
	printf("\n");
}
bool downEBT(void) {
	printf("%s download..", file[8]);
	downloadFile(server[8], file[8]);
	printf("\t\t success.\n");

	printf("Everything unzipping..\n");	

	getZPackage();
	extract7Z(file[8], "Everything");
	rmZPackage();

	con = (char*)malloc(sizeof(char) * BUFFSIZE);
	sprintf(con, "del %s", file[8]);
	system(con);
	free(con);

	printf("make symbolic link..");
	makeLnk("Everything\\Everything.exe", "Everything.lnk");
	printf("\t\tsuccess.\n");

	printf("\n");
}
bool down7zip(void) {
	printf("%s download..", file[9]);
	downloadFile(server[9], file[9]);
	printf("\t\t success.\n");
	printf("\n");

	printf("7-zip unzipping..\n");	

	getZPackage();
	extract7Z(file[9], "7-zip");
	rmZPackage();

	con = (char*)malloc(sizeof(char) * BUFFSIZE);
	sprintf(con, "del %s", file[9]);
	system(con);
	free(con);

	printf("make symbolic link..");
	makeLnk("7-zip\\7-zip\\7zFM.exe", "7zGui.lnk");
	printf("\t\tsuccess.\n");

	printf("\n");

}
bool downHxd(void) {
	printf("%s download..", file[10]);
	downloadFile(server[10], file[10]);
	printf("\t\t success.\n");
	printf("\n");

	printf("HxD unzipping..\n");	

	getZPackage();
	extract7Z(file[10], "HxD_Kor");
	rmZPackage();

	con = (char*)malloc(sizeof(char) * BUFFSIZE);
	sprintf(con, "del %s", file[10]);
	system(con);
	free(con);

	printf("make symbolic link..");
	makeLnk("HxD_Kor\\HxD_KOR\\HxD.exe", "HxD.lnk");
	printf("\t\tsuccess.\n");
}
bool resel(void) {
	printf("\n[!] invalid select option. use (0~4)\n\n");
}

static void getZPackage() {
	downloadFile(server[11], file[11]);
	downloadFile(server[12], file[12]);
}

static void rmZPackage() {
	system("del 7z.exe");
	system("del 7z.dll");
}

static void makeLnk(const char * path, const char * lnkname) {
	if (myusername == NULL) {
		myusername = (char*)malloc(sizeof(char) * BUFFSIZE);
		GetUserName(myusername, &myusernamelen);
	}
	if (currpath == NULL) {
		currpath = (char*)malloc(sizeof(char) * BUFFSIZE);
		GetCurrentDirectory(BUFFSIZE + 1, currpath);
	}
	char * con = (char*)malloc(sizeof(char) * BUFFSIZE * 8);
	sprintf(con, "mklink c:\\Users\\%s\\Desktop\\%s %s\\%s", myusername, lnkname, currpath, path);
	system(con);
	free(con);
}

void extract7Z(const char * zipname, const char * foldername) {
	char * con = (char*)malloc(sizeof(char) * BUFFSIZE * 8);
	sprintf(con, "7z.exe x %s -o.\\%s", zipname, foldername);
	system(con);
	free(con);
	return;
}