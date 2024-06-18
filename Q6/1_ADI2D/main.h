#include <stdio.h>
#include <math.h>
#include <stdlib.h>

typedef struct{
    int nl;
    double *l;
    double *d;
    double *u;
} Tridiag;

typedef struct{
    int nx, ny;
    double *val;

} Vec;


/* Variables globales definies dans le main */
extern int Nx;
extern int Ny;

/* numerotation unique sur la grille Nx x Ny 
Entree : i, j, Nx
Sortie : i+j*Nx
*/
int idx(int i, int j);

/* Construction d'une matrice sous la forme d'un vecteur de taille nx*ny
Entree : double val valeur de remplissage, 
         int nx, ny taille
Sortie : *Vec 
*/
Vec* buildVec(double val, int nx, int ny);

/* Affichage du vecteur 
Entree : Vec *V
Sortie : vide
*/
void printVec(Vec* V);

/* Destruction d'un vecteur
Entree : Vec* V
Sortie : vide
*/
void destroyVec(Vec* V);
   
/* Construction de la matrice tridiagonale M de rang nl
Entree : double omega, int nl
Sortie : Tridiag* pt
*/
Tridiag* buildM(double omega, int nl);

/* Destruction d'une matrice tridiagonale M
Entree : Tridiag *ptM
Sortie : vide
*/

void destroyM(Tridiag *ptM);

/* Affichage de la matrice Tridiag
Entree : Tridiag *T
Sortie : vide
*/
void printTridiag(Tridiag* T);

/* Construction de la decomposition LU à la place de la matrice
Entree : Tridiag *T
Sortie : vide
*/ 
void invM(Tridiag *ptM);

/* Resolution du systeme d'equations lineaires T X = RHS
Entree : Tridiag *ptM, Vec *ptRHS
Sortie : Vec *ptX
*/
void solve(Tridiag *ptM, Vec *ptRHS, Vec *ptX);

/* Produit Matrice tridiagonale par un vecteur
Entree : Tridiag T, Vec X
Sortie : Vec *ptY
*/
void dot(Tridiag *ptM, Vec *ptX, Vec *ptY);

/* Calcul de la norme infinie du residu 
Entree : Vec *ptX, *ptB
Sortie : double
*/
double residu(Vec *ptX, Vec *ptB);

/* Methode ADI2D
Entree : Vec *ptB, Vec *u, double epsilon, double omega
Sortie : Vec *u
*/

void ADI2DPoisson(Vec *ptB, Vec *u, double epsilon, double omega);
