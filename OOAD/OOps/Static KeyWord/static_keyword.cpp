// C++ program to demonstrate
// the use of static Static
// variables in a Function
#include <iostream>
#include <string>
using namespace std;
class In{
    public:
     int counti;
    In(){

    }
};
void display(int n){
    if(n<9){
        static int count=0;
        ++count;
        cout<<count<<" ";
    }
    display(n+1);
}
int main()
{
     int n=6;
	for (int i = 0; i < 5; i++){
     static int c=0;
      ++c;
      cout<<c<<" ";
    }
    cout<<endl;
    display(n);
    In obj;
    obj.counti=10;
    cout<<obj.counti<<endl;
    // obj.counti=11;
    cout<<obj.counti<<endl;
}
