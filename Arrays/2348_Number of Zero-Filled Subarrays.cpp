//Approach 1 n*(n+1)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int n = nums.size();
        long long start = -1;
        for(long long i = 0;i<n;i++){
            if(nums[i]==0){
                start = i;
                while(i<n && nums[i]==0)
                    i++;
                ans += (i-start)*(i-start+1)/2;
            }
        }
        return ans;

    }
};
