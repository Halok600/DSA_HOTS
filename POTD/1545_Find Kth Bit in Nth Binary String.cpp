// Done with basic Approach
class Solution {
public:
    string invert(string s){
        int n = s.length();
        for(int i = 0;i<n;i++){
            if(s[i]=='1')
                s[i] = '0';
            else
                s[i] = '1';
        }
        return s;

    }
    char findKthBit(int n, int k) {
        vector<string> x(n,"");
        x[0] += "0";
        
        for(int i = 1;i<n;i++){
            string inverted = invert(x[i-1]);
            reverse(inverted.begin(),inverted.end());
            x[i] = x[i-1] + "1" + inverted;
        }
        return x[n-1][k-1];
    }
};

// Optimized Recursive Approach
class Solution {
public:
    char findKthBit(int n, int k) {
        int len = pow(2,n)-1;
        if(n==1)
            return '0';
        if(k<ceil(len/2.0))
            return findKthBit(n-1,k);
        else if(k==ceil(len/2.0))
            return '1';
        else{
            char ch = findKthBit(n-1,len-(k-1));
            if(ch=='0')
                return '1';
            else
                return '0';
        }
    }
};