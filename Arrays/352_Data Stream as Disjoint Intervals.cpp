//BASIC Solution (KIND OF BRUTE FORCE)
// Space O(n) and T.C O(nlogn)
class SummaryRanges {
public:
    unordered_set<int> st;
    SummaryRanges() {
        st.clear();
    }
    
    void addNum(int value) {
        st.insert(value);
    }
    
    vector<vector<int>> getIntervals() {
        vector<int> nums(begin(st),end(st));
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        int n = nums.size();
        for(int i = 0;i<n;i++){
            int left = nums[i];
            while(i<n-1 && nums[i]+1==nums[i+1])
                i++;
            res.push_back({left,nums[i]});
        }
        return res;
    }
};

