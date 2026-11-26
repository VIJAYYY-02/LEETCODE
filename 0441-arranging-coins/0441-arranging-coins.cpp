class Solution {
public:
    int arrangeCoins(int n) {
        int r = 1;
        // calcullate remaining as shown in diagram 
        while (n >= r) {
            n -= r;
            r++;
        }
        
        return r - 1;
    }
};