#include "main.h"

/* Affichage de la matrice Tridiag
Entree : Tridiag *T
Sortie : vide
*/
void printTridiag(Tridiag* T){
    int nl=T->nl;
    for (int k=0; k<nl; k++) {
        printf("row %d : %10.5lf %10.5lf %10.5lf\n", k, T->l[k], T->d[k], T->u[k]);
        }
}
   
