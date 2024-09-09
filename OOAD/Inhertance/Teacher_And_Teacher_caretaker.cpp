// Public inheritance
#include<iostream>
using namespace std;
class Teacher{
   public :
   Teacher (string fn,string ln,string id,int bs){
         setfname(fn);
         setlname(ln);
         setid(id);
         setbsalary(bs);
   }
   void setfname(string fn){
      first_name=fn;
   }
   void setlname(string ln){
      last_name=ln;
   }
   void setid(string id){
       Id=id;
   }
   void setbsalary(int bs){
      base_salary=bs;
   }
   string getfname(){
      return first_name;
   }
   string getlname(){
    return last_name;
   }
   string getid(){
    return Id;
   }
   int getbsalary(){
    return base_salary;
   }
   void print(){
      cout<<"Name :"<<getfname()<<" "<<getlname()<<endl;
      cout<<"Id :"<<getid()<<endl;
      cout<<"Base :"<<getbsalary()<<endl;
   }
   private:
   string first_name;
   string last_name;
   string Id;
   int base_salary;
};
class Teacher_caretaker :public Teacher{
    public:
    Teacher_caretaker(string fn,string ln,string id,int bs,int ps)
     : Teacher(fn,ln,id,bs)
    {
        passive_salary=ps;
    }
    void setpsalary(int ps){
         passive_salary=ps;
    }
    int getpsalary(){
      return passive_salary;
    }
    int gettotal_salary(){
      return getbsalary()+getpsalary();
    }
    void print(){
      Teacher ::print();
       cout<<"Passive salary :"<<getpsalary()<<endl;
       cout<<"Total salary :"<<gettotal_salary()<<endl;
    }
    private:
      int passive_salary;
};
int main(){
   Teacher_caretaker t1("anup","malik","3434DSERSE",200000,10000);
   t1.print();
}
