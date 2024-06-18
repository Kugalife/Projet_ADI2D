syms omega lb
assume(omega, 'real');
assume(lb, 'real');

v= ((lb-omega)/(lb+omega))^2
diff(v, omega)