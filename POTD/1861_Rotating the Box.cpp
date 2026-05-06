//BRUTE FORCE APPROACH
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& boxGrid) {
        int m = boxGrid.size();
        int n = boxGrid[0].size();
        vector<vector<char>> res(n,vector<char>(m));
        for(int i = 0;i<n;i++){
            for(int j = 0;j<m;j++)
                res[i][j] = boxGrid[j][i];
        }
        for(vector<char> &x : res)
            reverse(x.begin(),x.end());
        for(int j = 0;j<m;j++){
            for(int i = n-1;i>=0;i--){
                if(res[i][j]=='.'){
                    int stoneRow = -1;
                    for(int k = i-1;k>=0;k--){
                        if(res[k][j]=='*')
                            break;
                        else if(res[k][j]=='#'){
                            stoneRow = k;
                            break;
                        }
                    }
                    if(stoneRow!=-1){
                        res[i][j] = '#';
                        res[stoneRow][j] = '.';
                    }
                }
            }
        }
        return res;
    }
};
