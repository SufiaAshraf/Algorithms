#include <bits/stdc++.h> 
using namespace std; 

int kadane(int a[], int n);

int maxCircularSum(int a[], int n) 
{ 
	int max_kadane = kadane(a, n); 

	int max_wrap =  0;
	int i;
	for(i=0; i<n; i++){
		max_wrap = max_wrap +a[i];
		a[i] = -a[i];
		}
	 max_wrap = kadane(a, n) + max_wrap;
    return (max_wrap > max_kadane) ? max_wrap: max_kadane;

}
int kadane(int a[], int n){
	 int max_so_far = 0, max_ending_here = 0;  
    int i;  
    for (i = 0; i < n; i++)  
    {  
        max_ending_here = max_ending_here + a[i];  
        if (max_ending_here < 0)  
            max_ending_here = 0;  
        if (max_so_far < max_ending_here)  
            max_so_far = max_ending_here;  
    }  
    return max_so_far; 
} 

int main() 
{ 
	int t;
	cin>> t;
	int a[1000];
	while(t--){
	    int n;
		cin >> n;
		for(int i=0; i<n; i++){
			cin >> a[i];
		}
		cout << maxCircularSum(a, n) << endl; 
	}

	return 0; 
} 
