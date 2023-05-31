#include <iostream>
#include <vector>
#include <algorithm>

void nextPermutation(std::vector<int>& nums) {
    int n = nums.size();
    int i = n - 2;

    // Find the first pair of adjacent elements in descending order
    while (i >= 0 && nums[i] >= nums[i + 1]) {
        --i;
    }

    if (i >= 0) {
        // Find the next greater element than nums[i]
        int j = n - 1;
        while (j > i && nums[j] <= nums[i]) {
            --j;
        }

        // Swap nums[i] and nums[j]
        std::swap(nums[i], nums[j]);
    }

    // Reverse the subarray from i+1 to the end
    std::reverse(nums.begin() + i + 1, nums.end());
}

int main() {
    std::vector<int> nums = {1, 2, 3};
    nextPermutation(nums);

    for (int num : nums) {
        std::cout << num << " ";
    }
    std::cout << std::endl;  // Output: 1 3 2

    return 0;
}

