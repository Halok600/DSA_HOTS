// C++ CODE APPROACH O(n) normal approach will be O(n*log10k) but we just optimize it for the problem in digitSum just find Out the digitSum by normal method
class Solution {
public:
    int digitSum(int n){
        return ((n/10000)+ (n%10000/1000)+(n%1000/100)+(n%100/10)+n%10);
    }
    int minElement(vector<int>& nums) {
        int res = 37;
        for(int &num : nums){
            int s = digitSum(num);
            res = min(s,res);
        }
        return res;
    }
};

// Python CODE

class Solution:
    def digitSum(self,n: int) -> int:
        return ((n//10000)+(n%10000//1000)+(n%1000//100)+(n%100//10)+n%10);
    def minElement(self, nums: List[int]) -> int:
        res = 37
        for num in nums:
            sum = self.digitSum(num)
            res = min(res,sum)
        return res
