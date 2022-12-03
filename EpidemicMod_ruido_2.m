A=[0.95 0.04 0 0;0.05 0.85 0 0; 0 0.10 1 0; 0 0.01 0 1];
Xo=[1 0 0 0];Error=0.01;
N=1;
for k=1:N
	X = [X [A*X(:,k)+Error*randn(4,1)]];
end
Y = X(:,2:(N+1));
X = X(:,1:N);
A1=minimo(X,Y);
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
  
function S1=minimo(X,Y)
D=X*transpose(X);
I=eye(4);
R=ones(20,1);M=zeros(20);
for i=1:4
  R(4*(i-1)+1:4*i,1)= 2*X(i,:)*Y';
  M(4*(i-1)+1:4*i,4*(i-1)+1:4*i)=2*D;
  M(17:20,4*(i-1)+1:4*i)=I;
  M(4*(i-1)+1:4*i,17:20)=I;
endfor
S=pinv(M,1e-10)*R;
S1=reshape(S(1:16),4,4);
endfunction