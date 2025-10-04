#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal(numRows);

        for (int i = 0; i < numRows; i++) {
            pascal[i].resize(i + 1);  // cada fila tiene i+1 elementos
            pascal[i][0] = pascal[i][i] = 1;  // primero y último siempre son 1

            for (int j = 1; j < i; j++) {
                pascal[i][j] = pascal[i-1][j-1] + pascal[i-1][j]; // suma de los dos de arriba
            }
        }

        return pascal;
    }
};


int main() {
    Solution sol;
    int numRows;
    cout << "Ingresa el número de filas: ";
    cin >> numRows;
    vector<vector<int>> result = sol.generate(numRows);

}