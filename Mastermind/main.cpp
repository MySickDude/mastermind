//
//  main.cpp
//  Mastermind
//
//  Created by Sacha Kozma on 05.05.15.
//  Copyright (c) 2015 Sacha KOZMA. All rights reserved.
//

#include <iostream>

using namespace std;

int main(int argc, const char * argv[])
{
    
    int combinaisonMystere [4], nombreEssai = 0, combinaisonUtilisateur[4];
    bool combinaisonTrouvee = false;
    
    cout << "Bienvenue au jeu du Mastermind !" << endl << endl;
    cout << "Génération d'une nouvelle partie ..." << endl << endl;
    
    for (int i = 0; i < 4; i++) {
        combinaisonMystere[i] = random() % 8 + 1;
    }
    
    
    do{
        nombreEssai++;
        
        cout << "Essai " << nombreEssai << "/10, entrer une combinaison (séparer les chiffres d'un espace : ";
        for (int i = 0; i < 4; i++) {
            cin >> combinaisonUtilisateur[i];
        }
        
        
        
    }while (combinaisonTrouvee == false && nombreEssai < 10);
    
    
    
    
    return 0;
}