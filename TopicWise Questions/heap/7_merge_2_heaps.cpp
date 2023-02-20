class Solution{
    public:
    void heapify(vector<int> &arr,int n,int index) {
    int smallest = index;
    int left = 2*index + 1;
    int right = 2*index + 2;
    if(left < n && arr[left] >arr[smallest]) {
        smallest = left;
    }
    
    if(right < n && arr[right] > arr[smallest]) {
        smallest = right;
    }
    if(smallest != index) {
        swap(arr[smallest],arr[index]);
        heapify(arr,n,smallest);
    }
}
    vector<int> mergeHeaps(vector<int> &a, vector<int> &b, int n, int m) {
        //merge both arrays
        vector<int> ans;
        for(auto i:a) {
            ans.push_back(i);
        }
        for(auto i:b) {
            ans.push_back(i);
        }
        int size = ans.size();
        for(int i=size/2;i>=0;i--) {
    heapify(ans,size,i);
   }
   
   return ans;
        
    }
};