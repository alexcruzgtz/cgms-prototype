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

%{
    Article
    Matthew Kuure-Kinsey, Cesar C. Palerm, B. Wayne Bequette, "A dual-rate
    Kalman Filter for Continuous Glucose Monitoring", Proceedings of the
    28th IEEE 2006.

    .......................................................................
    Blood glucose estimation. Expressed in terms of its rate of change
        g[t+1] = g[t] + (dif)g[t]
    and the rate of change is modeled as a stochastic signal
        (dif)g[t+1] = (dif)g[t] + w[g,t]
    The same is done for the sensor gain.
        a[t+1] = a[k] + (dif)a[t]
        (dif)a[t+1] = (dif)a[t] + w[a,t]
    
    -----------------------------------------------------------------------
    In Kalman state notation
    
    X(t+1) = [ g(t+1)
               [dif]g(t+1)
               a(t+1)
               [dif]a(t+1) ]

    A = [1 1 0 0
         0 1 0 0
         0 0 1 1
         0 0 0 1]

    X(t) = [ g(t)
             [dif]g(t)
             a(t)
             [dif]a(t) ]

    G = [0 0
         1 0
         0 0
         0 1]
 
    w(t) = [ w[g,t]
             w[a,t] ]

    Q -> 4x4

        
        X(t+1) = AX(t) + GW(t)

    -----------------------------------------------------------------------
    Given that the model has two measured outputs , sensor and reference blood
    glucose, two different time scales are used: fast, for sensor measurements;
    and slow, for fingerstick measurements.
    
    In Kalman state notation
    
    H[fast] = [ 0.5a(t) 0 0.5g(t) 0 ]
    

        Y[s,t] = H[fast]X(t) + V[s,t]
    
    
    Y(t) = [ Y[s,t]
             Y[f,t] ]
    
    H[slow] = [ 0.5a(t) 0 0.5g(t) 0 
                1       0 0       0 ]

    V(t) = [ V[s,t]
             V[f,t] ]


        Y(t) = H[slow]X(t) + V(t)
    
    If Q<R then model has priority
    if R<Q then measurements have priority
%}
%clear all
%close all

%codegen
close all
clear all
load('Meas');
load('Datos Alex 2');

t = 1;

Yga = zeros(2,length(Meas(1,:)));

X = zeros(4,length(Meas(1,:)));
X(1,1) = 1;
X(3,1) = 1;
H = zeros(length(Meas(1,:)),4);

A = [1 1 0 0; 0 1 0 0; 0 0 1 1; 0 0 0 1];

G = [0 0; 1 0; 0 0; 0 1];

Q = 1*eye(4);
Rf = 1;
Rs = eye(2);


X_est = zeros( 4, 1 );
P_est = ones( 4, 4 );
X_est(1,1) = X(1,1);
X_est(3,1) = X(3,1);

for t=2 : length(Meas(1,:))
    Hf = [.5*X(3,t-1) 0 .5*X(1,t-1) 0];

    Hs = [.5*X(3,t-1) 0 .5*X(1,t-1) 0; 1 0 0 0];
    
    
    if Meas(2,t) == 0
    
        % Predicted state and covariance
        X_prd = A * X_est;
        P_prd = A * P_est * A' + Q;
    
        % Estimation
        S = Hf * P_prd' * Hf' + Rf;
        B = Hf * P_prd';
        K= (S\B)';

        %Z = Hf * Meas(1,t)+Rf;   
        
        % Estimated state and covariance
        X_est = X_prd + K * ( Meas(1,t) - Hf * X_prd );
        P_est = P_prd - K * Hf * P_prd;

        % Compute the estimated measurements
        Yf = Hf * X_est;
        
        X(:,t) = X_est;
        
        H(t,:) = Hf;
        
        Yga(1,t)=Yf;
    
    else
        % Predicted state and covariance
        X_prd = A * X_est;
        P_prd = A * P_est * A' + Q;
    
        % Estimation
        S = Hs * P_prd' * Hs' + Rs;
        B = Hs * P_prd';
        K= (S \ B)';

        % Estimated state and covariance
        X_est = X_prd + K * ( Meas(:,t) - Hs * X_prd );
        P_est = P_prd - K * Hs * P_prd;

        % Compute the estimated measurements
        Ys = Hs * X_est;
        
        X(:,t)=X_est;
        
        H(t,:) = Hs(1,:);
        
        Yga(:,t)=Ys;
    end
end

%title('asd');
%xlabel('Time [5min]');
%ylabel('');
figure(1)
hold on
plot(Meas(1,:),'g.');
plot(Yga(1,:),'bx');

figure(2)
for i=1:length(Meas(1,:))
    M(i) = Yga(1,i)*H(i,3);
end
hold on
plot(M(:),'g*');
plot(data(:,3),'rx');
plot(Meas(2,:),'bs');


