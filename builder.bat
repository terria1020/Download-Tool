@echo off

rem builder


set output=Dtool.exe
set compath=C:\Users\Cyber\Downloads\MinGW\MinGW\bin\

set tgpath=C:\Users\Cyber\Downloads\Download-Tool-master\Download-Tool-master\
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