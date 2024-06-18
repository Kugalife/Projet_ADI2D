#include "main.h"
  
int main(){
    double omega=1;
    int    nl   =6;
    // Construction dynamique de la matrice M
    Tridiag *ptM = buildM(omega, nl);
    // Affichage
    printf("Matrice M\n");
    printTridiag(ptM);
    printf("----------------------------\n");
    
    /* Construction d'un vecteur de 1 de dimension nl*/
    Vec *ptRHS = buildVec(1.0, nl, 1);
    
    /* Construction du vecteur solution de dimension nl*/
    Vec *ptX = buildVec(0.0, nl, 1);
    
    /* Resolution du systeme lineaire avec la methode LU */
    solve(ptM, ptRHS, ptX);
    
    printf("Solution \n");
    printVec(ptX);
    
    /* ATTENTION M a été remplacée par sa décomposition LU */
    /* => reconstruire M */
    // Liberation memoire
    destroyM(ptM);
    
    // Construction de la matrice M
    ptM = buildM(omega, nl);
    
    /* Contruction d'un vecteur Y pour contenir M*X */
    Vec *ptY = buildVec(0.0, nl, 1);
    dot(ptM, ptX, ptY);
    
    printf("M X \n");
    printVec(ptY);
    
    /* Estimation de |RHS-M*X| */
    double norminf=0;
    for (int k=0; k<nl; k++){
        double delta = fabs(ptRHS->val[k]-ptY->val[k]);
        if (delta> norminf) 
           norminf = delta;
        }
    printf("Norme infinie de RHS-M X : %lf\n", norminf);
    
    /* liberation memoire faite par l'OS */
    }     
