#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of scores for each player: ";
    cin >> n;

    int player1[n], player2[n];

    cout << "Enter the scores for Player 1:\n";
    for (int i = 0; i < n; i++) {
        cin >> player1[i];
    }

    cout << "\nEnter the scores for Player 2:\n";
    for (int i = 0; i < n; i++) {
        cin >> player2[i];
    }

    // Bubble sort in descending order for Player 1
    cout << "\nSorting... Leveling up Player 1!\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (player1[j] < player1[j + 1]) {
                int temp = player1[j];
                player1[j] = player1[j + 1];
                player1[j + 1] = temp;
            }
        }
    }

    // Bubble sort in descending order for Player 2
    cout << "\nSorting... Leveling up Player 2!\n";
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (player2[j] < player2[j + 1]) {
                int temp = player2[j];
                player2[j] = player2[j + 1];
                player2[j + 1] = temp;
            }
        }
    }

    // Display sorted scores
    cout << "\nSorted scores:\n";
    cout << "Player 1: ";
    for (int i = 0; i < n; i++) {
        cout << player1[i] << " ";
    }

    cout << "\nPlayer 2: ";
    for (int i = 0; i < n; i++) {
        cout << player2[i] << " ";
    }
    cout << endl;

    // Compare highest scores
    if (player1[0] > player2[0]) {
        cout << "\nPlayer 1 is the winner!" << endl;
    } 
    else if (player2[0] > player1[0]) {
        cout << "\nPlayer 2 is the winner!" << endl;
    } 
    else {
        cout << "\nIt's a tie!" << endl;
    }

    return 0;
}
