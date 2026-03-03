//Brute force (Time Limit Exceeded)
class Solution {
public:
    int kadane(vector<int> &nums){
        int global = nums[0];
        int n = nums.size();
        int curr_max = nums[0];
        for(int i = 1;i<n;i++){
            curr_max = max(nums[i],curr_max+nums[i]);
            global = max(curr_max,global);
        }
        return global;
    }
    void leftRotate(vector<int>& nums){
        int n = nums.size();
        int tem = nums[0];
        for(int i = 1;i<n;i++)
            nums[i-1] = nums[i];
        nums[n-1] = tem;
    }
    int maxSubarraySumCircular(vector<int>& nums) {
        int n = nums.size();
        int maxi = kadane(nums);
        for(int i = 1;i<n;i++){
            leftRotate(nums);
            maxi = max(maxi,kadane(nums));
        }
        return maxi;
    }
};