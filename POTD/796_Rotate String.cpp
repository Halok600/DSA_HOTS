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
