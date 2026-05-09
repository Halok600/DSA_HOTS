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

// PYTHON SOLUTION
class Solution:
    def rotateGrid(self, grid: List[List[int]], k: int) -> List[List[int]]:
        m = len(grid)
        n = len(grid[0])
        layers = min(m//2,n//2)
        for layer in range(layers):
            nums = []
            left,top = layer,layer
            bottom,right = m-layer-1,n-layer-1
            #From (TOP) left to right
            for j in range(left,right+1):
                nums.append(grid[top][j])
            #From (Right) top to bottom
            for i in range(top+1,bottom):
                nums.append(grid[i][right])
            #From (BOTTOM) right to left
            for j in range(right,left-1,-1):
                nums.append(grid[bottom][j])
            #FROM (left) bottom to top
            for i in range(bottom-1,top,-1):
                nums.append(grid[i][left])
            size = len(nums)
            newK = k%size
            nums = nums[newK:] + nums[:newK]
            idx = 0
            # top (LEFT->RIGHT)
            for j in range(left,right+1):
                grid[top][j] = nums[idx]
                idx+=1
            #right (TOP->BOTTOM)
            for i in range(top+1,bottom):
                grid[i][right] = nums[idx]
                idx+=1
            #bottom (RIGHT->LEFT)
            for j in range(right,left-1,-1):
                grid[bottom][j] = nums[idx]
                idx+=1
            #left (BOTTOM->TOP)
            for i in range(bottom-1,top,-1):
                grid[i][left] = nums[idx]
                idx+=1
        return grid        
