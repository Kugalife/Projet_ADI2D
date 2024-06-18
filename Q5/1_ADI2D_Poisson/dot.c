#include "main.h"

/* Produit Matrice tridiagonale par un vecteur
Entree : Tridiag T, Vec X
Sortie : Vec *ptY
*/
void dot(Tridiag *ptM, Vec *ptX, Vec *ptY){
    int nl = ptM->nl;
    
    /* Verification des dimensions */
    if (nl != ptX->nx*ptX->ny){
      printf("Error : M and X inconsistent dimensions\n");
      exit(1);
      }      
    if (nl != ptY->nx*ptY->ny){
      printf("Error : M and X inconsistent dimensions\n");
      exit(1);
      } 
      
   /* effacage des composantes de Y */
   for (int k=0; k<nl; k++){
       ptY->val[k]=0.0;
       }            

   /* Y[0] = d[0]*X[0]+u[0]*X[1] */
   ptY->val[0]=ptM->d[0]*ptX->val[0]+ptM->u[0]*ptX->val[1];
   for (int k=1; k<nl-1; k++){ 
       /* Y[k] = l[k]*X[k-1]+d[k]*X[k]+u[k]*X[k+1] */
       ptY->val[k]=ptM->l[k]*ptX->val[k-1]+ptM->d[k]*ptX->val[k]+ptM->u[k]*ptX->val[k+1];
       }
   /* Y[nl-1] = l[nl-1]*X[nl-2]+d[nl-1]*X[nl-1] */
   ptY->val[nl-1]=ptM->l[nl-1]*ptX->val[nl-2]+ptM->d[nl-1]*ptX->val[nl-1];   
   }
