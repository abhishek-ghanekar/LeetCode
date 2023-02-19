#include <iostream>
using namespace std;
class heap {
  public:
  int arr[100];
  int size;
  heap() {
    arr[0] = -1;
    size = 0;
  }
  void insert(int val) {
    size++;
    int index = size;
    arr[index] = val;
    while(index > 1) {
        int parent = index/2;
        if(arr[parent] < arr[index]) {
            swap(arr[parent],arr[index]);
            index = parent;
        }else {
            return ;
        }
    }
  }
  void print() {
    for(int i=1;i<=size;i++) {
        cout << arr[i] << " ";
    }
  }
  void deleteFromHeap() {
    if(size ==0 ){
        cout << "nothing to delete from heap" << endl;
        return ;
    }
    //first replace first element with last element
    arr[1] = arr[size];
    size--;
    //take node to correct position
    int i = 1;
    while(i<size) {
        int leftIndex = 2*i;
        int rightIndex = 2*i + 1;
        if(leftIndex < size && arr[leftIndex] > arr[i]) {
            swap(arr[i],arr[leftIndex]);
            i = leftIndex;
        }else if(rightIndex < size && arr[rightIndex] > arr[i]) {
            swap(arr[i],arr[rightIndex]);
            i = rightIndex;
        }else {
            return ;
        }
    }

  }
};
void heapify(int arr[],int n,int index) {
    int largest = index;
    int left = 2*index;
    int right = 2*index + 1;
    if(left <n && arr[left] > arr[largest]) {
        largest = left;
    }else if(right < n && arr[right] > arr[largest]) {
        largest = right;
    }
    if(largest != index) {
        swap(arr[largest],arr[index]);
        heapify(arr,n,largest);
    }

}
int main() {
//    heap h;
//    h.insert(50);
//    h.insert(55);
//    h.insert(53);
//    h.insert(52);
//    h.insert(54);
//    h.print();

//    h.deleteFromHeap();
//    cout << endl;
//    h.print();
   int arr[6] = {-1,54,53,55,52,50};
   int n = 5;
   for(int i=n/2;i>0;i--) {
    heapify(arr,n,i);
   }
   cout << "printing the heap" << endl;
   for(int i=1;i<=n;i++) {
      cout << arr[i] << " ";
   }
   return 0;
}