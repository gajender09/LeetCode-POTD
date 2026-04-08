class Solution {
public:
    bool judgeCircle(string moves) {
        int count1 = 0;
        int count2 = 0;

        for (char ch : moves) {
            if (ch == 'U')
                count1++;
            else if (ch == 'D')
                count1--;
            else if (ch == 'L')
                count2++;
            else if (ch == 'R')
                count2--;
        }

        if (count1 == 0 && count2 == 0)
            return true;

        return false;
    }
};