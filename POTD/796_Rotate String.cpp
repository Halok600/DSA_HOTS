//SOLVED APPROACH 1 CPP
class Solution {
public:
    bool rotateString(string s, string goal) {
        string res = s + s;
        if(s.length()!=goal.length())
            return false;
        if(res.contains(goal))
            return true;
        return false;

    }
};
//SOLVED APPROACH 2 PYTHON
class Solution:
    def rotateString(self, s: str, goal: str) -> bool:
        res = s + s
        if len(s) != len(goal):
            return False
        if goal in res:
            return True
        return False
