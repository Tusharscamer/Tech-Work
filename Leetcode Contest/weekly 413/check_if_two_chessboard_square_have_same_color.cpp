class Solution {
public:
    bool checkTwoChessboards(string coordinate1, string coordinate2) {
        int count=0;
           int s1;
           int s2;
           string a1;
           string a2;
           s1=int(coordinate1[0]);
           s2=int(coordinate1[1]);
           if(s1%2==0 && s2%2==0){
               a1="black";
           }
           else if(s2%2!=0 && s1%2!=0){
              a1="black";
           }
           else{
              a1="white";
           }
           s1=int(coordinate2[0]);
           s2=int(coordinate2[1]);
           if(s1%2==0 && s2%2==0){
               a2="black";
           }
           else if(s2%2!=0 && s1%2!=0){
              a2="black";
           }
           else{
              a2="white";
           }
           if(a1==a2){
            return true;
           }
           return false;
    }
};