class Solution {
public:
    int numWaterBottles(int nb, int ne) {

        
        int ans=nb;

        while(nb>=ne){
            int d=nb/ne;
            int r=nb%ne;
            ans=ans+d;

            nb=d+r;           
        }
      return ans;
        
    }
};