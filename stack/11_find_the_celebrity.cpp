//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    private:
    bool knows(int a,int b,vector<vector<int>> M) {
        if(M[a][b] == 1) {
            return true;
        }else {
            return false;
        }
    }
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        //push all elements in the stack
        stack<int> s;
        for(int i=0;i<n;i++) {
            s.push(i);
        }
        //step 2
        while(s.size() > 1) {
            int a = s.top();
            s.pop();
            int b = s.top();
            s.pop();
            if(knows(a,b,M)) {
                s.push(b);
            }else {
                s.push(a);
            }
        }
        //now the single element in stack is the celebrity
        int celeb = s.top();
        
        //check row
        bool rowCheck = false;
        int zeroCount = 0;
        for(int i=0;i<n;i++) {
            if(M[celeb][i] == 0) {
                zeroCount++;
            }
        }
        if(zeroCount == n) {
            rowCheck = true;
        }
        //check column
        bool colCheck = false;
        int colCount = 0;
        for(int i=0;i<n;i++) {
            if(M[i][celeb] == 1) {
                colCount++;
            }
        }
        if(colCount == n-1) {
            colCheck = true;
        }
        
        if(colCheck == true && rowCheck == true) {
            return celeb;
        }else {
            return -1;
        }
    }
};

//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<vector<int> > M( n , vector<int> (n, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                cin>>M[i][j];
            }
        }
        Solution ob;
        cout<<ob.celebrity(M,n)<<endl;

    }
}

// } Driver Code Ends