class Solution {
public:
    int maxArea(vector<int>& height) {
        int i=0;
        int j=height.size()-1;
        int maxa=0;
        int area=0;
        while(i<j){
            int l=min(height[i],height[j]);
            int w=j-i;
             area=l*w;
             maxa=max(maxa,area);
             if(height[i]<=height[j]) i++;
             else j--;
        }
        return maxa;
    }
};