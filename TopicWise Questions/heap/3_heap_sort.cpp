#include <iostream>
#include <vector>
using namespace std;

void heapify(int arr[],int n,int index) {
    int smallest = index;
    int left = 2*index ;
    int right = 2*index + 1;
    if(left <= n && arr[left] > arr[smallest]) {
        smallest = left;
    }
    
    if(right <= n && arr[right] > arr[smallest]) {
        smallest = right;
    }
    if(smallest != index) {
        swap(arr[smallest],arr[index]);
        heapify(arr,n,smallest);
    }
}
void heapSort(int arr[],int n) {
    int size = n;
    while(size > 1) {
        //step 1 :
        swap(arr[1],arr[size]);
        size--;

        heapify(arr,size,1);
    }
}
int main() {
    int arr[6] = {-1,40,32,60,50,12};
    int n = 5;

   cout << "printing the heap" << endl;
   for(int i=1;i<=n;i++) {
      cout << arr[i] << " ";
   }
   cout << endl;
   heapSort(arr,n);
   cout << "printing the heap" << endl;
   for(int i=1;i<=n;i++) {
      cout << arr[i] << " ";
   }
   

    return 0;
}