
#include <iostream>
#include <vector>

int searchInsert(std::vector<int>& nums, int target) {
    int left = 0;
    int right = nums.size() - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (nums[mid] == target) {
            return mid; // Target found
        } else if (nums[mid] < target) {
            left = mid + 1; // Search in the right half
        } else {
            right = mid - 1; // Search in the left half
        }
    }

    return left; // Target not found, return the insert position
}

int main() {
    std::vector<int> nums = {1, 3, 5, 6};
    int target = 5;
    int index = searchInsert(nums, target);

    std::cout << "Target index: " << index << std::endl; // Output: 2

    return 0;
}
