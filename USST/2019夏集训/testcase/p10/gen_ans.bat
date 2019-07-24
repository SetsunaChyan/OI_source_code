@SETLOCAL ENABLEDELAYEDEXPANSION
@echo off

set pexe=p10

for %%i in (*.in) do (
	echo %%~ni%
	%pexe% <%%i >%%~ni%.out
)
pause