class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourangle = hour * 30 + minutes *0.5;
        double minuteAngle = minutes * 6;

        double diff =abs(hourangle - minuteAngle);
        

        return min(diff, 360 - diff);
    }
};