class Solution {
    
private:
void solve(string digits,vector<string>& ans,string mapping[],string output,int i){
        
        
    if(i>=digits.length()){
        ans.push_back(output);
        return;
    }
    
    string value=mapping[digits[i]-'0'];
    
    for(int j=0;j<value.length();j++){
        
        output.push_back(value[j]);
        solve(digits,ans,mapping,output,i+1);
        output.pop_back();
            
        
        
    }
        
        
        
        
        
        
        
        
        
    }
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> ans;
        string mapping[10]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        
        string output="";
        
        if(digits.length()==0){
            return ans;
        }
        int i=0;
        solve(digits,ans,mapping,output,i);
        
        return ans;
    }
};