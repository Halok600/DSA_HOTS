class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int left = 0;
        int right = m-1;
        int bottom = n-1;
        int top = 0;
        int dir = 0;
        vector<int> res;
        while(top<=bottom && left<=right){
            if(dir==0){
                for(int i = left;i<=right;i++){
                    res.push_back(matrix[top][i]);
                }
                top++;
            }
            else if(dir==1){
                for(int i = top;i<=bottom;i++)
                    res.push_back(matrix[i][right]);
                right--;
            }
            else if(dir==2){
                for(int i = right;i>=left;i--){
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }
            else{
                for(int i = bottom;i>=top;i--)
                    res.push_back(matrix[i][left]);
                left++;
            }
            dir++;
            if(dir>=4)
                dir = dir%4;

        }
        return res;
    }
};