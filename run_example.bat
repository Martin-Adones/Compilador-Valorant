@echo off
if "%1"=="" (
    echo Uso: %0 nombre_ejemplo
    echo.
    echo Ejemplos disponibles:
    dir /b examples\*.val
    exit /b 1
)

if not exist "examples\%1.val" (
    echo Error: El archivo examples\%1.val no existe
    echo.
    echo Ejemplos disponibles:
    dir /b examples\*.val
    exit /b 1
)

echo Compilando y ejecutando %1.val...
echo.

bin\valorant.exe < examples\%1.val
if %ERRORLEVEL% neq 0 (
    echo.
    echo Error al ejecutar el ejemplo
    exit /b 1
)

exit /b 0 