@echo off
:again
1002_gen
1002 < 1002test.in > 1002_my.out
1002_brute < 1002test.in > 1002_std.out
fc 1002_std.out 1002_my.out
if not errorlevel 1 goto again
pause