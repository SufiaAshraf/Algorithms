#include<iostream>
using namespace std;
void tower_of_hanoi(int n, char src, char dest, char helper){
    if(n==0){
        return;
    }
    tower_of_hanoi(n-1, src, helper, dest);
    cout<<"Moving ring "<<n<<" from "<<src<<" to "<< dest<<endl;
    tower_of_hanoi(n-1, helper, dest, src);
}

int main() {
    int n;
    cin>>n;
    char A, B, C;
    tower_of_hanoi(n,'A', 'B', 'C');
	return 0;
}