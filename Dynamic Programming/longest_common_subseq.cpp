#include<iostream>
#include<cstring>
using namespace std;
int dp[1001][1001]={0};
  
   
string lcs(char* str1,char* str2){
     int m = strlen(str1);
    int n = strlen(str2);
    
    // base case
    for(int i=0; i<=m; i++){ dp[i][0] = 0;}
    for(int j=0; j<=n; j++){dp[0][j] = 0;}
    for(int i=1; i<=m; i++){ 
        for(int j=1; j<=n; j++){
            if(str1[i-1] == str2[j-1]){
                dp[i][j]= 1+dp[i-1][j-1];
            }else{
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
     int i=m;
    int j=n;
    string ans =" ";
    while(i>0 && j>0){
        int x = dp[i][j-1];
        int y = dp[i-1][j];
        if(str1[i-1] == str2[j-1]){
            ans = str1[i-1]+ans;
            i--;
            j--;
        }else if(y>x){
            i--;
        }else{
            j-- ;
        }
    }
    return ans;
}

int main(){
  char str1[1001], str2[1001];
    cin>> str1>>str2;
    string ans = lcs(str1, str2);
    cout<<ans;
}