class Solution {
public:
    bool canPartitionGrid(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<long long> row(m,0);
        vector<long long> col(n,0);
        long long total_sum = 0;
        for(int i = 0;i<m;i++){
            for(int j = 0;j<n;j++){
                int x = grid[i][j];
                total_sum += x;
                row[i] += x;
                col[j] += x;
            }
        }
        if(total_sum%2!=0)
            return false;
        long long upper = 0;
        for(int i = 0;i<m-1;i++){
            upper += row[i];
            if(upper==total_sum-upper)
                return true;
        }
        long long left = 0;
        for(int i = 0;i<n-1;i++){
            left += col[i];
            if(left == total_sum-left)
                return true;
        }
        return false;
    }
};
