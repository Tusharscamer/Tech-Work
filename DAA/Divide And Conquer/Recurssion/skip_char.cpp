#include<iostream>
using namespace std;
string skip(string s,string t,int i){
    if(i==t.size()) return "";
    if(t[i]=='a') return s+skip(s,t,i+1);
    else  return s+t[i]+skip(s,t,i+1);
}
int main(){
    string s="Raghav";
    string t="";
    cout<<skip(t,s,0);
}