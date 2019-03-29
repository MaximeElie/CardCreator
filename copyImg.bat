@echo off

del ..\build-CardCreator-Desktop_Qt_5_12_2_MinGW_32_bit-Release\release\img\* /Q
copy img\*.png ..\build-CardCreator-Desktop_Qt_5_12_2_MinGW_32_bit-Release\release\img\

echo.
pause