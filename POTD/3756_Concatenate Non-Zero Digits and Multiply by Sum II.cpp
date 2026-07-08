//C++ CODE
class Solution {
public:
    int M = 1e9+7;
    typedef long long ll;
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n = s.length();
        vector<int> nonZeroCount(n,0);
        vector<long long> numberUpto(n,0);
        vector<ll> digitSumUpto(n,0);
        vector<ll> pow10(n+1,0);
        pow10[0] = 1;
        for(int i = 1;i<=n;i++){
            pow10[i] = (pow10[i-1]*10)%M;
        }
        nonZeroCount[0] = (s[0] != '0') ? 1:0;
        for(int i =1;i<n;i++){
            int digit = s[i]-'0';
            nonZeroCount[i] = nonZeroCount[i-1] + ((digit != 0) ? 1: 0);

        }
        numberUpto[0] = s[0] - '0';
        for(int i = 1;i<n;i++){
            int digit = s[i]-'0';
            if(digit != 0){
                numberUpto[i] = (numberUpto[i-1]*10 + digit)%M;
            }
            else{
                numberUpto[i] = numberUpto[i-1];
            }
        }
        digitSumUpto[0] = s[0]-'0';
        for(int i = 1;i<n;i++){
            int digit = s[i] - '0';
            digitSumUpto[i] = digitSumUpto[i-1]+digit;
        }
        int q = queries.size();
        vector<int> res(q);
        for(int i = 0;i<q;i++){
            int l = queries[i][0];
            int r = queries[i][1];
            int numberBefore = (l == 0) ? 0: numberUpto[l-1];
            ll sum = digitSumUpto[r] - ((l == 0) ? 0: digitSumUpto[l-1]);
            int k = nonZeroCount[r] - ((l==0) ? 0: nonZeroCount[l-1]);
            ll x = (numberUpto[r] - ((numberBefore*pow10[k])%M)+M)%M;
            res[i] = (x*sum)%M;

        }
        return res;
    }
};


//PYTHON CODE 

class Solution:
    MOD = int(1e9+7)
    def sumAndMultiply(self, s: str, queries: List[List[int]]) -> List[int]:
        n = len(s)
        numsUpto = [0]*n
        pow10 = [0]*(n+1)
        nonZeroCount = [0]*n
        digitSumUpto = [0]*n
        pow10[0] = 1
        for i in range(1,n+1):
            pow10[i] = (pow10[i-1]*10)%self.MOD
        numsUpto[0] = int(s[0])
        nonZeroCount[0] = 1 if s[0] != '0' else 0 
        for i in range(1,n):
            dig = int(s[i])
            nonZeroCount[i] = nonZeroCount[i-1] + (1 if s[i]!='0' else 0)
        for i in range(1,n):
            dig = int(s[i])
            if dig != 0:
                numsUpto[i] = (numsUpto[i-1]*10+dig)%self.MOD
            else:
                numsUpto[i] = numsUpto[i-1]
        digitSumUpto[0] = int(s[0])
        for i in range(1,n):
            dig = int(s[i])
            digitSumUpto[i] = digitSumUpto[i-1]+dig 
        
        q = len(queries)
        res = [0]*q
        for i in range(q):
            l = queries[i][0]
            r = queries[i][1]
            numBefore = 0 if l==0 else numsUpto[l-1]
            sum = digitSumUpto[r]-(0 if l==0 else digitSumUpto[l-1])
            k = nonZeroCount[r] - (0 if l==0 else nonZeroCount[l-1])
            x = (numsUpto[r] - ((numBefore*pow10[k])%self.MOD)+self.MOD)%self.MOD
            res[i] = (x*sum)%self.MOD

        return res

