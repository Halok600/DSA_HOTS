// C++ SOLUTION STORED
class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        vector<int> ans(n);
        int idx = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]<pivot){
                ans[idx] = nums[i];
                idx++;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]==pivot){
                ans[idx] = nums[i];
                idx++;
            }
        }
        for(int i = 0;i<n;i++){
            if(nums[i]>pivot){
                ans[idx] = nums[i];
                idx++;
            }
        }
        return ans;
    }
};

// PYTHON SOLUTION
class Solution:
    def pivotArray(self, nums: List[int], pivot: int) -> List[int]:
        n = len(nums)
        ans = [0]*n
        idx = 0
        for i in range(n):
            if nums[i]<pivot:
                ans[idx] = nums[i]
                idx += 1
        for i in range(n):
            if nums[i]==pivot:
                ans[idx] = nums[i]
                idx += 1
        for i in range(n):
            if nums[i]> pivot:
                ans[idx] = nums[i]
                idx+=1

        return ans
