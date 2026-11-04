// class Solution {
// public:
//     long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        // diff push queue mai then if we have k1 and k2 not equal to zero thrn largest diff mai plus k1 or k2 unless we have k1 or k2 = 0 
        // now sum ebery diff while suqaring them andfd return sum;

    //     priority_queue<int> q;
    //     int n=nums1.size();
    //     for(int i=0;i<n;i++){
    //         q.push(abs(nums1[i]-nums2[i]));
    //     }

    //     int k=k1+k2;

    //     while(k-- && q.top()>0){
    //          int x = q.top();
    //            q.pop();

    //            q.push(x - 1);
    //     }
    //     long long ans=0;
    //     while(!q.empty())
    //       { long long x = q.top();
    //        q.pop();

    //        ans += x * x;
    //       }
    //       return ans;
    // }
    class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {

        long long k = (long long)k1 + k2;
        int n = nums1.size();

        vector<long long> diff(n);
        long long low = 0, high = 0;

        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            high = max(high, diff[i]);
        }

        while(low < high) {
            long long mid = low + (high - low) / 2;

            long long operations = 0;

            for(int i = 0; i < n; i++) {
                if(diff[i] > mid) {
                    operations += diff[i] - mid;
                }
            }

            if(operations <= k) {
                high = mid;
            }
            else {
                low = mid + 1;
            }
        }

        long long ans = 0;
        long long operations = 0;

        for(int i = 0; i < n; i++) {
            if(diff[i] > low) {
                operations += diff[i] - low;
                diff[i] = low;
            }

            ans += diff[i] * diff[i];
        }

        // Use remaining operations to reduce differences from low to low-1.
        long long remaining = k - operations;

        for(int i = 0; i < n && remaining > 0; i++) {
            if(diff[i] == low && low > 0) {
                ans -= low * low;
                ans += (low - 1) * (low - 1);
                remaining--;
            }
        }

        return ans;
    }
};
