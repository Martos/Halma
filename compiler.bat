@echo off

:MENU
cls
echo ===================
echo Easy Compiler Tools
echo ===================
echo.

echo 1. Compila soluzione
echo 2. Aggiorna sorgente
echo 0. Esci
echo.

SET /P M= "> " : 

IF %M%==1 GOTO COMPILE
IF %M%==2 GOTO UPDATE
IF %M%==0 GOTO EOF
GOTO ERROR_INPUT

:COMPILE
gcc .\src\gameEngine.c .\main.c -o HalmaWin
echo Soluzione compilata ...
pause
GOTO MENU

:UPDATE
git pull
pause
GOTO MENU

:ERROR_INPUT
echo Input errato ...
pause
GOTO MENU

:EOF
exit