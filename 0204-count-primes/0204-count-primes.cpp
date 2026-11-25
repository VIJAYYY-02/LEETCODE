// class Solution {
// public:
//     int countPrimes(int n) {
//         int c=0;
//         if(n<=2) return 0;
//         // lets say 10 ko check karna hai toh uske half means 5 tak ki range se kisi s bhi divide ho gay toh not prime
//         for(int i=2;i<n;i++){
//            bool prime = true;
//             for (int j = 2; j <= i / 2; j++) {
//                if (i % j == 0) {
//                   prime = false;
//                    break;
//                 }
//             }
        
//         if (prime) {
//             c++;
//         }
//         }
//         return c;
  
          
//     }
// };
class Solution {
public:
    int countPrimes(int n) {
        if (n <= 2) return 0;

        vector<bool> prime(n, true);

        prime[0] = false;
        prime[1] = false;

        for (int i = 2; i * i < n; i++) {

            if (prime[i]) {

                for (int j = i * i; j < n; j += i) {
                    prime[j] = false;
                }
            }
        }

        int c = 0;

        for (int i = 2; i < n; i++) {
            if (prime[i]) {
                c++;
            }
        }

        return c;
    }
};