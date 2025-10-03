#include <iostream>
using namespace std;

int main() {
    int cities = 3;
    int months = 4;
    double rainfall[cities][months];
    
    cout << "Enter rainfall data (in mm) for 3 cities over 4 months:\n";
    
    for (int i = 0; i < cities; i++) {
        cout << "City " << i + 1 << ":\n";
        for (int j = 0; j < months; j++) {
            cout << "Month " << j + 1 << ": ";
            cin >> rainfall[i][j];
        }
    }
    
    cout << "\nRainfall Data Table (in mm):\n";
    cout << "City\tMonth1\tMonth2\tMonth3\tMonth4\tAverage\n";
    
    for (int i = 0; i < cities; i++) {
        double sum = 0;
        cout << "City " << i + 1 << "\t";
        
        for (int j = 0; j < months; j++) {
            cout << rainfall[i][j] << "\t";
            sum += rainfall[i][j];
        }
        
        double average = sum / months;
        cout << average << endl;
    }
    
    return 0;
}
