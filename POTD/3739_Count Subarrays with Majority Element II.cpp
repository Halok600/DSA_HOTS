class Solution {
public:
    long long countMajoritySubarrays(vector<int>& nums, int target) {
        long long res = 0;
        int n = nums.size();
        long long cumSum = 0;
        unordered_map<long long, int> mp;
        mp[0] = 1;
        long long validLeft = 0;
        for(int i =0;i<n;i++){
            
            if(target == nums[i]){
                validLeft += mp[cumSum];
                cumSum += 1;
            }
            else{
                cumSum -=1 ;
                validLeft -= mp[cumSum];
            }
            mp[cumSum] += 1;
            res += validLeft;
        }
        return res;
    }
};

//Python SOlution
class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        res = 0
        n = len(nums)
        cumSum = 0
        mp = defaultdict(int)
        mp[0] = 1
        validLeft = 0
        for i in range(n):
            if target == nums[i]:
                validLeft += mp[cumSum]
                cumSum += 1
            else:
                cumSum -= 1
                validLeft -= mp[cumSum]

            mp[cumSum] += 1
            res += validLeft

        return res
