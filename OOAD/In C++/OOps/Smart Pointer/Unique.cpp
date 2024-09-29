#include<iostream>
#include<memory>
using namespace std;
class Unique{
    private:
     string str;
    public:
    Unique(){

    }
    Unique(string s){
        str=s;
    }
    string non(){
         return this->str;
    }
   void print(){
       cout<<"you are reffering to unique pointer "<<endl;
   }

};
int main(){
    // first Way
    unique_ptr<Unique> p1(new Unique);
    p1->print();

    // second Way
   unique_ptr<Unique> P1(new Unique("tushar"));

    // moveing value of p1->p2
    unique_ptr<Unique> p2= move(p1);
    p2->print();
    p1->print();
    cout<<p1.get();
    cout<<p2.get();

    // moving value of P1->P2
     unique_ptr<Unique> P2=(move(P1)); 
     cout<<(P1->non())<<endl;// giving null value
     cout<<((*P2).non());// returning address why ?
}