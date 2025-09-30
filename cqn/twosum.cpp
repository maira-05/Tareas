#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    return {i, j};
                }
            }
        }
        return {};
    }
};
int main() {
    Solution sol;
    string line;
    vector<int> nums;
    int target;

    cout << "Ingrese los numeros separados por comas: ";
    getline(cin, line);

    for (size_t i = 0, start = 0; i <= line.size(); i++) {
        if (i == line.size() || line[i] == ',') {
            nums.push_back(stoi(line.substr(start, i - start)));
            start = i + 1;
        }
    }

    cout << "Ingrese el valor objetivo (target): ";
    cin >> target;

    vector<int> result = sol.twoSum(nums, target);

    cout << "Input: nums = [";
    for (size_t i = 0; i < nums.size(); i++) {
        cout << nums[i];
        if (i < nums.size() - 1) cout << ",";
    }
    cout << "], target = " << target << endl;

    cout << "Output: [";
    for (size_t i = 0; i < result.size(); i++) {
        cout << result[i];
        if (i < result.size() - 1) cout << ",";
    }
    cout << "]" << endl;

    if (!result.empty()) {
        cout << "Explanation: Because nums[" << result[0] << "] + nums[" 
             << result[1] << "] == " << target 
             << ", we return [" << result[0] << ", " << result[1] << "]." << endl;
    } else {
        cout << "Explanation: No two indices sum to target." << endl;
    }

    return 0;
}