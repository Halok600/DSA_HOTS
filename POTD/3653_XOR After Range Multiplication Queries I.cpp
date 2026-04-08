class Solution {
public:
    int xorAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        const int MOD = 1e9 + 7;
        int n = nums.size();
        int size = queries.size();
        for(int i = 0;i<size;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int k = queries[i][2];
            int v = queries[i][3];
            int idx = l;
            if(idx>n-1)
                continue;
            r = min(n-1,r);
            while(idx<=r){
                nums[idx] = (1LL * nums[idx]*v)%MOD;
                idx += k;
            }

        }
        int x = 0;
        for(int i = 0;i<n;i++){
            x ^= nums[i];
        }
        return x;
    }
};
