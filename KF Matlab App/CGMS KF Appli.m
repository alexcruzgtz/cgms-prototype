
%Kalman Filter Application

%%
%{
Theory
---------------------------------------------------------------------------
KF estimate the state x E R^n
given by   x(t)= Ax(t-1) + Gw(t-1)
A (n x m)-> relates state at t-1 with state at t
G (n x k)-> relates w(t) to the state at t
w(t)(K) -> represents the process noise

Measurement y E R^m
given by   y(t)= Hx(t) + v(t)
H (m x n)-> relates the state with the measurement
v(t)-> represents the measurement noise

---------------------------------------------------------------------------
P(w) ~ N(o,Q)
p(v) ~ N(0,R)
Q-> process noise covariance
R-> measurement noise covariance

P[t|t-1] = E[ ( x(t) - ^x(t|t-1) ) ( x(t) - x(t|t-1) )^T ]
P[t|t] = E[ ( x(t) - ^x(t|t) ) ( x(t) - x(t|t) )^T ]

Time update equations:
^x(t|t-1) =  A* ^x(t-1|t-1)
P[t|t-1] = A * P[t-1|t-1] * A^T + Q

Measurement equations:
K[t] = P[t|t-1] * H^T * (H * P[t|t-1] * H^T + R)^-1
^x(t|t) = ^x(t|t-1) + K[t] * ( y(t) - H * ^x(t|t-1) )
P[t|t] = ( I - K[t] * H )* P(t-1|t-1)

K[t] (n x m)-> Kalman gain
%}

%%

clear all
close all

%Define coefficient matrices. Based on Andrea Facchinetti Thesis
A=[2 -1 ; 1 0];
G=[1 0];
H=[1 0];

[Kest,L,P,M,Z]=Kalman()



