@echo off
FOR /F "tokens=1 delims=" %%A in ('bat\win32_get_java_dir.bat') do SET JAVABIN=%%A
FOR /F "tokens=1 delims=" %%A in ('"%JAVABIN%\bin\java" -version -d64') do SET VAR=%%A echo %VAR% 