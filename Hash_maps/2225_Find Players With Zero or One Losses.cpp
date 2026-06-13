//C++ Solution
class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> res(1e5+1,-1);
        for(auto& match : matches){
            if(res[match[0]] == -1){
                res[match[0]] = 0;
            }
            if(res[match[1]] == -1)
                res[match[1]] = 1;
            else 
                res[match[1]]++;
        }
        vector<int> zeroLoss;
        vector<int> oneLoss;
        for(int i = 0;i<1e5+1;i++){
            if(res[i] == 0)
                zeroLoss.push_back(i);
            if(res[i]==1){
                oneLoss.push_back(i);
            }
        }
        return {zeroLoss,oneLoss};
    }
};

//Python SOlution
class Solution:
    def findWinners(self, matches: List[List[int]]) -> List[List[int]]:
        res = [-1]*(100001)
        for winner, loser in matches:
            if res[winner] == -1:
                res[winner] = 0
            if res[loser] == -1:
                res[loser] = 1
            else:
                res[loser] += 1
        zeroLoss = []
        oneLoss = []
        for i in range(100001):
            if res[i] == 0:
                zeroLoss.append(i)
            if res[i] == 1:
                oneLoss.append(i)
        return [zeroLoss,oneLoss]
        
