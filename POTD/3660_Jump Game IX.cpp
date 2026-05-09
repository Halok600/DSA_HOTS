//SOLVED USING C++ T.C O(n)
class Solution {
public:
    vector<int> maxValue(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxLeft(nums.size());
        vector<int> minRight(nums.size());
        maxLeft[0] = nums[0];
        minRight[n-1] = nums[n-1];
        for(int i = 1;i<n;i++){
            maxLeft[i] = max(nums[i],maxLeft[i-1]);
        }
        for(int i = n-2;i>=0;i--){
            minRight[i] = min(nums[i],minRight[i+1]);
        }
        vector<int> ans(n);
        ans[n-1] = maxLeft[n-1];
        for(int i = n-2;i>=0;i--){
            if(maxLeft[i]<=minRight[i+1])
                ans[i] = maxLeft[i];
            else
                ans[i] = ans[i+1];
        }
        return ans;
    }
};

//python solution
class Solution:
    def maxValue(self, nums: List[int]) -> List[int]:
        n = len(nums)
        maxLeft = [0]*n
        minRight = [0]*n
        maxLeft[0] = nums[0]
        minRight[n-1] = nums[n-1]

        for i in range(1,n):
            maxLeft[i] = max(maxLeft[i-1],nums[i])
        for i in range(n-2,-1,-1):
            minRight[i] = min(minRight[i+1],nums[i])
        ans = [0]*n
        ans[n-1] = maxLeft[n-1]
        for i in range(n-2,-1,-1):
            if maxLeft[i]<=minRight[i+1]:
                ans[i] = maxLeft[i]
            else:
                ans[i] = ans[i+1]
        return ans
