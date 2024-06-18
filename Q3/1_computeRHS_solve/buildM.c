#include "main.h"

/* Construction de la matrice tridiagonale M de rang nl
Entree : double omega, int nl
Sortie : Tridiag* pt
*/
Tridiag* buildM(double omega, int nl){
    // Allocation d'une structure Tridiag
    Tridiag* pt=( Tridiag*) malloc(sizeof(Tridiag));
    
    // Affectation du nombre de lignes
    pt->nl = nl;
    
    if (pt==NULL) {
       printf("Allocation Error\n");
       exit(1);
       }
    // Allocation du tableau l 
    pt->l=(double*) malloc(nl*sizeof(double));
    if (pt==NULL) {
       printf("Allocation Error\n");
       exit(1);
       }  
    // Allocation du tableau d
    pt->d=(double*) malloc(nl*sizeof(double));
    if (pt==NULL) {
       printf("Allocation Error\n");
       exit(1);
       }  
    // Allocation du tableau u
    pt->u=(double*) malloc(nl*sizeof(double));
    if (pt==NULL) {
       printf("Allocation Error\n");
       exit(1);
       } 
       
    // Remplissage de la matrice M
    double m    = (double) nl -1.;
    double m_sq = m*m;
    
    pt->d[0]=1.0;
    pt->u[0]=0.0;
    for (int k=1; k<nl-1; k++){
        pt->l[k]= -m_sq;
        pt->d[k]=2*m_sq+omega;
        pt->u[k]= -m_sq;
        } 
    pt->l[nl-1]=0.0;
    pt->d[nl-1]=1.0;
    // annulation des composantes non pertinentes    
    pt->l[0]   =0.0;
    pt->u[nl-1]=0.0;
    return pt;
    }
 
