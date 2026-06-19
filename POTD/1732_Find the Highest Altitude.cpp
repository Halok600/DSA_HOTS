//C++ CODE
class Solution {
public:
    int largestAltitude(vector<int>& gain) {

        int begin = gain[0];
        
        int res = max(0,begin);
        for(int i = 1;i<gain.size();i++){
            res = max(res,begin+gain[i]);
            begin = gain[i]+begin;
        }
        return res;
    }
};

//PYTHON CODE
class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        begin = gain[0]
        res = max(0,begin)
        for i in range(1,len(gain)):
            res = max(gain[i]+begin,res)
            begin = gain[i] + begin
        return res
