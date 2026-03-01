//SOLVING THE PROBLEM USING LOG2(_)

class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int MOD = 1e9 + 7;
        for(int i = 1;i<=n;i++){
            int digits = log2(i)+1;
            res = (((res<<digits)%MOD)+i)%MOD;
        }
        return (int)res;
    }
};

//WITHOUT USING LOG
class Solution {
public:
    int concatenatedBinary(int n) {
        long long res = 0;
        int MOD = 1e9 +7;
        int digits = 0;
        for(int num = 1;num<=n;num++){
            if((num&(num-1))==0){
                digits++;
            }
            res = ((res<<digits)%MOD+num)%MOD;
        }
        return (int)res;
    }
};