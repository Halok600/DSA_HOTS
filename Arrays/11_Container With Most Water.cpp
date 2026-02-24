class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int low = 0;
        int high = n-1;
        int res = 0;
        while(low<high){
            int width = high-low;
            int h = min(height[low],height[high]);
            int area = width * h;
            res = max(area,res);
            if(height[low]<height[high])
                low++;
            else 
                high--;
        }
        return res;
    }
};