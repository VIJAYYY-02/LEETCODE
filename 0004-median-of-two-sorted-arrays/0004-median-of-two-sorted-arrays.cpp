class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;

        // Merge arrays into one
        vector<int> arr(n);
        for (int i = 0; i < n1; i++) {
            arr[i] = nums1[i];
        }
        for (int j = 0; j < n2; j++) {
            arr[n1 + j] = nums2[j];
        }

        // // Bubble sort 
        // for (int i = 0; i < n - 1; i++) {
        //     for (int j = 0; j < n - i - 1; j++) {
        //         if (arr[j] > arr[j + 1]) {
        //             int temp = arr[j];
        //             arr[j] = arr[j + 1];
        //             arr[j + 1] = temp;
        //         }
        //     }
        // }
         sort(arr.begin(),arr.end());
        // Median calculation using (n % 2 == 1)
        if (n % 2 == 1) {
            // Odd length → middle element
            return arr[n / 2];
        } else {
            // Even length → average of two middle elements
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};
