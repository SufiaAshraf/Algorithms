#include<iostream>
#include<algorithm>

using namespace std;

bool validPosition(int ans , int stalls[], int N, int C){
	int Cows = 1;
	int pos = stalls[0];
	for(int i=1; i<N; i++){
		if(stalls[i] - pos >= ans){
				pos = stalls[i];
				Cows++;
				if(Cows == C){
					return true;
				}
		}
	}
	return false;
}

int binarySearch(int stalls[] ,int N, int C){
	int start =0;
	int end = N-1;
	int mid , max = -1;
	while(start<=end){
		if(validPosition(mid, stalls, N, C)){
			if(mid>max){
				max = mid;
				start = mid+1;
			}
		}
		else {
			end = mid -1;
		}
	}
	return max;
}

int main() {
	int N,C;
	cin>> N>>C;
	int stalls[N];
	for(int i=0; i<N; i++){
		cin>> stalls[i];
	}
	sort(stalls, stalls+N);
	int k= binarySearch(stalls, N, C);
	cout<<k;
	return 0;
}