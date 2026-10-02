class Solution {
public:
    int reverseDegree(string s) {
         int total = 0; // main thing asckii value  
    for (int i = 0; i < s.size(); i++) {
        int pos = i + 1; 
        int revVal = 26 - (s[i] - 'a');  // a-a=0 then26-0= 26 then multiplay with pos 
        total += revVal * pos;  //26*1=26 and thern add using loop;
    }
    return total;
      
        
    }
};