class Solution {
public:
    int sumOfSquares(vector<int>& nums) {
        int n= nums.size();
        int r=0;

        for(int x=1;x<=n;x++){
            if(n%x==0) {
                r+=nums[x-1]*nums[x-1];

            }
        }
        return r;
        
    }
};