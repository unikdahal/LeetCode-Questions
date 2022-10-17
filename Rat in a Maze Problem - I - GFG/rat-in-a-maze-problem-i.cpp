//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution{
    private:
    
    bool ispossible(vector<vector<int>> &m,vector<vector<int>> travelled,string path,int x,int y,vector<string> &ans,int n){
        if(x<=n-1 && x>=0 && y>=0 && y<=n-1 && m[x][y]==1 &&  travelled[x][y]==0){
            return true;
        }
        return false;
    }
    
    void findpath(vector<vector<int>> &m,vector<vector<int>> travelled,string path,int x,int y,vector<string> &ans,int n){
        
        
        if(x==n-1 && y==n-1){
            
            ans.push_back(path);
            return;
        }
        
        travelled[x][y]=1;
        
        //for down
        int newx=x+1;
        int newy=y;
        if(ispossible(m,travelled,path,newx,newy,ans,n)){
            path.push_back('D');
            findpath(m,travelled,path,newx,newy,ans,n);
            path.pop_back();
        }
        
        //for right
        newx=x;
        newy=y+1;
        if(ispossible(m,travelled,path,newx,newy,ans,n)){
            path.push_back('R');
            findpath(m,travelled,path,newx,newy,ans,n);
            path.pop_back();
        }
        
        //for left
        newx=x;
        newy=y-1;
        if(ispossible(m,travelled,path,newx,newy,ans,n)){
            path.push_back('L');
            findpath(m,travelled,path,newx,newy,ans,n);
            path.pop_back();
        }
        
        //for up
        newx=x-1;
        newy=y;
        if(ispossible(m,travelled,path,newx,newy,ans,n)){
            path.push_back('U');
            findpath(m,travelled,path,newx,newy,ans,n);
            path.pop_back();
        }
        
        
        travelled[x][y]=0;
        
    }
    
    public:
    
    vector<string> findPath(vector<vector<int>> &m, int n) {
        
        vector<vector<int>> travelled=m;
        vector<string> ans;
        
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                travelled[i][j]=0;
            }
        }
        if(m[0][0]==0){
            return ans;
        }
        
        string path="";
        int srcx=0;
        int srcy=0;
        
        findpath(m,travelled,path,srcx,srcy,ans,n);
        sort(ans.begin(),ans.end());
        return ans;
        
        
        
    }
};

    


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int> (n,0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m, n);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++) cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends