//C++ Solution
class Solution {
public:
    double angleClock(int hour, int minutes) {
        
        double x = double(abs(11*minutes-60*hour))/2;
        if(x>180){
            x = 360-x;
        }
        return x;
    }
};
//Python Solution
class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        x = abs(11*minutes-60*hour)/2
        if x>180:
            x = 360-x
        return x
