#include <iostream> 
using namespace std; 
  
class Arithematic{ 
    private: 
        int a,b;
        Arithematic(int c_a,int c_b):a(c_a),b(c_b){};
        friend class friendArithematic;
    public:
        void add(){
            cout<<a<<'+'<<b<<'='<<a+b<<endl;
        }
        void subtract(){
            cout<<a<<'-'<<b<<'='<<a-b<<endl;
        }
        void divide(){
            if(b==0){
                cout<<"infinity"<<endl;
            }
            else{
                cout<<a<<'/'<<b<<'='<<a/b<<endl;
            }
        }
        void multiply(){
            cout<<a<<'*'<<b<<'='<<a*b<<endl;
        }

}; 
  
class friendArithematic{ 
    int a,b;
    public: 
        friendArithematic(int c_a,int c_b):a(c_a),b(c_b){ 
            Arithematic obj(a,b);  
            obj.add();
            obj.subtract();
            obj.multiply();
            obj.divide();
        } 
}; 
  
// Driver program 
int main(){ 
    int a,b;
    cout<<"Enter the values of a and b to perform arithematic operation:"<<endl;
    cout<<"a=";
    cin>>a;
    cout<<"b=";
    cin>>b;
    friendArithematic obj(a,b); 
    return 0; 
} 