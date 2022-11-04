//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.

void reverse(stack<int> &s,queue<int> &q,int k,int count){
    if(q.empty() || count>=k){
        return;
    }
    int n=q.front();
    q.pop();
    s.push(n);
    reverse(s,q,k,count+1);
    n=s.top();
    q.push(n);
    s.pop();
    return;
}

queue<int> modifyQueue(queue<int> q, int k) {
    int count=0;
    stack<int> s;
    reverse(s,q,k,count);
    
    for(int i=0;i<q.size()-k;i++){
        int num=q.front();
        q.pop();
        q.push(num);
    }
    return q;
}