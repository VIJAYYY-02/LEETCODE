class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        //int mid = (nums[0] + nums[nums.size()-1]) / 2;
      int mid=nums.size()/2;
       int moves=0;
       for(int x:nums){
        moves+=abs(x-nums[mid]);
       }
       return moves;
    }
};