//
//  main.cpp
//  Mastermind
//
//  Created by Sacha Kozma on 05.05.15.
//  Copyright (c) 2015 Sacha KOZMA. All rights reserved.
//

#include <iostream>

using namespace std;

int demanderNombre (string caption);
void genererCombinaison (int combinaisonMystere[], int nombreCases, int nombreCouleurs);
void demanderCombinaison (int combinaisonUtilisateur [], int nombreCases, int nombreEssai);
void calculScore(int combinaisonMystere [], int combinaisonUtilisateur [], int nombreCases, int score []);

int main(int argc, const char * argv[])
{
    
    cout << "Bienvenue au jeu du Mastermind !" << endl << endl;
    
    const int nombreCases = demanderNombre("Combien de cases souhaitez-vous ? ");
    const int nombreCouleurs = demanderNombre("Combien de couleurs souhaitez-vous ? ");
    
    cout << endl << "Génération d'une nouvelle partie ..." << endl << endl;
    
    int combinaisonMystere [nombreCases], nombreEssai = 0, combinaisonUtilisateur[nombreCases], score [2] = {0};
    
    genererCombinaison(combinaisonMystere, nombreCases, nombreCouleurs);
    
    do{
        nombreEssai++;
        demanderCombinaison(combinaisonUtilisateur, nombreCases, nombreEssai);
        calculScore(combinaisonMystere, combinaisonUtilisateur, nombreCases, score);
    
        
        
    }while (score[0] != nombreCases);
    
    
    
    
    return 0;
}

int demanderNombre (string caption)
{
    int nombre;
    cout << caption;
    cin >> nombre;
    return nombre;
}

void genererCombinaison (int combinaisonMystere[], int nombreCases, int nombreCouleurs)
{
    for (int i = 0; i < nombreCases; i++) {
        combinaisonMystere[i] = random() % nombreCouleurs + 1;
    }
}

void demanderCombinaison (int combinaisonUtilisateur [], int nombreCases, int nombreEssai)
{
    cout << "Essai " << nombreEssai << "/10, entrer une combinaison (séparer les chiffres d'un espace) : ";
    for (int i = 0; i < nombreCases; i++) {
        cin >> combinaisonUtilisateur[i];
    }
}

void calculScore(int combinaisonMystere [], int combinaisonUtilisateur [], int nombreCases, int score [])
{
    for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "noir" (bonne couleur au bon endroit)
        if (combinaisonUtilisateur [i] == combinaisonMystere [i]) {
            score [0] += 1;
        }
    }
    
    
    
}