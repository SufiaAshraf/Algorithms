#include <iostream>
using namespace std;
int main() {
   int  n;
   cin >> n;
   int left = -1;
   int right = -1;
   int A[1000];
   int cumSum[1000] = {0};
   int maxsum =0;
   cin>> A[0];
   cumSum[0]= A[0];
   for(int i=1; i<n; i++){
       cin >> A[i];
        cumSum[i] = cumSum[i-1]+A[i];
   }
  
   for(int i=0; i<n; i++){
       for(int j=i; j<n; j++){
            int sum=0;
            sum = cumSum[j]-cumSum[i-1];
            
           if(sum>maxsum){
               maxsum = sum;
               left =i;
               right =j;
           }
       }
   }
   cout<<"Maximum Sum is: "<< maxsum<< '\n';
   for(int k= left; k<=right; k++){
       cout<< A[k]<< ", ";
   }
}
