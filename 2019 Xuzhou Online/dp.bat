@echo off
:again
K_gen
K_2 < qaq.in > K_bf.out
K < qaq.in > K.out
fc K_bf.out K.out
if not errorlevel 1 goto again
pause