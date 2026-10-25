class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        int n = nums.size();

        for (int i = 1; ; i++) {
            int ans = k * i;
            bool found = false;

            for (int x : nums) {
                if (x == ans) {
                    found = true;
                    break;
                }
            }

            if (!found) return ans;
        }
    }
};