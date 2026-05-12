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
//PYTHON SOLUTION
class Solution:
    def isPossible(self,tasks: List[List[int]],mid : int)->bool:
        for task in tasks:
            mini = task[1]
            act = task[0]
            if mini>mid:
                return False
            mid = mid - act
        return True
    def minimumEffort(self, tasks: List[List[int]]) -> int:
        left = 0
        right = int(1e9)
        res = int(1e9)
        tasks.sort(key = lambda x: x[1]-x[0],reverse = True)
        while left<=right:
            mid = left + (right-left)//2
            if self.isPossible(tasks,mid):
                res = mid
                right = mid-1
            else:
                left = mid+1
        return res

