#include "main.h"

/* Construction d'une matrice sous la forme d'un vecteur de taille nx*ny
Entree : double val valeur de remplissage, 
         int nx, ny taille
Sortie : *Vec 
*/
Vec* buildVec(double val, int nx, int ny){
    // Allocation du vecteur pt
    Vec* pt = (Vec*) malloc(sizeof(Vec));
    if (pt==NULL) {
    printf("Allocation Error\n");
    exit(1);
    }
    // Affectation des dimensions  
    pt->nx=nx;
    pt->ny=ny;      
 
    pt->val=(double*) malloc(nx*ny*sizeof(double));
    if (pt->val==NULL) {
       printf("Allocation Error\n");
       exit(1);
       }
    for (int i=0; i<nx; i++)
        for (int j=0; j<ny; j++)
            pt->val[i+j*nx]=val;  
    return pt;
    }
