class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int p1 = m - 1; // Pointer for nums1
        int p2 = n - 1; // Pointer for nums2
        int p = m + n - 1; // Pointer for the end of the merged array

        // Loop backwards as long as there are elements in nums2
        while (p2 >= 0) {
            // If p1 is valid and its element is larger, use it.
            if (p1 >= 0 && nums1[p1] > nums2[p2]) {
                nums1[p] = nums1[p1];
                p1--;
            } else {
                // Otherwise, use the element from nums2.
                nums1[p] = nums2[p2];
                p2--;
            }
            // Move the write pointer back.
            p--;
        }
    }
};