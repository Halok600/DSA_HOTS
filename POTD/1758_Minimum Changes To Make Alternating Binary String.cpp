//Approach 1
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        string x = "";
        string y = "";
        for(int i = 0;i<n;i++){
            if(i%2==0){
                x+="0";
                y+="1";
            }
            else{
                x+="1";
                y+="0";
            }
        }
        int ops1 = 0;
        int ops2 = 0;

        for(int i = 0;i<n;i++){
            if(s[i]!=x[i]){
                ops1++;
            }
            if(s[i]!=y[i])
                ops2++;
        }
        return min(ops1,ops2);
    }
};

//BETTER Approach saves Space
class Solution {
public:
    int minOperations(string s) {
        int op1 = 0;
        int op2 = 0;
        for(int i = 0;i<s.length();i++){
            if(i%2==0){
                if(s[i]=='1')
                    op2++;
                else
                    op1++;
            }
            else{
                if(s[i]=='0')
                    op2++;
                else
                    op1++;
            }
        }
        return min(op1,op2);
    }
};

//BEST Approach Smallest code
class Solution {
public:
    int minOperations(string s) {
        int n = s.length();
        int res=  0;
        for(int i = 0;i<n;i++){
            if(i%2==0){
                if(s[i]=='0')
                    res++;
            }
            else{
                if(s[i]=='1')
                    res++;
            }
        }
        return min(res,n-res);
    }
};