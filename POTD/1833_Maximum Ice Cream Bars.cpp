//C++ CODE

class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(),costs.end());
        int res = 0;
        for(int i=0;i<costs.size();i++){
            if(coins>=costs[i]){
                coins-=costs[i];
                res++;
            }
        }
        return res;
    }
};

// PYTHON CODE

class Solution:
    def maxIceCream(self, costs: List[int], coins: int) -> int:
        costs.sort()
        res = 0
        for x in costs:
            if coins>=x:
                coins -=x
                res+=1
        return res
