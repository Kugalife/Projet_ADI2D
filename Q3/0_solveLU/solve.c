#include "main.h"

/* Resolution du systeme d'equations lineaires T X = RHS
Entree : Tridiag *ptM, Vec *ptRHS
Sortie : Vec *ptX
*/

void solve(Tridiag *ptM, Vec *ptRHS, Vec *ptX){
   /* Decomposition LU a la place de M */
   invM(ptM);
   int nl = ptM->nl;
   
   /* Allocation du tableau local y */
   double *y=(double*) malloc(nl*sizeof(double));
   if (y == NULL){
      printf("Allocation Error\n");
      exit(1);
      }
      
   /* Verification des dimensions */
   if (nl != ptRHS->nx*ptRHS->ny){
      printf("Error : M and RHS inconsistent dimensions\n");
      exit(1);
      }
    if (nl != ptX->nx*ptX->ny){
      printf("Error : M and X inconsistent dimensions\n");
      exit(1);
      }
           
   /* Methode de la descente */
   y[0]=ptRHS->val[0];
   for (int k=1; k<nl; k++){
       y[k]=ptRHS->val[k]-ptM->l[k]*y[k-1];
       }
                
   /* effacage des composantes de X */
   for (int k=0; k<nl; k++){
       ptX->val[k]=0.0;
       }
       
   /* Methode de la montee */
   ptX->val[nl-1]=y[nl-1]/ptM->d[nl-1];
   for (int k=nl-2; k>=0; k--){
       ptX->val[k] = (y[k]-ptM->u[k]*ptX->val[k+1])/ptM->d[k];
       }
       
   /* liberation memoire du tableau local y */
   free(y);           
}

