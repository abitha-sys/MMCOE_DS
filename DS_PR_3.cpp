#include <iostream>
using namespace std;
int main() {
    	cout << "Welcome to the Simple Hash-based Load Balancer!" << endl;
   	int n, r_id, r_count = 0;
    	string user;
    	cout << "Enter the total number of servers (N): ";
    	cin >> n;
	int hsh[n];
    	if (n <= 0) {
       		cout << "Number of servers must be positive. Exiting." << endl;
        	return 1;
    	}
    	cout << "\nReady to process requests.";
    	while (1) {		
       		cout << "\nEnter Request ID (integer): ";
        	cin >> r_id;
        	int i = (r_id % n);
        	hsh[i] = r_id;
        	cout << "Request ID " << r_id << " assigned to Server [" << i << "]" << endl;
        	r_count++;
        	cout<<"Do you want to continue? (Yes/No): ";
        	cin>>user;
        	if (user == "No" || user == "no" || user == "NO" || user == "N" || user == "n") {
            		break;
        	}
    	}
    	cout << "\nLoad balancer stopped. \nProcessed " << r_count << " requests." << endl;
    	cout<<"Hash Table: "<<endl;
    	cout<<"Server \tRequest ID"<<endl;
    	for ( int i=0; i<n; i++) {
			cout<<i<<"\t"<<hsh[i]<<endl;
		}
    	return 0;
}
