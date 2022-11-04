//{ Driver Code Starts
//Initial Template for C++

#include<bits/stdc++.h>
using namespace std;
queue<int> rev(queue<int> q);
int main()
{
    int test;
    cin>>test; 
    while(test--)
    {
    queue<int> q; 
    int n, var; 
    cin>>n; 
    while(n--)
    {
        cin>>var; 
        q.push(var);
    }
    queue<int> a=rev(q); 
    while(!a.empty())
    {
        cout<<a.front()<<" ";
        a.pop();
    }
    cout<<endl; 
    }
}
// } Driver Code Ends


//function Template for C++

//Function to reverse the queue.

void reverse(stack<int> &s,queue<int> &q){
    if(q.size()==0){
        return;
    }
    int n=q.front();
    q.pop();
    s.push(n);
    reverse(s,q);
    n=s.top();
    q.push(n);
    s.pop();
    return;
}


queue<int> rev(queue<int> q)
{
    stack<int> r;
    reverse(r,q);
    return q;
}