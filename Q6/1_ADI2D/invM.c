#include "main.h"

/* Construction de la decomposition LU à la place de la matrice
Entree : Tridiag *T
Sortie : vide
*/ 
void invM(Tridiag *ptM){
   int nl=ptM->nl;
   for (int k=1; k<nl; k++){
       ptM->l[k] =ptM->l[k]/ptM->d[k-1];
       ptM->d[k] =ptM->d[k]-ptM->u[k-1]*ptM->l[k];
       }
}
