clc
clear all
close all

load convergence
semilogy(convergence(:, 1), convergence(:, 2), 'r')
grid on