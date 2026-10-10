
class Solution {
public:
    int minInsertions(string s) {
        int open = 0, close = 0;

        for (char x : s) {
            if (x == '(') {
                open += 2;

                if (open % 2 == 1) {
                    close++;
                    open--;
                }
            } 
            else {
                open--;

                if (open < 0) {
                    open+=2;
                    close++;
                }
            }
        }

        return open + close;
    }
};
