//C++ CODE SOLUTION:
class Solution {
public:
    string processStr(string s) {
        string res = "";
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i] >= 'a' && s[i]<='z'){
                res += s[i];
            }
            else if(s[i] == '#'){
                res += res;
            }
            else if(s[i] == '*'){
                int l = res.length();
                if(l == 0)
                    continue;
                res.erase(l-1,1);
            }
            else if(s[i] == '%')
                reverse(res.begin(),res.end());
        }
        return res;
    }
};

// Python Solution
class Solution:
    def processStr(self, s: str) -> str:
        res = ""
        for ch in s:
            if 'a'<=ch<='z':
                res = res + ch
            elif ch == '#':
                res = res + res
            elif ch == '*':
                if len(res)>0:
                    res = res[:-1]
            elif ch == '%':
                res = res[::-1]
        return res
