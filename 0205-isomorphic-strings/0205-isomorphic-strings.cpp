// class Solution {
// public:
//     bool isIsomorphic(string s, string t) {
//         // size is same and then all the charcater should be unique and if the are repeetive remove duplicated abd then the size should eb same
      
//           unordered_set<char> st1, st2;

//         for (char ch : s) {
//             st1.insert(ch);
//         }

//         for (char ch : t) {
//             st2.insert(ch);
//         }

//         return st1.size() == st2.size();
//     }
// };
class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> m1(256, 0);
        vector<int> m2(256, 0);

        for (int i = 0; i < s.size(); i++) {
            if (m1[s[i]] != m2[t[i]])
                return false;

            m1[s[i]] = i + 1;
            m2[t[i]] = i + 1;
        }

        return true;
    }
};