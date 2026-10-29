class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());

        int o1=nums[n-3]*nums[n-1]*nums[n-2];
        int o2=nums[n-1]*nums[0]*nums[1];

        return max(o1,o2);
    }
};