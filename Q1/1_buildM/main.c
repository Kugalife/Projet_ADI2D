#include "main.h"
     
int main(){
    double omega=1;
    int    nl   =6;
    // Construction de la matrice M tridiag de rang nl avec omega=1
    Tridiag *M = buildM(omega, nl);
    // Affichage de son contenu
    printTridiag(M);
    // Liberation memoire
    destroyM(M);
    }     
