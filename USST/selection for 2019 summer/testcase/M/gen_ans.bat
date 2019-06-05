@SETLOCAL ENABLEDELAYEDEXPANSION
@echo off

set pexe=M_std

for %%i in (*.in) do (
	echo %%~ni%
	%pexe% <%%i >%%~ni%.out
)
pause