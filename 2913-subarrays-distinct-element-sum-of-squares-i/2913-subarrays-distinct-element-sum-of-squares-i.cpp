class Solution {
public:
    int sumCounts(vector<int>& nums) {
        int ans = 0;
        int n = nums.size();

        for (int i = 0; i < n; i++) {  // first loop to the endddd
            set<int> s;  // set stores uniue value 

            for (int j = i; j < n; j++) { // second loop from ht efrst loop to the end covering ebery subset and sto4es only unqiue vaue 
                s.insert(nums[j]);
                int k = s.size();
                ans += k * k;
            }
        }

        return ans;
    }
};