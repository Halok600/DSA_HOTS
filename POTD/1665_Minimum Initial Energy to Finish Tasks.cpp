//C++ SOLUTION HARD
class Solution {
public:
    bool isPossible(vector<vector<int>>&  tasks,int mid){
        int n = tasks.size();
        for(vector<int>& task : tasks){
            int min = task[1];
            int act = task[0];
            if(min>mid)
                return false;
            
            mid -= act;
        }
        return true;
    }
    int minimumEffort(vector<vector<int>>& tasks) {
        int left = 0;
        int n = tasks.size();
        int right = 1e9;
        int res = INT_MAX;
        auto lambda = [](auto &task1,auto &task2){
            int diff1 = task1[1]-task1[0];
            int diff2 = task2[1]-task2[0];
            return diff1>diff2;
        };
        sort(begin(tasks),end(tasks),lambda);
        while(left<=right){
            int mid = left + (right-left)/2;
            if(isPossible(tasks,mid)){
                res = mid;
                right = mid-1;
            }
            else
                left = mid+1;
        }
        return res;
    }
};
