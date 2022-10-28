class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        
        unordered_map<string, vector<string>> check;
        vector<vector<string>> ans;
        
        for(int i=0;i<strs.size();i++){
            string t=strs[i];
            sort(t.begin(),t.end());
            check[t].push_back(strs[i]);
        }
        
        // for(int i=0;i<key.size();i++){
        //     ans.push_back(check[key[i]]);
        // }
        for (auto p : check) { 
            ans.push_back(p.second);
        }
    
        return ans;
    }
};