@echo off

cd hlslang\MachineIndependent

SET BISON_SIMPLE=..\..\tools\bison.simple
SET SET BISON_HAIRY=..\..\tools\bison.simple

REM generate Gen_hlslang.cpp
..\..\tools\flex.exe hlslang.l

REM hlslang.tab.c hlslang.tab.h
..\..\tools\bin\bison.exe -d -t -v hlslang.y
ren hlslang.tab.c Gen_hlslang_tab.cpp
ren hlslang.tab.h hlslang_tab.h
del hlslang.output

