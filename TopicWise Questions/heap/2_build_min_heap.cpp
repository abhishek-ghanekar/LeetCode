#include <bits/stdc++.h> 
void heapify(vector<int> &arr,int n,int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < n && arr[left] < arr[smallest]) {
        smallest = left;
    }
    
    if(right < n && arr[right] < arr[smallest]) {
        smallest = right;
    }
    if(smallest != index) {
        swap(arr[smallest],arr[index]);
        heapify(arr,n,smallest);
    }
}
vector<int> buildMinHeap(vector<int> &arr)
{
    int n = arr.size();
    for(int i=n/2-1;i>=0;i--) {
        heapify(arr,n,i);
    }
    return arr;
}