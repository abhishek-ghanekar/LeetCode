#include<bits/stdc++.h>
vector<int> firstNegative(vector<int> arr, int n, int k) {
	vector<int> ans;
	queue<int> q;
	int i = 0;
	int j = 0;
	while(j < n) {
		if(arr[j] < 0) {
			q.push(arr[j]);
		}
		if(j-i+1 < k) {
			j++;
		}else if(j-i+1 == k) {
			if(q.size()) {
				ans.push_back(q.front());
			}else {
				ans.push_back(0);
			}
            if(arr[i] < 0) {
				q.pop();
			}
			
			i++;
			j++;
		}
	}
	return ans;
}