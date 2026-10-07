class Solution {
public:
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        unordered_set<string> visited;// use unordered to not store duplicate 
        
        
        
          // we will store string in queue and remove one elemnt at a time and then chech if the nee strting i.e after removing el,emnt is valid opr not if valud push into vector result and retutrn result and then remove second element until last .....
        queue<string> q; // first copme first serve
        q.push(s);
        visited.insert(s);// store 1 stroing for not duplication
        bool found = false;

        while (!q.empty()) {
            string cur = q.front();  //store first stirngg 
            q.pop();// remove first elemnt 

            if (isValid(cur)) {
                res.push_back(cur);  // check validiity 
                found = true;
            }

            if (found) continue; // once we find valid, stop deeper removals

            // remove one character at a time
            for (int i = 0; i < cur.size(); i++) {
                if (cur[i] != '(' && cur[i] != ')') continue;
                string next = cur.substr(0, i) + cur.substr(i + 1);
                if (!visited.count(next)) {
                    q.push(next);
                    visited.insert(next);
                }
            }
        }
        return res;
    }

    bool isValid(string s) {
        int count = 0;
        for (char c : s) {
            if (c == '(') count++;
            else if (c == ')') {
                if (count == 0) return false;
                count--;
            }
        }
        return count == 0; // if count is 0 means its valid return ture 
    }
};
