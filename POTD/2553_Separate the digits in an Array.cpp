//SOLVED TODAY PROBLEM CPP
class Solution {
public:
    vector<int> separateDigits(vector<int>& nums) {
        vector<int> res;
        for(int& val : nums){
            string s = to_string(val);
            for(char c : s){
                res.push_back(c-'0');
            }
        }
        return res;
    }
};
