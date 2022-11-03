class Solution {
    
private:

    vector<int> nextSmallerElements(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=n-1;i>=0;i--){
            int num=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=num)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);

        }
        return ans;
    }

    vector<int> prevSmallerElements(vector<int> arr, int n)
    {
        stack<int> s;
        s.push(-1);
        vector<int> ans(n);

        for(int i=0;i<n;i++){
            int num=arr[i];
            while(s.top()!=-1 && arr[s.top()]>=num)
            {
                s.pop();
            }
            ans[i]=s.top();
            s.push(i);

        }
        return ans;
    }
    
    
public:
    int largestRectangleArea(vector<int>& heights) {
        
        
        int n=heights.size();
        
        vector<int> next(n);
        vector<int> prev(n);
        
        next=nextSmallerElements(heights,n);
        prev=prevSmallerElements(heights,n);
        int area=INT_MIN;
        
        for(int i=0;i<n;i++){
            int l=heights[i];
            int b=next[i]-prev[i]-1;
            
            if(next[i]==-1){
                b=n-prev[i]-1;
            }
            
            int newArea=l*b;
            area=max(area,newArea);
            
        }
        return area;
        
        
    }
};