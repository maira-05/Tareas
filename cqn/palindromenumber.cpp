#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        long reversed = 0;
        int original = x;

        while (x != 0) {
            int digit = x % 10;
            reversed = reversed * 10 + digit;
            x /= 10;
        }

        return original == reversed;
    }
};

int main() {
    Solution sol;
    int num;

    cout << "Ingresa un numero: ";
    cin >> num;

    if (sol.isPalindrome(num)) {
        cout << num << " se lee igual de derecha a izquierda y de izquierda a derecha" << endl;
    } else {
        cout << num << " no es un numero palindromo" << endl;
    }

    return 0;
}
