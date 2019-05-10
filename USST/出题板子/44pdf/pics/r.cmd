@echo off

if "%~1" == "build" (
    for %%a in (*.mp) do (
        call mpost %%a
        if errorlevel 1 exit /b 1
    )
) else if "%~1" == "clean" (
    for %%a in (log mpx 1 2 3 4 5 6 7 8 9 10 11 12 13 14 15) do (
        if exist *.%%a del *.%%a
    )
) else (
    pushd ..
    call r
    popd
)
