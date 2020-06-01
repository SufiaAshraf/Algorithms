#include<iostream>
#include<cstring>
using namespace std;

int countLCS(string str1, string str2, string str3){
    int m=str1.length();
    int n = str2.length();
    int p = str3.length();

    int dp[m+1][n+1][p+1] = {0};
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            for(int k=0; k<=p; k++){
                if(i==0 || j==0 || k==0){
                    dp[i][j][k] =0;
                }
                if(str1[i-1]==str2[j-1] && str2[j-1]==str3[k-1]){
                    dp[i][j][k] = 1+dp[i-1][j-1][k-1];
                }else{
                    dp[i][j][k] = max(dp[i-1][j][k], max(dp[i][j-1][k], dp[i][j][k-1]));
                }
            }
        }
    }
    return dp[m][n][p];
}

int main(){
    string str1, str2, str3;
    cin>> str1>>str2>>str3;
    cout<< countLCS(str1, str2, str3);
}