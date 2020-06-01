#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    int a[100000];
    int k;
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> a[i];
    }
    cin>> k;

    // We have to process first k elements separately
    deque <int>  Q(k);
    int i;
    for(i=0; i<k; i++){
        while (!Q.empty() && a[i]>a[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    }
    // Process remaining element
    for(; i<n; i++){
        cout<<a[Q.front()]<<" ";
        // 1. Remove the elements which are not the part of the window
        while(!Q.empty() && Q.front()<=i-k){
            Q.pop_front();
        }
        // 2. Remove the elements which are not useful but are in the window
        while(!Q.empty() && a[i]>= a[Q.back()]){
            Q.pop_back();
        }


        // 3. Add the new elements(Expansion)
        Q.push_back(i);
    }
    cout<< a[Q.front()]<<endl;
}