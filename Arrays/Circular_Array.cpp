#include<iostream>
#include<vector>
using namespace std;
int next(vector<int> a, int i){
    return (i+a[i]+a.size())%a.size();
}
bool CircularLoop(vector<int> &v){
    int n = v.size();
    for(int i=0; i<n; i++){
        int slow = i;
        int fast = i;
        if(v[i]==0){
            continue;
        }
        while(v[slow]*v[next(v, slow)]>0 && 
            v[fast]*v[next(v,fast)]>0 &&
            v[fast]*v[next(v, next(v,fast))]>0){
                slow = next(v,slow);
                fast = next(v,next(v,fast));
            if(slow == fast){
                // That means cycle is present but length should be greater than 1
                if(slow == next(v,slow)){
                    break;
                }
                return true;
            }
        }
        slow = i;
        int val = v[slow];
        while(val*v[slow]>0){
            int x = slow;
            slow = next(v,slow);
            v[x] =0;
        }
    }
    return false;
}

int main(){
    int n;
    cin>> n;

    vector<int> v;
    for(int i=0; i<n; i++){
        int x;
        cin>>x;
        v.push_back(x);
    }
    cout<< CircularLoop(v)<<endl;
}