#include "main.h"
 
/* variables globales */
int Nx; // nombre de noeuds selon x
int Ny; // nombre de noeuds selon y
 
void init_b(Vec *f){
   int Nx=f->nx;
   int Ny=f->ny;
   double dx=1./(Nx-1);
   double dy=1./(Ny-1);
   for (int i=0; i<Nx; i++){
       double x=i*dx;
       for (int j=0; j<Ny; j++){
           double y=j*dy;
           int n=idx(i, j);
           f->val[n]=2.0*x*(1.0-x)+2.0*y*(1.0-y);
           }//endfor
       }//endfor
   }
   
void init_uREF(Vec *u){
   int Nx=u->nx;
   int Ny=u->ny;
   double dx=1./(Nx-1);
   double dy=1./(Ny-1);
   for (int i=0; i<Nx; i++){
       double x=i*dx;
       for (int j=0; j<Ny; j++){
           double y=j*dy;
           int n=idx(i, j);
           u->val[n]=x*(1.0-x)*y*(1.0-y);
           }//endfor
       }//endfor
   }
   
double norminf(Vec *u, Vec*f){
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
            res += mx_sq*u->val[left]-2.0*mx_sq*u->val[center]+mx_sq*u->val[right];
            res += my_sq*u->val[down]-2.0*my_sq*u->val[center]+my_sq*u->val[up];
            res += f->val[center];
            if (fabs(res)>norm) {
               norm=fabs(res);
               }
            }
        }
    return norm;
}
  
double norminf_debug(Vec *u, Vec*f){
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
            res += mx_sq*u->val[left]-2.0*mx_sq*u->val[center]+mx_sq*u->val[right];
            res += my_sq*u->val[down]-2.0*my_sq*u->val[center]+my_sq*u->val[up];
            printf("%d %d lap=%g  f=%g\n", i, j, res, f->val[center]);
            res += f->val[center];
            if (fabs(res)>norm) {
               norm=fabs(res);
               }
            }
        }
    return norm;
}
 
void save(char* filename, Vec *u) {
   double dx=1./(Nx-1);
   double dy=1./(Ny-1);
   FILE *fp=fopen(filename, "w");
   if (!fp) exit(1);
   for (int i=0; i<Nx; i++){
       for (int j=0; j<Ny; j++){
           int n=idx(i,j);
           fprintf(fp, "%lf %lf %g\n", i*dx, j*dy, u->val[n]);
           }
       fprintf(fp, "\n");
       }
   fclose(fp);
}
                              
int main(){
    
    Nx=8;
    Ny=8;
    double tolerance=1e-6;
    double omega = 1024;

    
    Vec *u      = buildVec(0.0, Nx, Ny);        
    Vec *u_star = buildVec(0.0, Nx, Ny);    
    Vec *ptB    = buildVec(0.0, Nx, Ny);
    init_b(ptB);
    
    int iter=0;
    for(;;){   
    
    // premier pas fractionnaire selon Ox
        for (int j=1; j<Ny-1; j++){
            Tridiag *ptM     = buildM(omega, Nx);
            Vec *ptRHS = buildVec(0.0, Nx, 1);
            
 /*         compute RHSX */ 
            computeRHSX(j, omega, u, ptB, ptRHS);
                                   
            Vec *ptX = buildVec(0.0, Nx, 1);
            solve(ptM, ptRHS, ptX);
                         
            for (int i=0; i<Nx; i++){
                int n = idx(i,j);
                u_star->val[n] = ptX->val[i];
                }//endfor i   
            destroyVec(ptX);
            destroyVec(ptRHS);
            destroyM(ptM); 
            }//endfor j
 
  
    // second pas fractionnaire selon Oy      
        for (int i=1; i<Nx-1; i++){
            Tridiag *ptM = buildM(omega, Ny);
            Vec *ptRHS = buildVec(0.0, 1, Ny);
            
 /*         compute RHSY */ 
            computeRHSY(i, omega, u_star, ptB, ptRHS);
                     
            Vec *ptX = buildVec(0.0, 1, Ny);
            solve(ptM, ptRHS, ptX);
              
            for (int j=0; j<Ny; j++){
                int n = idx(i,j);
                u->val[n] = ptX->val[j];
                }//endfor j   
            destroyVec(ptX);
            destroyVec(ptRHS);
            destroyM(ptM); 
            }//endfor i
        
        iter++;    
        printf("iter %d  residu %g \n", iter, norminf(u, ptB));
        if (norminf(u, ptB)<tolerance) break;
            
    } //endfor ever
    
    printf("iter %d  residu %g \n", iter, norminf(u, ptB));
    save("out", u);  
    
    Vec *uREF= buildVec(0.0, Nx, Ny);
    init_uREF(uREF);
    save("ref", uREF); 
    //printf("iter %d  residu %g \n", iter, norminf(uREF, ptB));
    }     
