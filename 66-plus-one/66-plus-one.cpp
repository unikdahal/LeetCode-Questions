class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int sum=0;
        vector<int> ans;
        for(int i=digits.size()-1;i>=0;i--){
            if(i==digits.size()-1){
                sum=sum+digits[i]+1;
            }else{
                sum=sum+digits[i];
            }
            int rem=sum%10;
            ans.push_back(rem);
            sum=sum/10;
        }
        while(sum!=0){
            int rem=sum%10;
            ans.push_back(rem);
            sum=sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
        
        
    }
};