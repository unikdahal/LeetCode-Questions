class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        
        string w1="";
        string w2="";
        
        for(int i=0;i<word1.size();i++){
            w1=w1+word1[i];
        }
        for(int i=0;i<word2.size();i++){
            w2=w2+word2[i];
        }
        
        int i=0,j=0;
        cout<<w1<<endl;
        cout<<w2<<endl;
        while(i<w1.length()&& j<w2.length()){
            if(w1[i++]==w2[j++]){
                continue;
            }
            return false;
        }
        if(i<w1.length() || j<w2.length()){
            return false;
        }
        return true;
        
    }
};