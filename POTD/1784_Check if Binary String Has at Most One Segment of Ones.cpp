class Solution {
public:
    bool checkOnesSegment(string s) {
        int i = 0;
        int n = s.length();
        while(s[i]=='1' && i<n)
            i++;
        if(i==n-1)
            return true;
        for(i=i+1;i<n;i++){
            if(s[i]=='1')
                return false;
        }
        return true;
    }
};