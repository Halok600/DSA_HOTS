class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        vector<int> res;
        int m = mat.size();
        int n = mat[0].size();
        map<int, vector<int>> mp;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                mp[i + j].push_back(mat[i][j]);
            }
        }
        bool flip = true;
        for (auto& x : mp) {
            if (flip) {
                reverse(x.second.begin(), x.second.end());
            }
            flip = !flip ;
            for (int& num : x.second) { res.push_back(num); }
        }
        return res;
    }
};