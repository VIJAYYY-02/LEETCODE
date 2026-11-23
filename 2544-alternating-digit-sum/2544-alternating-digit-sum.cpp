class Solution {
public:
    int alternateDigitSum(int n) {
        vector<int> temp;
        // store every elemnt into temp array 

        while (n > 0) {
            temp.push_back(n % 10);
            n /= 10;
        }
      // reversee the order 
        reverse(temp.begin(), temp.end());
         // using signal 0 for add and 1 for sub 

        int signal = 0;
        int ans = 0;

        for (int x : temp) {
            if (signal == 0) {
                ans += x;
                signal = 1;
            } else {
                ans -= x;
                signal = 0;
            }
        }

        return ans;
    }
};