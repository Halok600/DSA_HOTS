//APPROACH 1 
class Solution {
public:
    int binaryToNum(string x){
        int n = x.length();
        int num = 0;
        reverse(x.begin(),x.end());
        for(int i = 0;i<n;i++){
            if(x[i]=='1')
                num += pow(2,i);
        }
        return num;
    }
    string findDifferentBinaryString(vector<string>& nums) {
        int n = nums[0].length();
        unordered_set<int> st;
        for(int i = 0;i<nums.size();i++){
            int x = binaryToNum(nums[i]);
            st.insert(x);
        }
        for(int i = 0;i<=pow(2,n)-1;i++){
            if(st.find(i)==st.end()){
                string temp = bitset<16>(i).to_string();
                return temp.substr(16-n,n);
            }
        }
        return "";
    }
};