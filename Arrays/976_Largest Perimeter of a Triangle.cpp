class Solution {
public:
    bool isTriangle(int a,int b,int c){
        if((a+b<=c) || (a+c<=b) || (b+c<=a))
            return false;
        else
            return true;
        
    }
    int largestPerimeter(vector<int>& nums) {
        sort(nums.begin(),nums.end(),greater<int>());
        for(int i = 2;i<nums.size();i++){
            if(isTriangle(nums[i-2],nums[i-1],nums[i]))
                return nums[i-2]+nums[i-1]+nums[i];
        }
        return 0;
    }
};