#include "main.h"

/* Destruction d'une matrice tridiagonale M
Entree : Tridiag *ptM
Sortie : vide
*/

void destroyM(Tridiag *ptM){
    free(ptM->l);
    free(ptM->d);
    free(ptM->u);
    free(ptM);
    }
