#include<iostream>
#include<bits/stdc++.h>
#include<math.h>
using namespace std;
#define ll long long int
#define prime 119

ll createHashValue(string str, int n){
    // O(m)
    // I'll keep a prime number as our base
    // If substr is abc we will multiply ascii of every character with corresponding power of prime str[i]*pow(prime,i);
    ll result = 0;
    for(int i=0; i<n; i++){
        result += (ll)(str[i]*(ll)pow(prime,i));
    }
    return result;
}

ll recalculateHash(string str, int oldIndex, int newIndex, ll oldHash, int patLength){
    // 1. Subtract ASCII of first character of the string
    ll newHash = oldHash-str[oldIndex];
    // 2. Divide new hash value by the prime number chosen
    newHash/=prime;
    // 3. Add ASCII of str[newindex]*pow(prime,i);
    newHash+=(ll)(str[newIndex]*(ll)pow(prime,patLength-1));

    return newHash;
}

bool checkEqual(string str1, string str2, int s1,int e1, int s2,  int e2){
    if(e1-s1 != e2-s2){
        return false;
    }
    while(s1<=e1 && s2<=e2){
        if(str1[s1]!=str2[s2]){
            return false;
        }
        s1++;
        s2++;
    }
    return true;

}
int main(){
    string str = "ababcabdab";
    string pat = "abd";
    ll patHash = createHashValue(pat, pat.length());
    ll strhash = createHashValue(str, pat.length());
    for(int i=0; i<=str.length()-pat.length(); i++){
        if(patHash == strhash && checkEqual(str, pat, i, i+pat.length()-1, 0, pat.length()-1)){
            cout<<i<<endl;
            return 0;
        }
        if(i<str.length()-pat.length()){
            strhash = recalculateHash(str, i, i+pat.length(), strhash, pat.length());
       }
    }
}