A=[0.95 0.04 0 0;0.05 0.85 0 0; 0 0.10 1 0; 0 0.01 0 1];
Xo=[1 0 0 0];Error=0.01;
N=400;
for k=1:N
	X = [X [A*X(:,k)+Error*randn(4,1)]];
end
Y = X(:,2:(N+1));
X = X(:,1:N);
A1=minimo(X,Y)
display(["||ArX-Y||_F = ",num2str( norm(A1*Xo'-Y,"fro"))]);
display(["||Ar-A||_F = ",num2str( norm(A1-A,"fro"))]);
X0 = X1 = Xo';
  for k = 1:300
	  X0 = [X0 A*X0(:,k)];
	  X1 = [X1 A1*X1(:,k)];
  end
  
  subplot(211);
  plot(X0.');
  title('Órbitas del modelo original')

  subplot(212);
  plot(X1.');
  title('Órbitas del modelo identificado')
  