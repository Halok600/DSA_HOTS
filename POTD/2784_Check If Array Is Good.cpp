//C++ solution

class Solution {
public:
    bool isGood(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int size = nums.size();
        int n = size-1;
        int last = nums[size-1];
        for(int i = 0;i<size-1;i++){
            if(i+1 == nums[i])
                continue;
            else
                return false;
        }
        if(nums[size-1]==n)
            return true;
        return false;
    }
};

//PYTHON SOLUTION
class Solution:
    def isGood(self, nums: List[int]) -> bool:
        size = len(nums)
        n = size-1
        nums.sort()
        for i in range(size-1):
            if i+1 == nums[i]:
                continue
            else:
                return False
        if n == nums[size-1]:
            return True
        return False
                
