%{
Stochastic model
x[k+1] = A*x[k] + B*u[k] + G*w[k]
y[k] = H*x[k] + v[k]

x(-)[k] = A*x[k-1] + B*u[k]
x[k] = x(-)[k] + Kg*(y[k] - H*x(-)[k])

Xa[k] = x[k]
        u[k]

Aa = A B
     0 1

Ga = 0
     1

Ha = 1 0

Xa[k+1] = Aa*Xa[k] + Ga*w[k]
Y[k] = Ha*Xa[k] +v[k]

%} 

function [X,Y] = kF_V_Bequette(x,y,A,H,Kg)

    x_ =  A*x;
    
    y_ = H*x_;
    
    X = x_ + Kg*( y - y_ );
   
    Y = H*X;
    
return