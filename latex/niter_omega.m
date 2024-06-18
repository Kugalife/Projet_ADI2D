clc
clear all
close all

load("niter64x64");
omega=niter64x64(:, 1);
iter =niter64x64(:, 2);

%400 premiers points
omega=omega(1:400);
iter =iter (1:400);
plot(omega, iter, 'r-');
grid on
xlabel('\omega');
ylabel('nb iterations');
