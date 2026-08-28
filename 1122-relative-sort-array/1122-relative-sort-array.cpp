class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        map<int, int> mp;

        // Count elements of arr1
        for (int x : arr1)
            mp[x]++;

        vector<int> ans;

        // Put elements according to arr2
        for (int x : arr2) {
            while (mp[x] > 0) {
                ans.push_back(x);
                mp[x]--;
            }
        }

        // Put remaining elements in sorted order
        for (auto it : mp) {
            while (it.second > 0) {
                ans.push_back(it.first);
                it.second--;
            }
        }

        return ans;
    }
};