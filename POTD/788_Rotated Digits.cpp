//Approach 1 C++
class Solution {
public:
    bool isGood(int n){
        bool change = false;
        while(n>0){
            int dig = n%10;
            if(dig==3 || dig==4 || dig==7)  
                return false;
            if(dig==2 || dig == 5 || dig == 6 || dig == 9)
                change = true;
            n = n/10;
        }
        return change;
    }
    int rotatedDigits(int n) {
        int res = 0;
        for(int i = 1;i<=n;i++){
            if(isGood(i))
                res++;
        }
        return res;
    }
};
// Python
class Solution:
    def isGood(self,n: int)->bool:
        change = False
        while n>0 :
            dig = n%10
            if dig == 3 or dig == 4 or dig == 7:
                return False
            if dig == 2 or dig == 5 or dig == 6 or dig == 9:
                change = True
            n = n//10
        return change

    def rotatedDigits(self, n: int) -> int:
        res = 0
        for i in range(1,n+1):
            if self.isGood(i):
                res+=1
        return res
