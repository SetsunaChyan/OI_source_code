@echo off

set makepdf=true
set twopass=true
set clean=true

pushd %~dp0

pushd pics
call r build || exit /b 1
popd

latex problems.tex || exit /b 1
if "%twopass%" == "true" (
    pdflatex problems.tex || exit /b 1
)
dvips problems.dvi || exit /b 1
if "%makepdf%" == "true" (
    dvipdfmx -p a4 problems.dvi || exit /b 1
)
if "%clean%" == "true" (
    del problems.dvi
    del problems.log
    del problems.aux
)
popd

exit /b

:clean
for %%a in (aux dvi pdf log ps) do (
    if exist *.%%a del *.%%a
    rmdir /q /s _deploy > nul
)

pushd pics
call r clean
popd

exit /b