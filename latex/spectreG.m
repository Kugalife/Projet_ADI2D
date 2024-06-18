clc
clear all

global N
N=64;
omega=160;

Mpos = M(+omega);
Mneg = M(-omega);

A= (Mpos' \ Mneg)*(Mpos \ Mneg');
disp('valeurs propres calcules avec eig');
lb=eig(A)

disp('min lambda')
min(lb)

function Mat = M(omega)
global N
m=N-1;
Mat=(2*m*m+omega)*eye(N);
Mat=Mat+diag(-m*m*ones(1, N-1), -1);
% dirichlet
Mat(1, 1)=1; Mat(1, 2)=0;
Mat(N, N)=1; Mat(N, N-1)=0;
end