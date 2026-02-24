class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        int select = -1;
        for (int i = n - 1; i > 0; i--) {
            if (nums[i - 1] < nums[i]) {
                select = i - 1;
                break;
            }
        }

        if (select != -1) {
            int swap_index = select + 1;
            for (int j = n - 1; j > select; j--) {
                if (nums[j] > nums[select]) {
                    swap_index = j;
                    break;
                }
            }

            swap(nums[select], nums[swap_index]);
        }
        reverse(nums.begin() + select + 1, nums.end());
    }
};