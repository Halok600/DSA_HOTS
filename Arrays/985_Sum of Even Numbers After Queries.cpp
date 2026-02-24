class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        int n = queries.size();
        int sum = 0;
        for(int &num : nums){
            if(num%2==0)
                sum+=num;
        }
        vector<int> res;
        for(int i = 0;i<n;i++){
            int index = queries[i][1];
           
            if(nums[index]%2!=0){
                nums[index]+=queries[i][0];
                if(nums[index]%2==0)
                    sum+=nums[index];
            }
            else{
                sum-=nums[index];
                nums[index]+=queries[i][0];
                if(nums[index]%2==0)
                    sum+=nums[index];
            }
            res.push_back(sum);
        }
        return res;
    }
};