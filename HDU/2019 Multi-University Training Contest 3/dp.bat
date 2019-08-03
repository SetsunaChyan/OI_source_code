@echo off
:again
1007_gen
1007 < data.in > 1007_my.out
1007_jxc < data.in > 1007_jxc.out
fc 1007_my.out 1007_jxc.out
if not errorlevel 1 goto again
pause