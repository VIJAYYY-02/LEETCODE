class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int ans = 0;

        // for (int i = 0; i < nums.size(); i++) {
        //     for (int j = i+1 ; j < nums.size(); j++) {
        //         ans = max(ans, (nums[i] - 1) * (nums[j] - 1));
        //     }
        // }

        // return ans;

        int mx1=0,mx2=0;
        for(int x:nums){
            if(x>mx1){
                mx2=mx1;
                mx1=x;
            }
            else if(x>mx2) mx2=x;
        }
        return (mx1-1)*(mx2-1);
    }
};