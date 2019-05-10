@SETLOCAL ENABLEDELAYEDEXPANSION
@echo off

set pexe=G_std

for %%i in (*.in) do (
	echo %%~ni%
	%pexe% <%%i >%%~ni%.out
)
pause