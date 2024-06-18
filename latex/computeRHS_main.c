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
 