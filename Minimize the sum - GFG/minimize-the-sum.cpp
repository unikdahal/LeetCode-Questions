//{ Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
public:
    int minimizeSum(int N, vector<int> arr) {
        if(N == 1)
            return 0;
        
        priority_queue<int, vector<int>, greater<int>> q;
        
        for(int i: arr)
            q.push(i);
        
        int ans = 0;
        int i = N;
        
        while(i != 1){
            int a = q.top();
            q.pop();
            int b = q.top();
            q.pop();
            
            int sum = a + b;
            q.push(sum);
            
            ans += sum;
            
            --i;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
	int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> arr(n);
        for(int i = 0; i < n; i++)
            cin>>arr[i];
        Solution obj;
        cout << obj.minimizeSum(n, arr) << "\n";
    }
}
// } Driver Code Ends