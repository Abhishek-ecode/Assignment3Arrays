#include <iostream>
#include <vector>

std::vector<int> plusOne(std::vector<int>& digits) {
    int n = digits.size();
    int carry = 1;

    for (int i = n - 1; i >= 0; --i) {
        digits[i] += carry;
        if (digits[i] == 10) {
            digits[i] = 0;
            carry = 1;
        } else {
            carry = 0;
            break;
        }
    }

    if (carry == 1) {
        digits.insert(digits.begin(), 1);
    }

    return digits;
}

int main() {
    std::vector<int> digits = {1, 2, 3};
    std::vector<int> result = plusOne(digits);

    for (int digit : result) {
        std::cout << digit << " ";
    }
    std::cout << std::endl;  // Output: 1 2 4

    return 0;
}

