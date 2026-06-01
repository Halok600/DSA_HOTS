//C++ Approach with TC O(nLogn)
class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end(),greater<int>());
        int min_cost = 0;
        int i = 0;
        int n = cost.size();
        
        while(i<n){
            if((i+1)%3!=0)
                min_cost += cost[i];
            i++;
            
        }
        return min_cost;
    }
};

//Python
class Solution:
    def minimumCost(self, cost: List[int]) -> int:
        cost.sort(reverse = True)
        min_cost = 0
        for i in range(len(cost)):
            if (i+1)%3!=0:
                min_cost+=cost[i]
        return min_cost
