// CPP CODE


class Solution {
public:
    vector<vector<int>> rotateGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size();
        int n = grid[0].size();
        int layers = min(n/2,m/2);
        for(int layer = 0;layer<layers;layer++){
            vector<int> nums;
            int left = layer;
            int top = layer;
            int right = n-layer-1;
            int bottom = m-layer-1;
            //TopLeft to TopRight
            for(int j = left;j<=right;j++){
                nums.push_back(grid[top][j]);
            }
            //TOPright to bottom right
            for(int i = top+1;i<=bottom-1;i++){
                nums.push_back(grid[i][right]);
            }
            // bottomRight to bottomLeft
            for(int j = right;j>=left;j--)
                nums.push_back(grid[bottom][j]);
            // bottomLeft to topLeft
            for(int i = bottom-1;i>=top+1;i--)
                nums.push_back(grid[i][left]);
            int size = nums.size();
            int newK = k%size;
            rotate(begin(nums),begin(nums)+newK,end(nums));
            int idx = 0;
            //TopLeft to TopRight
            for(int j = left;j<=right;j++){
                grid[top][j] = nums[idx++];
            }
            //TOPright to bottom right
            for(int i = top+1;i<=bottom-1;i++){
                grid[i][right] = nums[idx++];
            }
            // bottomRight to bottomLeft
            for(int j = right;j>=left;j--)
               grid[bottom][j] = nums[idx++];
            // bottomLeft to topLeft
            for(int i = bottom-1;i>=top+1;i--)
                grid[i][left] = nums[idx++];

        }
        return grid;
    }
};
