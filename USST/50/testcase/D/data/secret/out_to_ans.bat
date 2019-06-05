@SETLOCAL ENABLEDELAYEDEXPANSION
@echo off

set pexe=C_std

for %%i in (*.out) do (
	echo %%~ni%
	copy %%i %%~ni%.ans
)

for %%i in (*.out) do (
	del %%i
)
pause