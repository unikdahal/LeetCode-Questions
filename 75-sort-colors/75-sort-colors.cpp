class Solution {
public:
    void sortColors(vector<int>& arr) {
        
        int n=arr.size()-1;
        
        int i=0;
        
       for(int j=0;j<arr.size();j++){
           if(arr[j]==0){
               swap(arr[i],arr[j]);
               i++;
           }
       }
       for(int j=i;j<arr.size();j++){
           if(arr[j]==1){
               swap(arr[i],arr[j]);
               i++;
           }
       }
        
        
        
    }
};