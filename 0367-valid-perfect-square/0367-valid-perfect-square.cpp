
class Solution {
public:
    bool isPerfectSquare(int num) {
        long long low = 1, high = num;
// use binary searach methode to divide the num in mid and square of that mid to vheck if tit eual to num
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            long long square = mid * mid;

            if (square == num) {
                return true;
            }
            else if (square < num) {
                low = mid + 1;
            }
            else {
                high = mid - 1;
            }
        }

        return false;
    }
};
