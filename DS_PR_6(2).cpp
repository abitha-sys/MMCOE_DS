#include <iostream>
#include <string> 
using namespace std;
class Circular {
    	string a[10];
    	int front, rear;
const int size = 10;  
	public:
    		Circular() {
        			front = -1;
        			rear = -1;
    		}
   		void enQueue(string val) {
        			if ((rear + 1) % size == front) {
            				cout << "Spooler is FULL!!! Insertion is not possible!!!\n";
            				return;
        			}
        			if (front == -1 && rear == -1) {
            				front = rear = 0;
        			} else {
            				rear = (rear + 1) % size;
       			}
        			a[rear] = val;
        			cout << "Print job {" << val << "} added to the spooler.\n";
    		}
    		void deQueue() {
        			if (front == -1 && rear == -1) {
            				cout << "The Spooler is EMPTY!!! Deletion is not possible!!!\n";
            				return;
        			}
        			cout << "Processing and removing print job {" << a[front] << "} from the
				spooler.\n";
        			if (front == rear) {
            				front = rear = -1;
        			} else {
            				front = (front + 1) % size;
        			}
    		}
    		void display() {
			if (front == -1 && rear == -1) {
				cout << "Cannot display jobs because spooler is empty.\n";
				return;
			}
			cout << "Current print jobs in spooler: ";
			for (int i = front;; i = (i + 1) % size) {
				cout << a[i];
				if (i == rear) {
					break;
				}
				cout << " <- ";
			}
			cout << endl;
		}
};
int main()
{
    	Circular q;
    	int choice;
    	string name;
    	do
    	{
        		cout << "\n--- Printer Spooler Menu ---\n";
       		 cout << "1. Add Print Job\n";
        		cout << "2. Show Current Print Jobs\n";
        		cout << "3. Process Print Job\n";
        		cout << "4. Exit\n";
        		cout << "Choose an option: ";
        		cin >> choice;
        		switch (choice) {
        			case 1: 	cout << "Enter Print Job name: ";
            				cin >> name;
            				q.enQueue(name);
           				break;
        			case 2: 	q.display();
            				break;
        			case 3:  q.deQueue();
            				break;
        			case 4: 	cout << "Exiting...\n";
            				break;
        			default:  cout << "Invalid option. Try again.\n";
        		}
    	} while (choice != 4);
    	return 0;
}
