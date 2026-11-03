class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
        // access each substring frpm patterns then for every elemnt of pattern aand compare to word if any char of subtrong is not in word then dont icrease counter ohterwise do increase a counter;
        int count=0;
        for(string s:patterns){
            if(word.find(s)<word.size()) //find returns index and if its less thna size that means it exist and if does not means doesn,t exist 
               count++;
        }
        return count;
    }
};