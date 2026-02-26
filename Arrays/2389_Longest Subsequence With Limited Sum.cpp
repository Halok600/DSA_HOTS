//MY APPROACH O(N^2)
class Solution {
public:
    vector<int> answerQueries(vector<int>& nums, vector<int>& queries) {
        sort(nums.begin(),nums.end());
        int n = nums.size();
        vector<int> res;
        int m = queries.size();
        int sum = 0;
        for(int &num : nums)
            sum+= num;
        for(int i = 0;i<m;i++){
            int x = queries[i];
            int sumNums = 0;
            if(sum<x){
                res.push_back(n);

            }
            else if(nums[0]>x)
                res.push_back(0);
            else{
                for(int j = 0;j<n;j++){
                    sumNums+=nums[j];
                    if(sumNums>x){
                        res.push_back(j);
                        break;
                    }
                    else if(sumNums==x){
                        res.push_back(j+1);
                        break;
                    }
                }
            }
        }
        return res;
    }
};