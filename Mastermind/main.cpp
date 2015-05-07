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
void afficherCombinaison(int combinaisonMystere[], int nombreCases);

int main(int argc, const char * argv[])
{
    cout << "Bienvenue au jeu du Mastermind !" << endl << endl;
    bool nouvellePartie;
    string reponseNouveauJeu;
    do {
        nouvellePartie = false;
        
        srandomdev(); // Remet à zéro le hasard
        
        
        const int nombreCases = demanderNombre("Combien de cases souhaitez-vous ? ");
        const int nombreCouleurs = demanderNombre("Combien de couleurs souhaitez-vous ? ");
        
        cout << endl << "Génération d'une nouvelle partie ..." << endl << endl;
        
        int combinaisonMystere [nombreCases], nombreEssai = 0, combinaisonUtilisateur[nombreCases], score [2] = {0};
        
        genererCombinaison(combinaisonMystere, nombreCases, nombreCouleurs);
        afficherCombinaison(combinaisonMystere, nombreCases);
        
        do{
            nombreEssai++;
            demanderCombinaison(combinaisonUtilisateur, nombreCases, nombreEssai);
            calculScore(combinaisonMystere, combinaisonUtilisateur, nombreCases, score);
            if (score[0] == nombreCases) {
                cout << endl << endl << "Bravo ! Vous avez trouvé la combinaison ! La combinaison était :";
                afficherCombinaison(combinaisonMystere, nombreCases);
                cout << endl;
            }
            else {
                cout << "Vous avez " << score[0] << " bon(s) nombre(s) au bon(s) endroit(s) et " << score[1] << " bon(s) nombre(s) mal placé(s)." << endl << endl;
                
            }
            
        } while (score[0] != nombreCases);
        
        cout << "Voulez-vous rejouer (oui/non) ? ";
        cin >> reponseNouveauJeu;
        if (reponseNouveauJeu == "oui") {
            nouvellePartie = true;
        }
        else {
            nouvellePartie = false;
        }
        
    } while (nouvellePartie == true);
    
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
    cout << "Essai n°" << nombreEssai << ", entrer une combinaison (séparer les chiffres d'un espace) : ";
    for (int i = 0; i < nombreCases; i++) {
        cin >> combinaisonUtilisateur[i];
    }
}

void calculScore(int combinaisonMystere [], int combinaisonUtilisateur [], int nombreCases, int score [])
{
    bool combinaisonMystereMarque [nombreCases], combinaisonUtilisateurMarque [nombreCases];
    
    
    fill(score, score + 2, 0); // Remet à zéro les scores
    
    for (int i = 0; i < nombreCases; i++) { //Remise à zéro des marques sur les combinaisons
        combinaisonMystereMarque[i] = false;
        combinaisonUtilisateurMarque[i] = false;
    }
    
    for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "noir" (bonne couleur au bon endroit)
        if (combinaisonUtilisateur [i] == combinaisonMystere [i]) {
            score [0] += 1; // score[0] représente les noirs
            combinaisonMystereMarque[i] = true;
            combinaisonUtilisateurMarque[i] = true;
        }
    }
    
    for (int i = 0; i < nombreCases; i++) { // Calcul du nombre de "blanc" (bonne couleur pas au même endroit)
        if (combinaisonMystereMarque[i] == false) {
            for (int j = 0; j < nombreCases; j++) {
                if (combinaisonUtilisateur[j] == combinaisonMystere[i] && combinaisonUtilisateurMarque[j] == false) {
                    score[1] += 1; // représente les blancs
                    combinaisonMystereMarque[i] = true;
                    combinaisonUtilisateurMarque[j] = true;
                    break;
                }
            }
        }
        
    }
    
}

void afficherCombinaison(int combinaisonMystere[], int nombreCases)
{
    for (int i = 0; i < nombreCases; i++) {
        cout << " | " << combinaisonMystere[i] << " | ";
    }
    
    cout << endl << endl;
}