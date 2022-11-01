class Solution {

public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        
        int n=matrix.size();
        int m=matrix[0].size();
        if(n<2 || m<2){
            return 1;
        }
        for(int i=1;i<n;i++){
            for(int j=1;j<m;j++){
                if(matrix[i][j]!=matrix[i-1][j-1]){
                    return 0;
                }
            }
        }
        return true;
        
    }
};