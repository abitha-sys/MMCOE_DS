#include <iostream>
using namespace std;

int main() {
    int n;  // number of servers
    cout << "Enter the total number of servers: ";
    cin >> n;

    if (n <= 0) {
        cout << "Number of servers must be positive!" << endl;
        return 0;
    }

    int hsh[100]; // basic hash table
    int request_id; 
    string choice;
    int count = 0;

    cout << "\n--- Simple Hash-Based Load Balancer ---\n";

    do {
        cout << "Enter Request ID (integer): ";
        cin >> request_id;

        int index = request_id % n; // hash function
        hsh[index] = request_id;

        cout << "Request " << request_id << " assigned to Server [" << index << "]\n";

        count++;

        cout << "Do you want to continue? (Yes/No): ";
        cin >> choice;

    } while (choice == "Yes" || choice == "yes" || choice == "Y" || choice == "y");

    cout << "\n--- Load Balancer Summary ---\n";
    cout << "Total Requests Processed: " << count << endl;
    cout << "Server\tRequest ID\n";
    for (int i = 0; i < n; i++) {
        cout << i << "\t" << hsh[i] << endl;
    }

    return 0;
}
