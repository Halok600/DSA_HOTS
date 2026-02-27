class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        int n = points.size();
        int prevSP = points[0][0];
        int prevEP = points[0][1];
        int arrows = 1;
        for(int i = 1;i<n;i++){
            int currSP = points[i][0];
            int currEP = points[i][1];
            if(currSP>prevEP){
                prevSP = currSP;
                prevEP = currEP;
                arrows++;
            }
            else{
                prevSP = max(currSP,prevSP);
                prevEP = min(currEP,prevEP);
            }
        }
        return arrows;
    }
};