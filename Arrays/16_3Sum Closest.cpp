class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(),nums.end());
        int ans = 100000;
        for(int i = 0;i<n-2;i++){
            int low = i+1;
            int high = n-1;
            while(low<high){
                int sum = nums[low]+nums[high]+nums[i];
                if(abs(target-sum)<abs(target-ans)){
                    ans = sum;
                }
                if(sum<target)
                    low++;
                else
                    high--;
                
            }
        }
        return ans;
    }
};