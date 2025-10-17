#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int titleToNumber(string columnTitle) {
        int result = 0;
        for (char c : columnTitle) {
            int value = c - 'A' + 1; 
            result = result * 26 + value; 
        }
        return result;
    }
};

int main() {
    Solution sol;
    string columnTitle;


    cout << "Ingrese el titulo de columna (por ejemplo A, AB, ZY): ";
    cin >> columnTitle;

    int numero = sol.titleToNumber(columnTitle);
    cout << "El numero correspondiente es: " << numero << endl;
    return 0;
}