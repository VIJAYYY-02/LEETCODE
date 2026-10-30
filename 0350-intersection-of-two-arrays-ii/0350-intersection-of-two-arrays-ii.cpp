class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        // create two map and find the size for both the sets whose ever size is small start a foreach loop and for every element search if that elemnt is in seconf set if yes store the elemnt intpo ans and hn return ans...
         sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());

    int i = 0, j = 0;
    vector<int> ans;

    while(i < nums1.size() && j < nums2.size()) {
        if(nums1[i] == nums2[j]) {
            ans.push_back(nums1[i]);
            i++;
            j++;
        }
        else if(nums1[i] < nums2[j]) {
            i++;
        }
        else {
            j++;
        }
    }

    return ans;
    }
};