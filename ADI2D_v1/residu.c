#include "main.h"

double residu(Vec *ptX, Vec *ptB){
    double mx=Nx-1.0;
    double mx_sq=mx*mx;
    double my=Ny-1.0;
    double my_sq=my*my;
    
    /* boucles sur les points interieurs */
    double norm=0.0;
    for (int i=1; i<Nx-1; i++){
        for (int j=1; j<Ny-1; j++){
            int center = idx(i,   j);
            int left   = idx(i-1, j);
            int right  = idx(i+1, j);
            int down   = idx(i, j-1);
            int up     = idx(i, j+1);
            //printf("%d %d %d %d %d\n", center, left, right, down, up);
            double res = 0;
            res += mx_sq*ptX->val[left]-2.0*mx_sq*ptX->val[center]+mx_sq*ptX->val[right];
            res += my_sq*ptX->val[down]-2.0*my_sq*ptX->val[center]+my_sq*ptX->val[up];
            res += ptB->val[center];
            if (fabs(res)>norm) {
               norm=fabs(res);
               }
            }
        }
    return norm;
}
