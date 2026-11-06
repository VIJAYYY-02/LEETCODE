// class Solution {
// public:
//     int minimumDeletions(vector<int>& nums) {
//         int mini=*min_element(nums.begin(),nums.end());
//         int maxi=*max_element(nums.begin(),nums.end());
//         //min max ,dequeue banao find min max thn remove min form fornt and last then use min of both approach to find min for fot botj del and return the sum 

        
//     }
// };
class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        int n = nums.size();

        int mini = min_element(nums.begin(), nums.end()) - nums.begin();
        int maxi = max_element(nums.begin(), nums.end()) - nums.begin();

        int a = max(mini, maxi) + 1;
        int b = n - min(mini, maxi);
        int c = min(mini, maxi) + 1 + n - max(mini, maxi);

        return min(a, min(b, c));
    }
};