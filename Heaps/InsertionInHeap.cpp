#include<iostream>
#include<vector>

using namespace std;

void upheapify(vector<int> &heap, int index){
    if(index == 0){
        return;
    }
    int parentIndex = (index -1)/2;
    if(heap[parentIndex] < heap[index]){
        int temp = heap[parentIndex];
        heap[parentIndex] = heap[index];
        heap[index] = temp;
        upheapify(heap, parentIndex);
    }else{
        return;
    }
}

void downheapify(vector<int> &heap, int index){
    int leftIndex = 2*index +1;
    int rightIndex = 2*index +2;
    if(leftIndex>= heap.size() && rightIndex >= heap.size()){
        return;
    } 
    int largestIdx = index;
    if(leftIndex < heap.size() && heap[leftIndex] > heap[largestIdx]){
        largestIdx = leftIndex;
    }
    if(rightIndex < heap.size() && heap[rightIndex] > heap[largestIdx]){
        largestIdx = rightIndex;
    }
    if(largestIdx == index){
        return;
    }
    swap(heap[index] , heap[largestIdx]);
    downheapify(heap, largestIdx);
}

void deletePeek(vector<int> &heap){
    swap(heap[0], heap[heap.size()-1]);
    heap.pop_back();
    downheapify(heap, 0);
}

void Insert(vector<int> &heap , int key){
    heap.push_back(key);
    upheapify(heap, heap.size()-1);
}

void buildHeap(vector<int> &heap){
    for(int i=0; i<heap.size() -1; i++){
        upheapify(heap, i);
    }
}


void display(vector <int> &heap){
    for(int i=0; i<heap.size(); i++){
        cout<<heap[i]<<" ";
    }
    cout<< endl;
}

void buildHeapOptimised(vector<int> &heap){
    for(int i= heap.size() -1; i>=0; i--){
        downheapify(heap, i);
    }
}


void downheapifyHelper(vector<int> &heap, int index, int heapSize){
    int leftIndex = 2*index +1;
    int rightIndex = 2*index +2;
    if(leftIndex>= heapSize && rightIndex >= heapSize){
        return;
    } 
    int largestIdx = index;
    if(leftIndex < heapSize && heap[leftIndex] > heap[largestIdx]){
        largestIdx = leftIndex;
    }
    if(rightIndex < heapSize && heap[rightIndex] > heap[largestIdx]){
        largestIdx = rightIndex;
    }
    if(largestIdx == index){
        return;
    }
    swap(heap[index] , heap[largestIdx]);
    downheapifyHelper(heap, largestIdx, heapSize);
}


void heapSort(vector<int> &arr){
    int heapSize = arr.size();
    buildHeapOptimised(arr);
    for(int i=arr.size()-1; i>=0; i--){
        swap(arr[0], arr[i]);
        heapSize-=1;
        downheapifyHelper(arr, 0, heapSize);
    }
}


int main(){
    vector<int> arr;
    int n;
    cin>> n;
    for(int i=0; i<n; i++){
        int x;
        cin>> x;
        // Insert(heap, x);
        arr.push_back(x);
    }
    buildHeapOptimised(arr);
    display(arr);
    // deletePeek(heap);
    // display(heap);
}