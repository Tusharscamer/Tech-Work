#include<iostream>
using namespace std;
int power(int n){
    if(n<10){
        if(n==4 || n==1) return true;
    }
    else{
        return false;
    }
    return power(n/4);
}
