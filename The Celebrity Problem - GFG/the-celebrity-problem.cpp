//{ Driver Code Starts
//Initial template for C++

#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template for C++

class Solution 
{
    public:
    //Function to find if there is a celebrity in the party or not.
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack<int> ans;
        
        for(int i=0;i<n;i++){
            ans.push(i);
        }
        
        while(ans.size()>1){
            int num1=ans.top();
            ans.pop();
            int num2=ans.top();
            ans.pop();
            
            if(M[num1][num2]==1){
                ans.push(num2);
            }else if(M[num2][num1]==1){
                ans.push(num1);
            }
        }
        
        int celeb=ans.top();
        for(int i=0;i<n;i++){
            if(M[celeb][i]==1 && i!=celeb)
                return -1;
        }
        for(int i=0;i<n;i++){
            if(M[i][celeb]==0 && i!=celeb)
                return -1;
        }
        
        
        
        if(ans.size()==0){
            return -1;
        }
        return ans.top();
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