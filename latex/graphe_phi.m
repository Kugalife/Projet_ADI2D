clc
clear all
close all

lambda=linspace(0, 10, 1000);
omega=5;
phi = (lambda-omega)./(lambda+omega);
plot(lambda, phi, 'r');
hold on
aphi=abs(phi);
plot(lambda, aphi, 'b');
grid on
legend({'$\varphi$', '$|\varphi|$'},'Interpreter','latex');
xlabel('\lambda');
title({'$\varphi(\lambda)$'},'Interpreter','latex');

nl=64;
m=nl-1;

j=m/2;
lb1=2*m^2*(1-cos(j*pi/m));
lbM=4*m^2; 

omega=linspace(0, 50000, 10000);
psi1=(omega-lb1)./(omega+lb1);
psiM=(omega-lbM)./(omega+lbM);
figure
plot(omega, psi1, 'r-')
hold on
plot(omega, abs(psi1), 'r.-')
plot(omega, psiM, 'b-')
plot(omega, abs(psiM), 'b.-')
grid on
xlabel('\omega');