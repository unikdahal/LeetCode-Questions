class Solution {
public:
    bool checkIfPangram(string sentence) {
        bool arr[26]={false};
        
        for(int i=0;i<sentence.length();i++){
            int value=sentence[i]-'a';
            arr[value]=true;
        }
        
        for(int i=0;i<26;i++){
            if(arr[i]==false){
                return false;
            }
        }
        return true;
    }
};