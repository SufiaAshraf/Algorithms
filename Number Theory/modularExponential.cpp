#include <iostream>
#include <math.h>
using namespace std;

int main(){
    int a, b, c;
    cin >> a>>b>>c;
    int power = pow(a, b);
    cout << power%c;
}

