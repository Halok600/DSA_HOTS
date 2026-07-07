//C++ CODE
class Solution {
public:
    long long sumAndMultiply(int n) {
        long long x = 0;
        vector<int> ans;
        long long sum = 0;
        while(n>0){
            if(n%10!=0)
                ans.push_back(n%10);
            sum += (n%10);
            n = n/10;
        }
        reverse(ans.begin(),ans.end());
        for(int i =0;i<ans.size();i++){
            x = x*10 + ans[i];
        }
        long long res = sum*x;
        return res;

    }
};

//PYTHON CODE
class Solution:
    def sumAndMultiply(self, n: int) -> int:
        x = 0
        ans = []
        sum = 0
        while n > 0:
            if n%10!=0:
                ans.append(n%10)
            sum += n%10
            n = n//10
        ans = ans[::-1]
        
        for num in ans:
            x = x*10 + num
        return sum * x
