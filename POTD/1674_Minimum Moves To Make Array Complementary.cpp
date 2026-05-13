//C++  SOLUTION COMING SOON
//BRUTE FORCE APPROACH
class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n = nums.size();
        int res = INT_MAX;
        for(int sum = 2;sum<=2*limit;sum++){
            int moves = 0;
            for(int i = 0;i<n/2;i++){
                int a = nums[i];
                int b = nums[n-i-1];
                if(sum==a+b)
                    continue;
                int minVal = min(a,b)+1;
                int maxVal = max(a,b) + limit;
                if(sum<=maxVal && sum>=minVal){
                    moves+=1;
                }
                else
                    moves+=2;
            }
            res = min(res,moves);
        }
        return res;
        
    }
};
