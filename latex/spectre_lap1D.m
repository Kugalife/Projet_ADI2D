clc
nl=4;
m=nl-1;

nLap=(2*m*m)*eye(nl);
nLap=nLap+diag(-m*m*ones(1, nl-1), -1);
nLap=nLap+diag(-m*m*ones(1, nl-1), +1);
nLap(1,1)=1; nLap(1,2)=0;
nLap(nl, nl-1)=0; nLap(nl, nl)=1;
nLap

D = eig(nLap)
lst=[];
for j=1:m-1
    lb=2*m^2*(1-cos(j*pi/m));
    lst=[lst lb];
end
lst

