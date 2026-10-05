#include<iostream>
using namespace std;
    void merge(vector<int>& nums, vector<int>& temp, int l, int mid, int r) {
        int i = l;       // Left subarray pointer
        int j = mid + 1; // Right subarray pointer
        int k = l;       // Temp array pointer

        // Merge directly into the temporary vector
        while (i <= mid && j <= r) {
            if (nums[i] <= nums[j]) {
                temp[k++] = nums[i++];
            } else {
                temp[k++] = nums[j++];
            }
        }

        // Copy remaining elements
        while (i <= mid) temp[k++] = nums[i++];
        while (j <= r)   temp[k++] = nums[j++];

        // Copy the sorted elements back into the original array
        for (int index = l; index <= r; index++) {
            nums[index] = temp[index];
        }
    }

    void merge_sort(vector<int>& nums, vector<int>& temp, int l, int r) {
        if (l < r) {
            int mid = l + (r - l) / 2;
            merge_sort(nums, temp, l, mid);
            merge_sort(nums, temp, mid + 1, r);
            merge(nums, temp, l, mid, r);
        }
    }

    int main() {
        vector<int> temp(nums.size()); 
        merge_sort(nums, temp, 0, nums.size() - 1);
        return nums;
    }
};
