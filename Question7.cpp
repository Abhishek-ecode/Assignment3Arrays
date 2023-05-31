
#include <iostream>
#include <vector>

std::vector<std::vector<int>> findMissingRanges(std::vector<int>& nums, int lower, int upper) {
    std::vector<std::vector<int>> result;

    if (nums.empty()) {
        result.push_back({lower, upper});
        return result;
    }

    if (lower < nums[0]) {
        result.push_back({lower, nums[0] - 1});
    }

    for (int i = 1; i < nums.size(); i++) {
        if (nums[i] > nums[i - 1] + 1) {
            result.push_back({nums[i - 1] + 1, nums[i] - 1});
        }
    }

    if (upper > nums.back()) {
        result.push_back({nums.back() + 1, upper});
    }

    return result;
}

int main() {
    std::vector<int> nums = {0, 1, 3, 50, 75};
    int lower = 0;
    int upper = 99;
    std::vector<std::vector<int>> result = findMissingRanges(nums, lower, upper);

    // Print the result
    for (const auto& range : result) {
        std::cout << "[" << range[0] << "," << range[1] << "]" << std::endl;
    }

    return 0;
}
