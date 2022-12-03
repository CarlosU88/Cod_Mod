function S1=minimo(X,Y)
D=X*transpose(X);
Z=Y*Y';
I=eye(4);
R=ones(20,1);M=zeros(20);
for i=1:4
  R(4*(i-1)+1:4*i,1)= 2*Z(:,i);
  M(4*(i-1)+1:4*i,4*(i-1)+1:4*i)=2*D;
  M(17:20,4*(i-1)+1:4*i)=I;
  M(4*(i-1)+1:4*i,17:20)=I;
endfor
S=pinv(M)*R;
S1=reshape(S(1:16),4,4);
endfunction