#include <bits/stdc++.h>

using namespace std;

int main()
{
   vector<vector<int>> arr(6); 
    for (int i = 0; i < 6; i++) {
        arr[i].resize(6);

        for (int j = 0; j < 6; j++) {
            cin >> arr[i][j];
        }

        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    int max = INT_MIN;
    for(int i=0; i<4; i++){
        for(int j=0; j<4; j++){
            int sum =0;
            for(int x=j; x<j+3; x++)
                sum += arr[i][x];
            
            for(int x=j; x<j+3; x++)
                sum += arr[i+2][x];
            sum+=arr[i+1][j+1];    
            if(sum>max){
                max = sum;
            }
        }
    }
    cout<<max;
    return 0;
}
