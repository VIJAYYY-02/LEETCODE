// class Solution {
// public:
//     int firstStableIndex(vector<int>& nums, int k) {
//         int n = nums.size();

//         for(int i = 0; i < n; i++) {
//             int maxi = nums[0];
//             int mini = nums[i];

//             for(int j = 0; j <= i; j++) {
//                 maxi = max(maxi, nums[j]);
//             }

//             for(int j = i; j < n; j++) {
//                 mini = min(mini, nums[j]);
//             }

//             if(maxi - mini <= k) {
//                 return i;
//             }
//         }

//         return -1;
//     }
// };
class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> maxi(n);
        vector<int> mini(n);

        maxi[0] = nums[0];
        mini[n-1] = nums[n-1];

        // Prefix maximum
        for(int i = 1; i < n; i++) {
            maxi[i] = max(maxi[i-1], nums[i]);
        }

        // Suffix minimum
        for(int i = n-2; i >= 0; i--) {
            mini[i] = min(mini[i+1], nums[i]);
        }

        // Check each index
        for(int i = 0; i < n; i++) {
            if(maxi[i] - mini[i] <= k) {
                return i;
            }
        }

        return -1;
    }
};