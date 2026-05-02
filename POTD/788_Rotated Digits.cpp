//Approach 1
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
