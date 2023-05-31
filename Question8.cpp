#include <iostream>
#include <vector>
#include <algorithm>

bool canAttendMeetings(std::vector<std::vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end(), [](const auto& a, const auto& b) {
        return a[0] < b[0];
    });

    for (int i = 1; i < intervals.size(); i++) {
        if (intervals[i][0] <= intervals[i - 1][1]) {
            return false;
        }
    }

    return true;
}

int main() {
    std::vector<std::vector<int>> intervals = {{0, 30}, {5, 10}, {15, 20}};
    bool canAttend = canAttendMeetings(intervals);

    std::cout << "Can attend all meetings: " << std::boolalpha << canAttend << std::endl; // Output: false

    return 0;
}
