clc
clear all

global N
N=64;
omega_lst=linspace(2000, 256*64, 100);
lambda_lst=[];

for omega=omega_lst

Mpos = M(+omega);
Mneg = M(-omega);

A= (Mpos' \ Mneg)*(Mpos \ Mneg');
disp('valeurs propres calcules avec eig');
lb=eig(A)

disp('min lambda')
min_lb = min(lb);
lambda_lst=[lambda_lst min_lb];
end

plot(omega_lst, lambda_lst, 'r');
grid on

function Mat = M(omega)
global N
m=N-1;
Mat=(2*m*m+omega)*eye(N);
Mat=Mat+diag(-m*m*ones(1, N-1), -1);
% dirichlet
Mat(1, 1)=1; Mat(1, 2)=0;
Mat(N, N)=1; Mat(N, N-1)=0;
end