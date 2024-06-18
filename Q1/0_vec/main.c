#include "main.h"
    
int main(){    
    int nx=5, ny=5;
    double val=1.0;
    // Creation dynamique d'un vecteur de taille nx x ny et remplissage
    Vec *V= buildVec(val, nx, ny);
    // Affichage de son contenu
    printVec(V);
    // Liberation memoire
    destroyVec(V);
    }     
