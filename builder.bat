@echo off

rem builder


set output=Dtool.exe
set compath=C:\Users\Administrator\Desktop\Sublime_MinGW-WinDevelopEnv\MinGW\bin\

set tgpath=C:\Users\Administrator\Downloads\Proj\DT\
set source=%tgpath%*.c

if exist %tgpath%bin\%output% (
	del %tgpath%bin\%output%
)

cd %compath%

%compath%gcc -o %tgpath%bin\%output% %source% -lwininet

if exist %tgpath%bin\%output% (
	cls
	echo build complete.
)