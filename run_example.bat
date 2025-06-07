@echo off
if "%1"=="" (
    echo Uso: %0 nombre_ejemplo
    echo.
    echo Ejemplos disponibles:
    dir /b examples\*.val
    exit /b 1
)

if not exist "%1" (
    echo Error: El archivo %1 no existe
    echo.
    echo Ejemplos disponibles:
    dir /b examples\*.val
    exit /b 1
)

echo Compilando y ejecutando %1...
echo.

bin\valorant.exe < %1
if %ERRORLEVEL% neq 0 (
    echo.
    echo Error al ejecutar el ejemplo
    exit /b 1
)

exit /b 0 