#include<iostream>
using namespace std;

int main () {
	int x, y;
	cin>> x>> y;
	int ans =0;
	int max =0;
	for(int i=x; i<=y; i++){
		for(int j=x; j<=y; j++){
			ans = i^j;
			if(ans> max){
				max= ans;
			}
		}
	}
	cout<< max;
	return 0;
}