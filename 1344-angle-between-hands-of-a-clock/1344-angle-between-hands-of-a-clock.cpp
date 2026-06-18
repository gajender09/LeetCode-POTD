class Solution {
public:
    double angleClock(int hour, int minutes) {

        double hourSection = double(minutes) / 12;

        double start = (hour == 12) ? 0 * 5 + hourSection : hour * 5 + hourSection;

        double diff = abs(minutes - start);

        double angle = diff * 6;

        return angle > 180 ? 360 - angle : angle;
    }
};