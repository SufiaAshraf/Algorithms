#include<iostream>
#include<bits/stdc++.h>
using namespace std;
bool compare(string s1, string s2){
    string s1s2=s1.append(s2);
    string s2s1=s2.append(s1);
    return s1s2.compare(s2s1)>0;
}
int main() {
		int t;
		cin>>t;
		while(t--){
			int n;
			cin>>n;
			string A[n];
			for(int i=0;i<n;i++)
				cin>>A[i];
			sort(A,A+n,compare);
			for(int i=0;i<n;i++){
				cout<<A[i];
			}
			cout<<endl;
			}
	return 0;
}
