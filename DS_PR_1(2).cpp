#include <iostream>
using namespace std;

int main() {
    int cities = 3;
    int days = 7;
    int temperature[cities][days];
    
    cout << "Enter temperature data for 3 cities for 7 days:\n";
    
    for (int i = 0; i < 3; i++) {
        cout << "City " << i + 1 << "\n";
        for (int j = 0; j < 7; j++) {
            cout << "Day " << j + 1 << ": ";
            cin >> temperature[i][j];
        }
    }
    
    cout << "\nTemperature Data Table:\n";
    cout << "City\t";
    
    for (int j = 0; j < 7; j++) {
        cout << "D" << j + 1 << "\t";
    }
    cout << "Average\n";
    
    for (int i = 0; i < 3; i++) {
        int sum = 0;
        cout << "City " << i + 1 << "\t";
        
        for (int j = 0; j < 7; j++) {
            cout << temperature[i][j] << "\t";
            sum += temperature[i][j];
        }
        
        double average = (double)sum / days;
        cout << average << endl; }  } return 0;}
