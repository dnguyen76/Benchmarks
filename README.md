# Benchmarks
Benchmark ESP32 versus ATMEGA328

Rapport de puissance entre ESP32 et ATMEGA 328 : Comparaison_Calcul.ino  et Comparaison_Calcul_Nano.ino

Pour tester la puissance de ces 2 processeurs, est effectué 1000 fois le calcul de la somme des carrées des nombres entiers de 1 à 1000 (12 + 22 +32 +42 +….+.9992 +10002 ) 

Afin de vérifier l’absence d’erreur dans le code, le résultat à obtenir pour la somme des carrés est  333833500 

Ce programme en pseudo code très simple en permet le calcul.
Répéter 1000 fois
| 	N = 1
| 	Faire Tant que N  <=  1000
|    	|	Somme  Somme + N*N   
|   	|	N   N+1
|	Fin Faire Tant que
Fin Répéter

Utilisation des 2 coeurs ESP32 Comparaison_Calcul_dual_core.ino 
--------------------------------------------------------------------------------------------------------------------------
Benchmark dhrystone : Dhrystone_benchmark.ino pour carte Arduino Nano et Dhrystone_benchmark_dual_core.ino pour ESP32
