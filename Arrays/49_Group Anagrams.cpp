class Solution {
public:
    string generate(string word){
        int arr[26] = {0};
        for(char & ch : word){
            arr[ch-'a']++;
        }
        string new_word = "";
        for(int i =0; i<26;i++){
            int freq = arr[i];
            if(freq>0){
                new_word+= string(freq,i+'a');
            }
        }
        return new_word;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n = strs.size();
        unordered_map<string,vector<string>> mp;
        vector<vector<string>> res;
        for(int i = 0;i<n;i++){
            string x = strs[i];
            string ans = generate(x);
            mp[ans].push_back(x);
            
        }
        for(auto &x : mp)
            res.push_back(x.second);
        return res;
    }
};