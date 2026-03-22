@echo off
setlocal enabledelayedexpansion

:: ── Banner ───────────────────────────────────────────────────────────────────
echo   .:#@@@@+.  _____ ____ _____ __  __
echo  :%%@@@@@@%%: ^| ____/ ___^|  ___^|  \/  ^|
echo  *@@@@@@@@* ^|  _^|^| ^|   ^| ^|_  ^| ^|\/^| ^|
echo  :%%@@@@@@%%: ^| ^|__^| ^|___^|  _^| ^| ^|  ^| ^|
echo   '-#@@@@-' ^|_____\____^|_^|   ^|_^|  ^|_^|
echo    Autograder -- Programacion 1 F12
echo.

:: ── Argumentos ───────────────────────────────────────────────────────────────
if "%~2"=="" (
    echo Uso:  autograder.bat ^<nombre_tarea^> ^<archivo.cpp^>
    echo.
    echo Ejemplo:
    echo   autograder.bat contar_hasta_10  solucion.cpp
    echo   autograder.bat ordenamiento     solucion.cpp
    exit /b 1
)

set TAREA=%~1
set ARCHIVO=%~2

:: Verificar extension
if /i not "%ARCHIVO:~-4%"==".cpp" (
    echo   [FAIL] Solo se aceptan archivos .cpp
    exit /b 1
)

set BINARIO=%TEMP%\programa_ecfm.exe
set SALIDA_TMP=%TEMP%\salida_ecfm.txt
set TOTAL=0
set PASADOS=0

echo ════════════════════════════════════════════════════════
echo  Tarea  : %TAREA%
echo  Archivo: %ARCHIVO%
echo ════════════════════════════════════════════════════════

:: ── Compilar ─────────────────────────────────────────────────────────────────
g++ -std=c++17 -O2 -Wall -o "%BINARIO%" "%ARCHIVO%" 2>"%TEMP%\ecfm_compile_err.txt"
if errorlevel 1 (
    echo   [FAIL] Error de compilacion:
    type "%TEMP%\ecfm_compile_err.txt"
    exit /b 1
)
echo   [INFO] Compilacion exitosa

:: ── Correr casos de prueba ────────────────────────────────────────────────────
set TEST_DIR=%~dp0tests\%TAREA%

if not exist "%TEST_DIR%" (
    echo   [FAIL] No se encontro la carpeta de tests: %TEST_DIR%
    exit /b 1
)

for %%F in ("%TEST_DIR%\*.in") do (
    set /a TOTAL+=1
    set CASO=%%~nF
    set EXPECTED=%%~dpnF.out

    if exist "!EXPECTED!" (
        "%BINARIO%" < "%%F" > "%SALIDA_TMP%" 2>nul

        fc /w "%SALIDA_TMP%" "!EXPECTED!" >nul 2>&1
        if not errorlevel 1 (
            echo   [PASS] !CASO!
            set /a PASADOS+=1
        ) else (
            echo   [FAIL] !CASO!
            echo     Esperado:
            for /f "usebackq tokens=*" %%L in ("!EXPECTED!") do echo       %%L
            echo     Obtenido:
            for /f "usebackq tokens=*" %%L in ("%SALIDA_TMP%") do echo       %%L
        )
    ) else (
        echo   [INFO] Sin .out para !CASO! - omitido
    )
)

echo.
echo  Resultado: %PASADOS% / %TOTAL% casos pasados
echo ════════════════════════════════════════════════════════

endlocal
