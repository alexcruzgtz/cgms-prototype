%{

x[k+1] = A*x[k] + B*u[k] + G*w[k]
z[k] = H*x[k] + v[k]

-----------------------------------------------------------------------------
g[k+1] = g[k] + dg[k]
dg[k+1] = dg[k] + w[g,k]

a[k+1] = a[k] + da[k]
da[k+1] = da[k] + w[a,k]

X[k+1] = g[k+1]
         dg[k+1]
         a[k+1]
         da[k+1]

A = 1 1 0 0
    0 1 0 0
    0 0 1 1
    0 0 0 1

X[k] = g[k]
       dg[k]
       a[k]
       da[k]

G = 0 0
    1 0
    0 0
    0 1

Hfast = 0.5*a[k] 0 0.5*g[k] 0

Hslow = 0.5*a[k] 0 0.5*g[k] 0
           1     0    1     0

Stochastic model
x[k+1] = A*x[k] + G*w[k]
y[g,k] = Hfast*x[k] + v[s,k]
y[k] = Hslow*x[k] + v[k]

x(-)[k] = A*x[k-1]
y(-)[1,k] = Hfast*x(-)[k]
x[k] = A*x(-)[k] + Kgfast*(y[1,k] - y(-)[1,k])

x(-)[k] = A*x[k-1]
y(-)[k] = Hslow*x(-)[k]
x[k] = A*x(-)[k] + Kgslow*(y[k] - y(-)[k])

P[k] = A*P[k-1]*A' + G*Q*G' - A*P[k-1]*Hfast'*(Hfast*P[k-1]*Hfast' + Rfast)^-1*Hfast*P[k-1]*A'
P[k] = A*P[k-1]*A' + G*Q*G' - A*P[k-1]*Hslow' * (Hslow*P[k-1]*Hslow' + Rslow)^-1*Hslow*P[k-1]*A'

Kgfast = P[k]*Hfast'*(Hfast*P[k]*Hfast' + Rfast)^-1
Kgslow = P[k]*Hslow'*(Hslow*P[k]*Hslow' + Rslow)^-1



%}


clear all
close all

load('Datos Alex 2');

k=1;

n=length(data(:,1));

%{
T = 1;                     
Fs = 1000;                  
t = [1/Fs:1/Fs:T];         
f = 5;

mu = .5;
sigma = 1;
r = chol(sigma);
noise = repmat(mu,1,Fs) + randn(1,Fs)*r;
%nonoise = 12.*ones(1,Fs);
nonoise = 5.*cos(2*pi*f*t)+12;
signal = nonoise + noise;

A = 1;
G = 1;
Q = r;
H = 1;
R = r;
P = R;

X = zeros(1,Fs);
Y = zeros(1,Fs);
X(1) = 12;
Y(1) = 12;

for k=2:Fs
    [X(1,k),Y(1,k),P] = kF_V_Bequette( X(1,k-1), signal(k), A, H, G, P, Q, R );
end

plot(X,'r.');
hold on
plot(signal,'g.');
plot(nonoise,'b-');

figure(2)
subplot(1,2,1), plot(nonoise,X,'.');
subplot(1,2,2), plot(nonoise,signal,'.');
%}

%
X = zeros(2,n);
Y = zeros(1,n);
P = ones(2);

X(1,1) = 10;
X(2,1) = 90;

A = [.92 .08; 0 1];
G = [0; 1];
H = [1 0];

Q = 5*eye(2);
R = 1;

Kg = [.52; 1.71];

m = zeros(1,n);
m(1) = 1;
for k=2:n
    if isnan(data(k,2))
        m(k) = m(k-1);
    else
        m(k) = data(k,4)/data(k,2);
    end
end
for k=2:n
    [X(:,k),Y(1,k)] = kF_V_Bequette( X(:,k-1), data(k,4)/m(k), A, H, Kg);
end
%{     
for i=1:n
    if Y(1,i)>=50
        Y(1,i)=50;
    elseif Y(1,i)<=0
        Y(1,i)=0;
    end
end
%}
figure(1)
hold on
plot(data(1:n,4),'g.');
plot(X(1,:).*m(:)','b.');
%plot(Y(1,1:n),'r.');

figure(2)
hold on
plot(data(1:n,3),'r.');
plot(data(1:n,2),'bs');
plot(X(1,:),'g.');
%plot(X(2,:),'b.');
%}
