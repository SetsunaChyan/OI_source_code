@SETLOCAL ENABLEDELAYEDEXPANSION
@echo off

set pexe=A_std

for %%i in (*.in) do (
	echo %%~ni%
	%pexe% <%%i >%%~ni%.out
)
pause