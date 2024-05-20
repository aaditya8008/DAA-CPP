#include<iostream>
#include <cstring>
using namespace std;



int lcs(char *S1,char *S2,int n1,int n2){
int dp[n1+1][n2+1];



for(int i=0;i<=n1;i++){
    for(int j=0;j<=n2;j++){
     if(i==0||j==0)
       dp[i][j]=0;
     else if(S1[i-1]==S2[j-1]){
        int x=dp[i][j];
        dp[i][j]=dp[i-1][j-1]+1;
       
       
     }
     else{
        dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
     }

    }
}

int index=dp[n1][n2];
char lcs[index+1];
lcs[index]='\0';
int i=n1,j=n2;
while(i>0&&j>0){
   if(S1[i-1]==S2[j-1]){
    lcs[index-1]=S1[i-1];
    i--;
    j--;
    index--;
   }

   else if(dp[i-1][j]>dp[i][j-1]){
    i--;
   }
   else{
    j--;
   }
  

}
 cout<<"LCS of "<<S1<<" and "<<S2<<" is "<<lcs<<endl;
return dp[n1][n2];

}

int main(){
    char X[] = "AGGTAB";
    char Y[] = "GXTXAYB";
    int m = strlen(X);
    int n = strlen(Y);
    int x=lcs(X, Y, m, n);
    cout<<"Size :"<<x<<endl;
    return 0;
}