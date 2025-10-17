#include <iostream>
#include <vector>
#include <sstream>  
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0; 

        int minPrice = prices[0];
        int maxProfit = 0;

        for (int i = 1; i < prices.size(); i++) {
            int profit = prices[i] - minPrice;

            if (profit > maxProfit)
                maxProfit = profit;

            if (prices[i] < minPrice)
                minPrice = prices[i];
        }

        return maxProfit;
    }
};

int main() {
    Solution sol;
    vector<int> precios;
    string linea;
    int valor;

    cout << "Ingresa los precios separados por espacios:\n";
    getline(cin, linea); 
    stringstream ss(linea);

    while (ss >> valor) { 
        precios.push_back(valor);
    }

    int resultado = sol.maxProfit(precios);
    cout << "La ganancia máxima es: " << resultado << endl;

    return 0;
}