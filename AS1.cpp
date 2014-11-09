
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <cmath>

int main()
{

  
/*Calculate the intercept of a line on the x-axis*/

//y = a+bx

double a, b, x0;

a =1;
b =2;

x0 =-a/b;

printf("x0=%lf\n",x0);

/*Solve a quadratic equation*/

// Ax^2 +Bx +C=0

double A, B, C, D;
double x1, x2;

A =1;
B =2;
C =0.5;

D =B*B-4*A*C;

x1 =(-B+sqrt(D))/(2*A);
x2 =(-B-sqrt(D))/(2*A);

printf("x1=%lf\tx2=%lf\n",x1,x2);

/*Calculate the length of vector*/

// v = (v1,v2,v3)

double v, v1, v2, v3;

v1 =2;
v2 =2;
v3 =2;

v=sqrt(v1*v1+v2*v2+v3*v3);

printf("v=%lf\n",v);

/*Calculate the invariant mass of two particles*/

//M=sqrt(m1^2+m2^2+2*(E1*E2-p1*p2))

double M, m1, m2;
double E1,E2;
double p1x, p1y, p1z, p2x, p2y, p2z;

m1 =10;
p1x =1;
p1y =2;
p1z =3;

m2 =20;
p2x =1;
p2y =2;
p2z =3;

E1 =sqrt(m1*m1+p1x*p1x+p1y*p1y+p1z*p1z);

E2 =sqrt(m2*m2+p2x*p2x+p2y*p2y+p2z*p2z);

M = sqrt(m1*m1+m2*m2+2*E1*E1-2*(p1x*p2x+p1y*p2y+p1z*p2z));

printf("M=%lf\n",M);


}
