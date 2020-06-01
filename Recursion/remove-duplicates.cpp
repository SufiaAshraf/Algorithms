#include<iostream>
#include<cstring>
using namespace std;

void remove_duplicates(char *a){
	if(a[0] == '\0'){
		return;
	}
	if(a[0] == a[1]){
		int i=0;
		while(a[i] != '\0'){
			a[i] = a[i+1];
			i++;
		}
		remove_duplicates(a);
	}
	remove_duplicates(a+1);
}

int main() {
	char a[10001];
	cin>>a;
	remove_duplicates(a);
	cout<<a;
	return 0;
}