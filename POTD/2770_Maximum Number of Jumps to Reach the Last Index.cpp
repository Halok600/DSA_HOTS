//MEMOIZATION CODE C++
class Solution {
public:
    int solve(int idx,vector<int>& nums,int target,vector<int>& t){
        if(idx==nums.size()-1)
            return 0;
        if(t[idx]!=INT_MIN)
            return t[idx];
        int res = INT_MIN;
        for(int j = idx+1;j<nums.size();j++){
            if(abs(nums[j]-nums[idx])<=target){
                int temp = 1+solve(j,nums,target,t);
                res = max(res,temp);
            }

        }
        return t[idx] = res;
    }
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> t(n+1,INT_MIN);
        int res = solve(0,nums,target,t);
        return (res<0) ? -1 : res;
    }
};
