//c++ Solution
class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            int countMajor = 0;
            for(int j = i;j<n;j++){
                if(nums[j] == target)
                    countMajor++;
                if((j-i+1)/2<countMajor)
                    res++;
            }
            
        } 
        return res;
    }
};

//PYTHON SOLUTION
class Solution:
    def countMajoritySubarrays(self, nums: List[int], target: int) -> int:
        n = len(nums)
        res = 0
        for i in range(n):
            countMajor = 0
            for j in range(i,n):
                if target == nums[j]:
                    countMajor += 1
                if (j-i+1)//2 < countMajor:
                    res+=1
        return res
