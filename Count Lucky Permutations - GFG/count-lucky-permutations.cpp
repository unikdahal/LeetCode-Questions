//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++
#define ll long long
class Solution {
public:
    bool getBit(int mask, int i) {
        return mask & (1 << i);
    }
    
    vector<vector<ll>> dp;
    
    ll helper(int prevIdx, int mask, vector<int>& arr, vector<vector<int>>& adj) {
        int n = arr.size();

        if(mask == (1 << n) - 1) return 1;
        if(dp[prevIdx+1][mask] != -1) return dp[prevIdx+1][mask];

        int prev = (prevIdx == -1) ? -1: arr[prevIdx];
        ll res = 0;
        for(int i = 0; i < n; i++) {
            if(getBit(mask, i)) continue;
            int curr = arr[i];
            
            // pick
            if(prev == -1 || adj[prev][curr]) {
                ll val = helper(i, mask | (1 << i), arr, adj);
                res += val;
            }
        }

        return dp[prevIdx+1][mask] = res;
    }
  
    long long int luckyPermutations(int n, int M, vector<int> arr,
                                    vector<vector<int>> graph) {
        // Code here
        
        for(auto &it: arr) it--;
        
        vector<vector<int>> adj(n, vector<int>(n, 0));
        
        for(auto it: graph) {
            int u = it[0], v = it[1];
            u--; v--;
            adj[u][v] = true;
            adj[v][u] = true;
        }
        
        dp = vector<vector<ll>>(n+1, vector<ll>(1 << n, -1));
        int mask = 0;
        return helper(-1, mask, arr, adj);
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, M;
        cin >> N >> M;
        vector<int> arr(N);
        vector<vector<int>> graph(M, vector<int>(2));
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }
        for (int i = 0; i < M; i++) {
            for (int j = 0; j < 2; j++) {
                cin >> graph[i][j];
            }
        }
        Solution obj;
        cout << obj.luckyPermutations(N, M, arr, graph) << endl;
    }
}

// } Driver Code Ends