  A=[0.10 0.06 0.05 0.70;
		 0.48 0.44 0.10 0.04;
		 0.00 0.55 0.52 0.04;
		 0.04 0.01 0.42 0.51];
  Xo=[0.6,0.9,1.3,0.5];
  N=15;
 Y=X=Xp=Xr=Xo';
for k=1:N
	X = [X A*X(:,k)];
end
Y = X(:,2:(N+1));
X = X(:,1:N);
[V,D,U] = svd(X,'econ') ;
Ai=(Y*U*pinv(D)*V');
X0 = X1 = Xo';
  for k = 1:300
	  X0 = [X0 A*X0(:,k)];
	  X1 = [X1 Ai*X1(:,k)];
  end
  subplot(211);
  plot(X0.');
  title('Órbitas del modelo original')
  axis("tight");
  subplot(212);
  plot(X1.');
  title('Órbitas del modelo identificado') 
  axis("tight");
display(["||Y(US^+V)-A||_F = ",num2str( norm(Ai-A,'fro'))]);
display(["||Y(US^+V)X-Y||_F = ",num2str( norm(Ai*X-Y,'fro'))]);
Ai