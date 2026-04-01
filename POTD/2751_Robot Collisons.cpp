class Solution {
public:
    vector<int> survivedRobotsHealths(vector<int>& positions, vector<int>& healths, string directions) {
        int n = positions.size();
        vector<int> actual_index(n);
        iota(begin(actual_index),end(actual_index),0);
        auto lambda = [&](int i,int j){
            if(positions[i]<positions[j])
                return true;
            else
                return false;
        };
        sort(actual_index.begin(),actual_index.end(),lambda);
        stack<int> st;
        for(int& currIdx : actual_index){
            if(directions[currIdx]=='R'){
                st.push(currIdx);
            }
            else{
                while(!st.empty() && healths[currIdx]>0){
                    int topIdx = st.top();
                    st.pop();
                    if(healths[topIdx]>healths[currIdx]){
                        healths[topIdx]-=1;
                        healths[currIdx]=0;
                        st.push(topIdx);
                    }
                    else if(healths[topIdx]<healths[currIdx]){
                        healths[topIdx] = 0;
                        healths[currIdx]-=1;
                    }
                    else{
                        healths[topIdx] = 0;
                        healths[currIdx] = 0;
                    }

                }
            }
        }
        vector<int> res;
        for(int i = 0;i<n;i++){
            if(healths[i]>0)
                res.push_back(healths[i]);
        }
        return res;
    }
};
