class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        int n = n1 + n2;


        vector<int> arr;
        arr.reserve(n);

        int i = 0, j = 0;

        // Merge two sorted arrays
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                arr.push_back(nums1[i++]);
            } else {
               arr.push_back(nums2[j++]);
            }
        }
        while (i < n1) arr.push_back(nums1[i++]);
        while (j < n2) arr.push_back(nums2[j++]);

        // // Merge arrays into one
        // vector<int> arr(n);
        // for (int i = 0; i < n1; i++) {
        //     arr[i] = nums1[i];
        // }
        // for (int j = 0; j < n2; j++) {
        //     arr[n1 + j] = nums2[j];
        // }

        // // // Bubble sort 
        // // for (int i = 0; i < n - 1; i++) {
        // //     for (int j = 0; j < n - i - 1; j++) {
        // //         if (arr[j] > arr[j + 1]) {
        // //             int temp = arr[j];
        // //             arr[j] = arr[j + 1];
        // //             arr[j + 1] = temp;
        // //         }
        // //     }
        // // }
        //  sort(arr.begin(),arr.end());
        // // Median calculation using (n % 2 == 1)
        if (n % 2 == 1) {
            // Odd length → middle element
            return arr[n / 2];
        } else {
            // Even length → average of two middle elements
            return (arr[n / 2 - 1] + arr[n / 2]) / 2.0;
        }
    }
};
