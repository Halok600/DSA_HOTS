//GETTING T.C but passed 987 test cases/989
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int startZero = 0;
        for(char &ch : s)
            if(ch=='0')
                startZero++;
        queue<int> q;
        if (startZero == 0)
            return 0;
        vector<int> ops(n+1,-1);
        q.push(startZero);
        ops[startZero] = 0;
        while(!q.empty()){
            int z = q.front();
            q.pop();
            int minF = max(0,k-n+z);
            int maxF = min(k,z);
            for(int f = minF;f<=maxF;f++){
                int newZ = z + k - 2*f;
                if(ops[newZ]==-1){
                    ops[newZ] = ops[z]+1;
                    if(newZ==0)
                        return ops[newZ];
                    q.push(newZ);
                }
            }
        }
        return -1;
    }
};
//Correct solution that is submitted|||||
class Solution {
public:
    int minOperations(string s, int k) {
        int n = s.length();
        int startZero = 0;
        for (char& ch : s)
            if (ch == '0')
                startZero++;
        set<int> evenSet;
        set<int> oddSet;
        queue<int> q;
        if (startZero == 0)
            return 0;
        vector<int> ops(n + 1, -1);
        q.push(startZero);
        ops[startZero] = 0;
        for (int i = 0; i <= n; i++) {
            if (i % 2 == 0)
                evenSet.insert(i);
            else
                oddSet.insert(i);
        }
        if (startZero % 2 == 0)
            evenSet.erase(startZero);
        else
            oddSet.erase(startZero);
        while (!q.empty()) {
            int z = q.front();
            q.pop();
            int min_newZ = z + k - 2 * min(z, k);
            int max_newZ = z + k - 2 * max(0, k - n + z);
            set<int>& currSet = (min_newZ % 2 == 0) ? evenSet : oddSet;
            auto it = currSet.lower_bound(min_newZ);
            while (it != currSet.end() && *it <= max_newZ) {
                int newZ = *it;
                if (ops[newZ] == -1) {
                    ops[newZ] = ops[z] + 1;
                    if (newZ == 0)
                        return ops[newZ];
                    q.push(newZ);
                }
                it = currSet.erase(it);
            }
        }
        return -1;
    }
};
