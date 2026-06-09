//C++ solution 
class Solution {
public:
    long long maxTotalValue(vector<int>& nums, int k) {
        int mini = INT_MAX;
        int maxi = INT_MIN;
        for(int & num: nums){
            maxi = max(maxi,num);
            mini = min(mini,num);
        }
        long long res = (long long)k*(maxi-mini);
        return res;
    }
};

//PYTHON SOLUTION
class Solution:
    def maxTotalValue(self, nums: List[int], k: int) -> int:
        minEl = 1e13
        maxEl = -1e13
        for num in nums:
            minEl = min(num,minEl)
            maxEl = max(num,maxEl)
        return k * (maxEl-minEl)
