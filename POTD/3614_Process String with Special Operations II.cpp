// C++ SOLUTION ::
//HARD PROBLEM BE LOGICAL
class Solution {
public:
    char processStr(string s, long long k) {
        int n = s.length();
        long long L = 0;
        for(char& ch: s){
            if(ch == '*'){
                if(L>0)
                    L--;
            }
            else if(ch == '#')
                L = L*2;
            else if(ch == '%')
                continue;
            else{
                L++;
            }
        }
        if(k>= L)
            return '.';
        for(int i = n-1;i>=0;i--){
            if(s[i] == '*')
                L++;
            else if(s[i] == '%'){
                k = L-k-1;
            }
            else if(s[i] == '#'){
                L = L/2;
                k = (k>=L) ? k-L : k;
            }
            else{
                L--;
            }
            if(k==L)
                return s[i];
        }
        return '.';
    }
};


//PYTHON SOLUTION
class Solution:
    def processStr(self, s: str, k: int) -> str:
        n = len(s)
        L = 0
        for ch in s:
            if ch == '*':
                if L>0:
                    L-=1
            elif ch == '%':
                continue
            elif ch == '#':
                L = L*2
            else:
                L+=1
        if k>=L:
            return '.'
        for i in range(n-1,-1,-1):
            if s[i] == '*':
                L += 1
            elif s[i] == '%':
                k = L-k-1
            elif s[i] == '#':
                L = L//2
                if k>=L:
                    k = k-L
            else:
                L-=1
            if k==L:
                return s[i]
        return '.'
