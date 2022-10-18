class Solution {
private:
public:
    string countAndSay(int n) {
        
        if(n==1){
            return "1";
        }
        
        string prev=countAndSay(n-1);
        string ans;
        
        int len= prev.length();
        
        for(int i=0;i<len;){
            int j=i,count=0;
            while(j<len){
                if(prev[i]==prev[j]){
                    count++;
                    j++;
                }else{
                    break;
                }
            }
            ans.push_back(count+'0');
            ans.push_back(prev[i]);
            i=j;
        }
        
        return ans;
        
        
        
        
    }
};