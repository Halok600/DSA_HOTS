// C++ SOLUTIOn

class Solution {
public:
    string mapWordWeights(vector<string>& words, vector<int>& weights) {
        string ans = "";
        for(string & x : words){
            int sum = 0;
            int size = x.length();
            for(int i = 0;i<size;i++){
                int idx = x[i] - 'a';
                sum += weights[idx];
            }
            sum = sum%26;
            ans += 'z'-sum;
        }
        return ans;
    }
};

//Python SOLUTION
class Solution:
    def mapWordWeights(self, words: List[str], weights: List[int]) -> str:
        ans = []
        for word in words:
            total_sum = 0
            for c in word:
                idx = ord(c) - ord('a')
                total_sum += weights[idx]
            total_sum = total_sum%26
            char_fin = chr(ord('z')-total_sum)
            ans.append(char_fin)
        
        return "".join(ans)
