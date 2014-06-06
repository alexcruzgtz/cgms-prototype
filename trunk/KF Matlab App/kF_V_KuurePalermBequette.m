%{
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

function [X,Y,P] = kF_V_KuurePalermBequette(x,y,A,H,G,P,Q,R)

    x_ =  A*x;
    
    P1 = A*P*H';
    P2 = (H*P*H' + R)^-1;
    P3 = H*P*A';
    P_ = A*P*A' + G*Q*G' - P1*P2*P3;
    
    %P_ = A*P*A' + Q;
    
    Kg1 = (H*P_*H' + R)^-1;
    Kg = P_*H'*Kg1;
        
    y_ = H*x_;
    
    X = A*x_ + Kg*( y - y_ );
   
    %P = P_ - Kg*H*P_;
    
    Y = H*X;
    
return


  
