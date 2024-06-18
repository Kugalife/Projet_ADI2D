#include "main.h"

/* residu = norminf(b-M*x)
Entree : Tridiag *ptM, Vec*ptRHS, Vec *ptX
Sortie : res
*/
double residu(Tridiag *ptM, Vec*ptRHS, Vec *ptX){
    int nl = ptM->nl;
    
    /* Verification des dimensions */
    if (nl != ptX->nx*ptX->ny){
      printf("Error : M and X inconsistent dimensions\n");
      exit(1);
      }      
    if (nl != ptRHS->nx*ptRHS->ny){
      printf("Error : M and RHS inconsistent dimensions\n");
      exit(1);
      } 
   
   Vec *ptY = buildVec(0.0, nl, 1);
   dot(ptM, ptX, ptY);
   
       
   double norminf=0;
   for (int k=0; k<nl; k++){
       double delta=fabs(ptRHS->val[k]-ptY->val[k]);
       if (delta>norminf) norminf=delta;
       }            

   destroyVec(ptY);
   return norminf; 
   }
