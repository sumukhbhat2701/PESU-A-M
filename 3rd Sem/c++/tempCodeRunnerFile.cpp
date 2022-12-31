#include<iostream>
using namespace std;
class A {
protected: int a;
public:
A(int a1){a=a1;cout<<"ctor A"<<endl;} A(){cout<<"default ctor A"<<endl;}
~A(){cout<<"dtor A"<<endl;}
};

class B:public A {
protected: int b;
public:
B(int a1,int b1):A(a1){b=b1;cout<<"ctor B"<<endl;}
~B(){cout<<"dtor B"<<endl;}
};

class C:public A {
protected: int c;
public:
C(int a1,int c1):A(a1){c=c1;cout<<"ctor C"<<endl;}
~C(){cout<<"dtor C"<<endl;}
};
class D:public B,public C {
protected: int d;
public:
D(int a1,int b1,int c1,int d1):B(a1,b1),C(a1,c1){d=d1;cout<<"ctor D"<<endl;}
~D(){cout<<"dtor D"<<endl;}
void show(){cout<<"a="<<B::a<<" b="<<b<<" c="<<c<<" d="<<d<<endl;}
};
int main( ) {
D d(1,2,3,4);
d.show( );
return 0;
}
