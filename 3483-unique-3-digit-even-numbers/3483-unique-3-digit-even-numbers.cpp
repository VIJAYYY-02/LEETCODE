class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        unordered_set<int> s;
        int n = digits.size();
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < n; k++) {
                    if (i == j || j == k || i == k) continue; // 3no same na ho
                    int hundreds = digits[i];
                    int tens = digits[j];
                    int ones = digits[k];
                    
                    if (hundreds == 0) continue;  // first digit zero na ho
                    if (ones % 2 != 0) continue;  // last dif=git even ho
                    
                    int num = hundreds * 100 + tens * 10 + ones;
                    s.insert(num);
                }
            }
        }
        return s.size();
    }
};
