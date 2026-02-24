class Solution {
public:
    vector<int> getLeftMaxArray(vector<int> &height,int n){
        vector<int> leftmax(n);
        leftmax[0] = height[0];
        for(int i = 1;i<n;i++){
            leftmax[i] = max(leftmax[i-1],height[i]);
        }
        return leftmax;
    }
    vector<int> getRightMaxArray(vector<int> &height,int n){
        vector<int> leftmax(n);
        leftmax[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            leftmax[i] = max(leftmax[i+1],height[i]);
        }
        return leftmax;
    }
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left_max = getLeftMaxArray(height,n);
        vector<int> right_max = getRightMaxArray(height,n);
        int sum = 0;
        for(int i = 0;i<n;i++){
            sum += min(left_max[i],right_max[i])-height[i];; 
        }
        return sum;
    }
};