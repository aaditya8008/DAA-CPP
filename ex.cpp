#include<iostream>
#include <limits.h>
#include <cstring>
using namespace std;

int lcs(char *S1,char *S2,int n1,int n2){
int dp[n1+1][n2+1];
for(int i=0;i<n1;i++){
    for(int j=0;j<n2;j++){
        if(i==0||j==0){
            dp[i][j]=0;
        }
        else if(S1[i]==S2[j]){
            dp[i][j]=dp[i-1][j-1]+1;
        }
        else{
            dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
        }
    }

}


}

int main(){
    char A[]="AGGTAB";
    char B[]="GXTXAYB";
    int m=strlen(A);
    int n=strlen(B);
    int x=lcs(A,B,m,n);
    cout<<"LCS:"<<x<<endl;
    return 0;

}