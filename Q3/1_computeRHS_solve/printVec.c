#include "main.h"

/* Affichage du vecteur 
Entree : Vec *V
Sortie : vide
*/
void printVec(Vec* V){
     int nx = V->nx;
     int ny = V->ny;
     for (int i=0; i<nx; i++)
         for (int j=0; j<ny; j++)
             printf("row %d col %d : %10.5lf\n", i, j, V->val[i+j*nx]);
}
