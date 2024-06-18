#include "main.h"

int main(){
    double omega=1;
    int    nl   =6;
    Tridiag *M = buildM(omega, nl);
    printf("Matrice M\n");
    printTridiag(M);
    printf("----------------------------\n");
    invM(M);
    printf("Decomposition LU de M\n");
    printTridiag(M);
    }     
