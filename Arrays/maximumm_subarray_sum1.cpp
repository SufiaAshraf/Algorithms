#include <iostream>
using namespace std;
int main() {
   int  n;
   cin >> n;
   int left = -1;
   int right = -1;
   int A[1000];
   int maxsum =0;
   for(int i=0; i<n; i++){
       cin >> A[i];
   }
  
   for(int i=0; i<n; i++){
       for(int j=i; j<n; j++){
            int sum=0;
           for(int k=i; k<=j; k++){
               sum+=A[k];

           }
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
