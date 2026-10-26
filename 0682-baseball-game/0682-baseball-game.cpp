// class Solution {
// public:
//     int calPoints(vector<string>& operations) {
//         int n=operations.size();
//         stack<int> st;
//         for(string x:operations){
//         if(x=="C") st.pop();
//         if(x=="D"){
//             st.push(2*st.top());
//         }
//         if(x=="+"){
//             int a=st.top();
//             st.pop();
//             int b=st.top();
//             st.pop();

//             st.push(a);
//             st.push(a+b);
//         }
//         else
//           {
//             st.push(stoi(x));
//           }

//         }
//         int sum=0;
//         while(!st.empty()){
//             sum+=st.top();
//             st.pop();
//         }
    
//     return sum;
// }
// };
class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;

        for(string x : operations) {

            if(x == "C") {
                st.pop();
            }
            else if(x == "D") {
                st.push(2 * st.top());
            }
            else if(x == "+") {
                int a = st.top();
                st.pop();

                int b = st.top();

                st.push(a);          // restore a
                st.push(a + b);
            }
            else {
                st.push(stoi(x));
            }
        }

        int sum = 0;

        while(!st.empty()) {
            sum += st.top();
            st.pop();
        }

        return sum;
    }
};