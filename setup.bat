@echo off
echo Configurando el entorno de desarrollo para el Compilador Valorant...

REM Verificar si ya está instalado MinGW
where gcc >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo GCC no encontrado. Por favor, instale MinGW y agregue bin al PATH
    echo Visite: https://www.mingw-w64.org/downloads/
    exit /b 1
)

REM Verificar si ya está instalado Flex
where flex >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Flex no encontrado. Por favor, instale Flex para Windows
    echo Visite: https://gnuwin32.sourceforge.net/packages/flex.htm
    exit /b 1
)

REM Verificar si ya está instalado Bison
where bison >nul 2>nul
if %ERRORLEVEL% neq 0 (
    echo Bison no encontrado. Por favor, instale Bison para Windows
    echo Visite: https://gnuwin32.sourceforge.net/packages/bison.htm
    exit /b 1
)

REM Crear directorios si no existen
if not exist build mkdir build
if not exist bin mkdir bin

REM Compilar el proyecto
echo Compilando el proyecto...
mingw32-make clean
mingw32-make

if %ERRORLEVEL% equ 0 (
    echo.
    echo Compilación exitosa!
    echo El compilador se encuentra en bin/valorant.exe
    echo.
    echo Para probar el compilador, ejecute:
    echo bin\valorant.exe examples\test.val
) else (
    echo.
    echo Error durante la compilación
    exit /b 1
)

exit /b 0 