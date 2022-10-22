%% Para o primeiro algoritmo
A = load("result.txt");

N = A(:,1);
V = A(:,2);
Fib = A(:,3);
T = A(:,4);

N1 = N( V==1);
T1 = T( V==1);

plot(N1,T1)
semilogy(N1,T1)
axis([0 60 10^-6 10^4 ])
grid on


%% Para o segundo algoritmo
figure
N2 = N( V==2);
T2 = T( V==2);
plot(N2,T2)

%% Para o terceiro algoritmo
figure
N3 = N( V==3);
T3 = T( V==3);
plot(N3,T3)

%% Para o quarto algoritmo
figure
N4 = N( V==4);
T4 = T( V==4);
plot(N4,T4)