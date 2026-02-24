class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for(int i = 0;i<n-2;i++){
            if(i>0 && nums[i-1]==nums[i]) continue;
            int low = i+1;
            int high = n-1;
            int sum = 0-nums[i];
            while(low<high){
                int x = nums[low]+nums[high];
                if(x==sum){
                    ans.push_back({nums[i],nums[low],nums[high]});
                    while(low<high && nums[low]==nums[low+1]) low++;
                    while(high>low && nums[high]==nums[high-1]) high--;
                    low++;
                    high--;
                }
                else if(x<sum){
                    low++;
                }
                else
                    high--;
            }
           
        }
         return ans;
    }
};