class Solution {
public:
    bool isRectangleOverlap(vector<int>& rec1, vector<int>& rec2) {
         //non overlap conditions are ==== if x2<=X1
                                    //     if x1>=X2
                                    //     if y2<=Y1
                                    //     IF y1>=Y2
    return !(rec1[2] <= rec2[0] ||
             rec2[2] <= rec1[0] ||  
             rec1[3] <= rec2[1] ||  
             rec2[3] <= rec1[1]);  
}
    
};