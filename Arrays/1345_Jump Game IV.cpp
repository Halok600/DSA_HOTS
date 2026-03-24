class Solution {
public:
    int minJumps(vector<int>& arr) {
        unordered_map<int,vector<int>> mp;
        int n = arr.size();
        vector<bool> visited(n,false);
        for(int i = 0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int res = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                int left = curr-1;
                int right = curr+1;
                if(curr==n-1)
                    return res;
                if(left>=0 && !visited[left]){
                    q.push(left);
                    visited[left] = true;
                }
                if(right<=n-1 && !visited[right]){
                    q.push(right);
                    visited[right] = true;
                }
                for(int &idx : mp[arr[curr]]){
                    q.push(idx);
                    visited[idx] = true;
                }
                mp.erase(arr[curr]);
            }
            res++;
        }
        return -1;
    }
};
