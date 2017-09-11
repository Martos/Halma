#!/bin/sh

#Variabili
scelta=0


#Funzioni
compile(){
    gcc src/gameEngine.c main.c -lm -o Halma
    echo Soluzione compilata ...
}

update(){
    git pull
}

#Main program
echo ===================
echo Easy Compiler Tools
echo ===================
echo
echo 1. Compila soluzione
echo 2. Aggiorna sorgente
echo 0. Esci
echo

read scelta
#echo $scelta

case "$scelta" in
    1) compile
    ;;
    2) update
    ;;
    0) exit
    ;;
    *) echo "error"
    ;;
esac