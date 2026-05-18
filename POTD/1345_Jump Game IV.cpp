//C++ Approach
class Solution {
public:
    int minJumps(vector<int>& arr) {
        int n = arr.size();
        int lastIndex = n-1;
        unordered_map<int,vector<int>> mp;
        vector<bool> visited(n,false);
        for(int i = 0;i<n;i++){
            mp[arr[i]].push_back(i);
        }
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int steps = 0;
        while(!q.empty()){
            int size = q.size();
            while(size--){
                int curr = q.front();
                q.pop();
                int left = curr-1;
                int right = curr+1;
                if(curr==n-1)
                    return steps;
                if(left>=0 && visited[left]==false){
                    q.push(left);
                    visited[left] = true;
                }    
                if(right<n && visited[right]==false){
                    q.push(right);
                    visited[right] = true;
                }
                for(int &idx : mp[arr[curr]]){
                    if(!visited[idx]){
                        q.push(idx);
                        visited[idx] = true;
                    }

                }
                mp.erase(arr[curr]);
                
            }
            steps++;
        }
        return -1;


    }
};


//Python Approach
class Solution:
    def minJumps(self, arr: List[int]) -> int:
        n = len(arr)
        if(n<=1):
            return 0
        mp = defaultdict(list)
        for i, val in enumerate(arr):
            mp[val].append(i)
        visited = [False]*n
        queue = deque([0])
        visited[0] = True
        steps = 0
        while queue:
            for _ in range(len(queue)):
                curr = queue.popleft()
                if curr == n-1:
                    return steps
                left = curr-1
                right = curr+1
                if left>=0 and visited[left] == False:
                    queue.append(left)
                    visited[left] = True
                if right<n and visited[right] == False:
                    queue.append(right)
                    visited[right] = True
                for idx in mp[arr[curr]]:
                    if not visited[idx]:
                        queue.append(idx)
                        visited[idx] = True
                del mp[arr[curr]]
            steps += 1
        return -1

