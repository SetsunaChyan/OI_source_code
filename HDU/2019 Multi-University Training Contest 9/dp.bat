@echo off
:again
1006_gen
1006_2 < qaq.in > 1006_my.out
std < qaq.in > std.out
fc 1006_my.out std.out
if not errorlevel 1 goto again
pause