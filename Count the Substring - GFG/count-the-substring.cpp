//{ Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function Template for C++
class Solution{
public:
  using ll = long long int;
  ll inversions = 0;

  void mergee(vector<ll> &v, int low, int mid, int high){
      ll n1 = (mid - low) + 1, n2 = high - mid;
      vector<ll> a(n1), b(n2);
      int i = 0, j = 0, k = low;
      while(i < n1) a[i ++] = v[k ++];
      while(j < n2) b[j ++] = v[k ++];
      i = 0, j = 0, k = low;
      while(i < n1 and j < n2){
          if(a[i] <= b[j]) v[k ++] = a[i ++];
          else {
              inversions += (n1 - i);
              v[k ++] = b[j ++];
          }

       }
       while(i < n1) v[k ++] = a[i ++];
       while(j < n2) v[k ++] = b[j ++];
  }

  void mergeSort(vector<ll> &v, int low, int high){

      if(low >= high) return;
      int mid = low + (high - low)/2;
      mergeSort(v, low, mid);
      mergeSort(v, mid + 1, high);
      mergee(v, low, mid, high);

  }

  

  long long countSubstring(string s){

      int n = s.size();
      vector<ll> v(n);
      ll ans = 0;
      for(int i = 0; i < n; i ++){
          if(s[i] == '1') v[i] = 1;
          else v[i] = -1;
          if(i > 0) v[i] += v[i - 1];
          if(v[i] > 0) ans ++;

      }
      reverse(v.begin(), v.end());
      mergeSort(v, 0, n - 1);
      ans += inversions;
      return ans;

  }

};



//{ Driver Code Starts.
int main() {
 ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL); 
 int t=1;
 cin>>t;
 for(int i=1;i<=t;i++){
    string S;
    cin>>S;
    Solution obj;
    long long ans =obj.countSubstring(S);
    cout<<ans<<endl;
 }
}
// } Driver Code Ends