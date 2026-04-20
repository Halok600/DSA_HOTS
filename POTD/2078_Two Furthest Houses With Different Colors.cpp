//SOLUTION 1 With 2 passes

class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int res = 1;
        int start = 0;
        int end = colors.size()-1;
        while(colors[start]==colors[end])
            start++;
        res = max(res,end-start);
        start = 0;
        while(colors[start]==colors[end])
            end--;
        res = max(res,end-start);
        return res;
    }
};

//SOLUTION 2 WITH 1 PASS
class Solution {
public:
    int maxDistance(vector<int>& colors) {
        int n = colors.size();
        int res = 0;
        for(int i = 0;i<n;i++){
            if(colors[0]!=colors[i])
                res = max(res,i);
            if(colors[i]!=colors[n-1])
                res = max(res,n-1-i);
        }
        return res;
    }
};
