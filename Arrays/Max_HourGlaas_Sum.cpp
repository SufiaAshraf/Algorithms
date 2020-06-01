#include<iostream>
#include<vector>
#include<algorithm>
#include<bits/stdc++.h>
using namespace std;
int A[6][6];
int hourGlassSum(){
    vector<int> sum;
    sum.reserve(16);
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
    int temp =A[i][j]+A[i][j+1]+A[i][j+2]+A[i+1][j+1]+ A[i+2][j]+A[i+2][j+1]+A[i+2][j+2];
             sum.push_back(temp); 
        }
    }
   return  *max_element(sum.begin(), sum.end());

}
int main(){

   for(int i=0; i<6; i++){
        for(int j=0; j<6; j++){
            cin>> A[i][j];
        }
    }
    cout<<hourGlassSum()<<endl;

}
