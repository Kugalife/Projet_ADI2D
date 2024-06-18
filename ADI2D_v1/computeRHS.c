#include "main.h"

/* calcul du second membre selon X 
Entree : int j, double omega, Vec *ptX, Vec *ptB
Sortie : Vec *ptRHS
*/
void computeRHSX(int j, double omega, Vec *ptX, Vec *ptB, Vec *ptRHS){
    double my=Ny-1.0;
    double my_sq=my*my;    
    for (int i=1; i<Nx-1; i++){
        int down   = idx(i, j-1);
        int center = idx(i, j);
        int up     = idx(i, j+1);
        ptRHS->val[i] = my_sq*ptX->val[down]-(2.0*my_sq-omega)*ptX->val[center]+my_sq*ptX->val[up];
        ptRHS->val[i]+= ptB->val[center];
        }//endfor i  
 }
  
/* calcul du second membre selon Y
Entree : int i, double omega, Vec *ptX, Vec *ptB
Sortie : Vec *ptRHS
*/
void computeRHSY(int i, double omega, Vec *ptX, Vec *ptB, Vec *ptRHS){
    double mx=Nx-1.0;
    double mx_sq=mx*mx;                  
    for (int j=1; j<Ny-1; j++){
        int left   = idx(i-1, j);
        int center = idx(i,   j);
        int right  = idx(i+1, j);
        ptRHS->val[j] = mx_sq*ptX->val[left]-(2.0*mx_sq-omega)*ptX->val[center]+mx_sq*ptX->val[right];
        ptRHS->val[j]+= ptB->val[center];
        }//endfor j 
 }
