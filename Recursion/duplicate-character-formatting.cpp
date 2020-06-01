#include<iostream>
#include<cstring>
using namespace std;

void duplicate_character(char *str, int i){
	int n = strlen(str);
	if(i == n-1){
		return ;
	}
	if(str[i] == str[i+1]){
		for(int j=n; j>i; j--){
			str[j] = str[j-1];
		}
		str[i+1] = '*';
	}
	return duplicate_character(str, i+1);
}

int main() {
	char str[2000];
	cin>>str;
	duplicate_character(str, 0);
	cout<< str;
	return 0;
}