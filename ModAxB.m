 A1=[1 -2 1 0 0 ;0 1 -2 1  0;0 0 1 -2 1;0 0 0 1 -2];
 A2=[1 -3 1 4 1 0 0 0; 0 1 -3 1 4 1 0 0; 0 0 1 -3 1 4 1 0; 0 0 0 1 -3 1 4 1];
 A=[A1 A2];
 B=[1 3 -2;1 -1 2;-1 3 1; -2 3 2];
 N=5;
 X1=randn(5,3*N);
 X2=randn(8,3*N);
 X=[X1;X2];
 Y=A*X+repmat(B,1,N);
 X=[X;repmat(eye(3),1,N)];
 AB1=Y/X;
 AA1=AB1(:,1:5)
 AA2=AB1(:,6:13)
 BB=AB1(:,14:16)
 display( num2str( norm([A B]-AB1,"fro")));
 display(num2str( norm(Y-AB1(:,1:13)*[X1;X2]-repmat(BB,1,N),"fro")));