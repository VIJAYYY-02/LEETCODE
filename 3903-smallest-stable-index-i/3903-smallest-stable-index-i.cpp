
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();
         // use for loop form 0 index and then divide array into two from idex i thn from first half fid max and from second half find min and if abs subtraction ofboth is less than k count++ then at last return count;

        for (int i = 0; i < n; i++) {
            int maxi = nums[0];
            int mini = nums[i];

            for (int j = 0; j <= i; j++) {
                if (nums[j] > maxi) {
                    maxi = nums[j];
                }
            }

            for (int j = i; j < n; j++) {
                if (nums[j] < mini) {
                    mini = nums[j];
                }
            }

            if (maxi - mini <= k) {
                return i;
            }
        }

        return -1;
    }
};
