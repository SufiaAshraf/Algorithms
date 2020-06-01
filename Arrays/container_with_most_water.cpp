#include<iostream>
#include<climits>

using namespace std;

int main(){
    int n;
    cin>> n;
    int* a = new int[n+1];
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    int left = 0;
    int right =n-1;
    int area = 0;
    while(left<right){
        area = max(area, (min(a[left], a[right])*(right-left) ));
        if(a[left]<a[right]){
            left++;
        }else{
            right--;
        }
    }
    cout<< area<<endl;
}

