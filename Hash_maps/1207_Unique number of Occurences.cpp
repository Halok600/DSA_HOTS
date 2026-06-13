//C++ Code
class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        unordered_map<int,int> mp;
        for(int &x : arr)
            mp[x]++;
        unordered_set<int> seen_freq;
        for(auto &it : mp){
            int freq = it.second;
            if(seen_freq.find(freq) != seen_freq.end())
                return false;
            seen_freq.insert(freq);
        }
        return true;
    }
};

//Python Equivalent
class Solution(object):
    def uniqueOccurrences(self, arr):
        """
        :type arr: List[int]
        :rtype: bool
        """
        mp = Counter(arr)
        seen_freq = set()
        for freq in mp.values():
            if freq in seen_freq:
                return False
            seen_freq.add(freq)
        return True
