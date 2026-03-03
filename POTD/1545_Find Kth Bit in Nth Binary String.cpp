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