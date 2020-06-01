#include <iostream>
#include <stack>
using namespace std;

void printSpan(int arr[], int n){
    stack <int> s;
    int ans[n] = {0};
    for(int day = 0; day<n; day++){
        int curPrice = arr[day];
        while (s.empty() == false && arr[s.top()] < curPrice){
            s.pop();
        }
        int betterDay = s.empty() ? day+1 : day-s.top();
        
        ans[day] = betterDay;
        s.push(day);
    }
    for(int i=0; i<n; i++){
        cout<< ans[i]<<" ";
    }
    cout<<"END"<<endl;
}

int main(){
    int n;
    cin>>n;
    int arr[n];
   for(int i=0; i<n; i++){
       cin>>arr[i];
   }
   if(n>0)
    printSpan(arr, n);
    return 0;
}