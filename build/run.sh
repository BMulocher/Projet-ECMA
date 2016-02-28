#!/bin/bash

# !!!ATTENTION!!! Ce script est à executer dans le même répertoire que l'executable ecma
# pour des raisons de placement relatifs des autres dossiers pour la sauvegarde des résultats

# Demande de la taille de l'instance souhaitée
read -p 'Quelle catégorie d instances voulez vous traitez ? ' taille

# Demande du solveur souhaité
read -p 'Avec quel solveur ? ' solver


# Affichage de la liste des fichiers
if [[ $taille == 5 ]]; then
	for (( i = 1; i < 11; i++ )); do
	./ecma -s $solver ../Nouvelles_instances/instances_eleves/projet_5_8_$i.dat
	done
fi

if [[ $taille == 12 ]]; then
	for (( i = 1; i < 11; i++ )); do
	./ecma -s $solver ../Nouvelles_instances/instances_eleves/projet_12_10_$i.dat
	done
fi

if [[ $taille == 15 ]]; then
	for (( i = 1; i < 11; i++ )); do
	./ecma -s $solver ../Nouvelles_instances/instances_eleves/projet_15_17_$i.dat
	done
fi

if [[ $taille == 20 ]]; then
	for (( i = 1; i < 11; i++ )); do
	./ecma -s $solver ../Nouvelles_instances/instances_eleves/projet_20_25_$i.dat
	done
fi

if [[ $taille == 25 ]]; then
	for (( i = 1; i < 11; i++ )); do
	./ecma -s $solver ../Nouvelles_instances/instances_eleves/projet_25_30_$i.dat
	done
fi