#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>  

std::vector<int> twoSum(std::vector<int>& nums, int target) {
    std::unordered_map<int, int> num_map;  // Hash map to store number and its index
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num_map.find(complement) != num_map.end()) {
            return {num_map[complement], i};  // Return indices if complement found
        }
        num_map[nums[i]] = i;  // Store number and its index in hash map
    }
    return {};  // Return empty vector if no solution found (shouldn't happen per constraints)
}

int main() {
    int n, target;
    
    // Input validation for the number of elements
    std::cout << "Enter the number of elements in the array (2 <= n <= 104): ";
    while (!(std::cin >> n) || n < 2 || n > 104) {
        std::cout << "Invalid input. Please enter an integer between 2 and 104: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::vector<int> nums(n);
    
    // Input validation for array elements
    std::cout << "Enter the elements of the array (-10^9 <= nums[i] <= 10^9): " << std::endl;
    for (int i = 0; i < n; ++i) {
        while (!(std::cin >> nums[i]) || nums[i] < -1000000000 || nums[i] > 1000000000) {
            std::cout << "Invalid input. Please enter an integer between -10^9 and 10^9: ";
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
    
    // Input validation for the target
    std::cout << "Enter the target value (-10^9 <= target <= 10^9): ";
    while (!(std::cin >> target) || target < -1000000000 || target > 1000000000) {
        std::cout << "Invalid input. Please enter an integer between -10^9 and 10^9: ";
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    std::vector<int> result = twoSum(nums, target);
    
    if (!result.empty()) {
        std::cout << "Indices of the two numbers are: [" << result[0] << ", " << result[1] << "]" << std::endl;
    } else {
        std::cout << "No solution exists for the given input." << std::endl;
    }
    
    return 0;
}
