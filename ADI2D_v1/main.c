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
    
    // Nx et Nx variables entieres globales 
    printf("Nx (entier)  = "); scanf("%d",  &Nx);
    printf("Ny (entier)  = "); scanf("%d",  &Ny);

    double omega, epsilon;
    printf("omega   (reel)  = "); scanf("%lf",  &omega);
    printf("epsilon (reel)  = "); scanf("%lf",  &epsilon);
        
    Vec *u      = buildVec(0.0, Nx, Ny);         
    Vec *ptB    = buildVec(0.0, Nx, Ny);
    
    /* Initialisation du vecteur B */
    init_b(ptB);
    
    /* Appel du solveur ADI2D */
    ADI2DPoisson(ptB, u, epsilon, omega);

    /* sauvegarde de la distribution u */
    save("out", u);  
    
    Vec *uREF= buildVec(0.0, Nx, Ny);
    init_uREF(uREF);
    save("ref", uREF); 
    //printf("iter %d  residu %g \n", iter, residu(uREF, ptB));
    }     
