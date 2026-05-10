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

//PYTHON MEMO SOLUTION
class Solution:
    def maximumJumps(self, nums: List[int], target: int) -> int:
        n = len(nums)
        memo = [-10**9]*n
        def solve(idx):
            if idx == n-1:
                return 0
            if memo[idx]!=-10**9:
                return memo[idx]
            res = -10**9
            for j in range(idx+1,n):
                if abs(nums[j]-nums[idx])<=target:
                    temp = 1+solve(j)
                    res = max(res,temp)
            memo[idx] = res
            return memo[idx]
        res = solve(0)
        return res if res>=0 else -1
