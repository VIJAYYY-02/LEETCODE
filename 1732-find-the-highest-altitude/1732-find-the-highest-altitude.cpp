class Solution {
public:
    int largestAltitude(vector<int>& gain) {
    //     int n=gain.size();
    //     int ts=0;
    //     vector<int> ans;
    //     ans.push_back(ts);
    //     for(int i=0;i<n;i++){
    //         ts=ts+gain[i];
    //         ans.push_back(ts);
    //     }
    //     return ans;
    // }
    
       int al=0;
       int maxi=0;
       for(int x:gain){
        al+=x;
        maxi=max(maxi,al);
       }
       return maxi;
    
    
    
    
    
    
    
    
    
    }
};