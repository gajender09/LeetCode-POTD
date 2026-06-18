class Solution {
public:
    double angleClock(int hour, int minutes) {

        // minute hand angle
        double minuteAngle = minutes * 6;

        // hour hand angle
        double hourAngle = (hour % 12) * 30 + minutes * 0.5;

        double diff = abs(hourAngle - minuteAngle);

        return min(diff, 360 - diff);
    }
};