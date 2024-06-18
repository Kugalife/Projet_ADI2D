#include "main.h"

/* Construction de la decomposition LU a la place de la matrice
Entree : Tridiag *ptM
Sortie : vide
*/ 
void invM(Tridiag *ptM){
   int nl=ptM->nl;
   // l[0] (non pertinent) , d[0] et u[0] sont conserves
   for (int k=1; k<nl; k++){
       // l[k] = l[k]/d[k-1]
       ptM->l[k] =ptM->l[k]/ptM->d[k-1];
       // d[k] = d[k]-u[k-1]*l[k]
       ptM->d[k] =ptM->d[k]-ptM->u[k-1]*ptM->l[k];
       }
}
