#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;
    int A[100000];
    int k;
    cin>> n;
    for(int i=0; i<n; i++){
        cin>> A[i];
    }
    cin>>k;
    // For first k elements
    int i;
    deque <int> Q(k);
    for(i=0; i<k; i++)[
        while(!Q.empty() && A[i]>A[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
    ]

    // Processing remaining elements
    for(; i<n; i++){
        cout<<A[Q.front()]<<" ";
        // Remove elements which are not part of the window
        while(!Q.empty()&& Q.front <= i-k){
            Q.pop_front();
        }
        while(!Q.empty() && A[i] >= A[Q.back()]){
            Q.pop_back();
        }
        Q.push_back(i);
        cout<< A[Q.front()]<<endl;
    }
}