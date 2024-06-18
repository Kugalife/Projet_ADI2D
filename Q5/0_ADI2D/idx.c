#include "main.h"
 
/* numerotation unique sur la grille Nx x Ny 
Entree : i, j
Sortie : i+j*Nx  // Nx est une variable globale
*/
int idx(int i, int j){
// ATTENTION aucune verification i in [0, Nx-1] et j in [0, Ny-1]
    return i+j*Nx;
    }
