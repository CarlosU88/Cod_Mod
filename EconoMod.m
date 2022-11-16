
  t=10;
  A=[0.10 0.06 0.05 0.70;
		 0.48 0.44 0.10 0.04;
		 0.00 0.55 0.52 0.04;
		 0.04 0.01 0.42 0.51];
  Xo=[0.6,0.9,1.3,0.5];
  Xt=Xo';
  Xr=A*(Xo)';
  Xp=Xt;
  for k=1:1:t-1
    Xt=A*Xt;
    Xp=[Xp,Xt]; %X
    Xr=[Xr,A*Xt]; %Y
  endfor
  Aid1=Xr/Xp
 display(["||(X^+)X-Y||_F = ",num2str( norm(Aid1*Xp-Xr,"fro"))]);
 display(["||(X^+)-A||_F = ",num2str( norm(Aid1-A,"fro"))]);
  X0 = X1 = Xo';
  for k = 1:300
	  X0 = [X0 A*X0(:,k)];
	  X1 = [X1 Aid1*X1(:,k)];
  end
  
  axis("tight");
  
  subplot(211);
  plot(X0.');
  title('Órbitas del modelo original')

  subplot(212);
  plot(X1.');
  title('Órbitas del modelo identificado')
  