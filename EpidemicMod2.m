 A=[0.95 0.04 0 0;0.05 0.85 0 0; 0 0.10 1 0; 0 0.01 0 1];
 Xo=[1 0 0 0];N=1000;
 Y=X=Xp=Xr=Xo';
for k=1:N
	X = [X A*X(:,k)];
end
Y = X(:,2:(N+1));
X = X(:,1:N);
[V,D,U] = svd (X,'econ') ;
Ai=(Y*U*pinv(D)*V');
X0 = X1 = Xo';
  for k = 1:300
	  X0 = [X0 A*X0(:,k)];
	  X1 = [X1 Ai*X1(:,k)];
  end
  axis("tight");
  subplot(211);
  plot(X0.');
  title('Órbitas del modelo original')
  subplot(212);
  plot(X1.');
  title('Órbitas del modelo identificado') 
display(["||Y(US^+V)-A||_F = ",num2str( norm(Ai-A,'fro'))]);
display(["||Y(US^+V)X-Y||_F = ",num2str( norm(Ai*X-Y,'fro'))]);
Ai