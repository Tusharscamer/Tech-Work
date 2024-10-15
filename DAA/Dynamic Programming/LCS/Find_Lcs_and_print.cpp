#include<iostream>
#include<vector>
using namespace std;
void printLCS(vector<vector<string>>B,vector<string>X,vector<string>Y,int i,int j){
    if(i==0 || j==0 ){
        return ;
    }
    else if (B[i][j]=="D"){
        printLCS(B,X,Y,i-1,j-1);
        cout<<X[i-1]<<" ";
    }
    else if(B[i][j]=="U"){
        printLCS(B,X,Y,i-1,j);
    }
    else{
        printLCS(B,X,Y,i,j-1);
    }
}
int main(){
    int n,m;
    vector<string>X;
    vector<string>Y;
    cout<<"size of x:";
    cin>>n;
    cout<<"enter elment of x "<<endl;
    string val;
    for(int i=0;i<n;++i){
        cin>>val;
        X.push_back(val);
    }
    cout<<"size of y:";
    cin>>m;
    cout<<"enter elment of y "<<endl;
    for(int i=0;i<m;++i){
        cin>>val;
        Y.push_back(val);
    }
    vector<vector<string>>B(n+1,vector<string>(m+1,"NIL"));
    vector<vector<int>>C(n+1,vector<int>(m+1,0));
    for(int i=1;i<n+1;++i){
        for(int j=1;j<m+1;++j){
             if(X[i-1]==Y[j-1]){
                C[i][j]=C[i-1][j-1]+1;
                B[i][j]="D";
             }
             else if(C[i-1][j]>=C[i][j-1]){
                 C[i][j]=C[i-1][j];
                 B[i][j]="U";
             }
             else{
                C[i][j]=C[i][j-1];
                B[i][j]="L";
             }
        }
    }
    for(int i=0;i<n+1;++i){
        for(int j=0;j<m+1;++j){
            cout<<C[i][j]<<" ";
        }
        cout<<endl;
    }
     for(int i=0;i<n+1;++i){
        for(int j=0;j<m+1;++j){
            cout<<B[i][j]<<" ";
        }
        cout<<endl;
    }
    printLCS(B,X,Y,n,m);
}