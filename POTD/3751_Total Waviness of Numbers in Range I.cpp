//C++ CODE

class Solution {
public:
    vector<int> solve(int n){
        vector<int> res;
        while(n>0){
            res.push_back(n%10);
            n = n/10;
        }
        reverse(res.begin(),res.end());
        return res;
    }
    int totalWaviness(int num1, int num2) {
        int ans = 0;
        for(int num = num1 ; num<=num2;num++){
            vector<int> x = solve(num);
            int n = x.size();
            
            if(n<3)
                continue;
            else{
                for(int i = 1;i<n-1;i++){
                    if((x[i-1]>x[i] && x[i]<x[i+1]) || (x[i-1]<x[i] && x[i]>x[i+1])){
                        ans++;
                    }
                }
            }
        }
        return ans;
    }
};

//DP solution NOT DONE AS I DONT KNOW DP

// PYTHON SOLUTION
class Solution:
    def solve(self, n : int) -> list:
        res = []
        while n>0:
            res.append(n%10)
            n = n//10
        return res
    def totalWaviness(self, num1: int, num2: int) -> int:
        res = 0
        for num in range(num1,num2+1):
            x = self.solve(num)
            n = len(x)
            if n < 3:
                continue
            else:
                for i in range(1,n-1):
                    if (x[i-1]>x[i] and x[i+1]>x[i]) or (x[i-1]<x[i] and x[i+1]<x[i]):
                        res += 1
        return res
