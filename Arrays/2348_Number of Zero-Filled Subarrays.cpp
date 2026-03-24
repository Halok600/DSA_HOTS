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
//Approach 2
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0;
        int i = 0;
        int n = nums.size();
        while(i<n){
            long long x = 0;
            if(nums[i]==0){
                int start = i;
                while(i<n && nums[i]==0){
                    x += i-start + 1;
                    i++;
                }
            }
            else
                i++;
            ans += x;
        }
        return ans;
    }
};

//Why did not I guess this || Approach 3 (Best ez code)
class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size();
        long long res = 0;
        int count = 0;
        for(int i = 0;i<n;i++){
            if(nums[i]==0){
                count++;
            }
            else
                count = 0;
            res += count;
        }
        return res;
    }
};
