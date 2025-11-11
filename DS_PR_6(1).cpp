#include <iostream> 
#define MAXSIZE 10
#define MIN 0
using namespace std;
class Coffee_shop {
int token[MAXSIZE];
public:
int rear;
int front;
Coffee_shop () {
rear = -1;
front = -1;
}

bool isFull () {
if (rear == MAXSIZE-1) {
return 1;
} else {
return 0;
}
}

bool isEmpty () {
if (front == -1 || front == MAXSIZE || rear < front) {
return 1;
} else {
return 0;
}
}

void enQueue (int t) {
if (isFull()) {
cout << "Sorry! The order can't be placed\nThe queue is full!" << endl;
} else {
if (rear == -1) {
front = 0;
}
rear = rear + 1;
token[rear] = t;
cout<<"order "<<token[rear]<<" is added to the queue";
}
}

int deQueue () {
if (isEmpty()) {
cout << "The queue is empty." << endl;
return 0;
} else {
int t = token[front];
cout <<	 "Order processed for: " << token[front] <<" and served"<< endl;
front += 1;
return t;
}
}
};
int main() {
Coffee_shop customer;
int choice = 0, order;
do {
cout << "Coffee shop menu:" << endl;
cout << " 1. Add an order\n 2. Serve order\n 3. Exit\nChoice: ";
	cin >> choice;
switch (choice) {
case 1: cout << "\nEnter your order number: ";
cin >> order;
customer.enQueue(order);
cout << endl;
break;
case 2:	cout << "\nprocessing the order:" << endl;
customer.deQueue();
cout << endl;
break;
case 3: 	cout << "Thank you!" << endl;
break;
default: cout << "\nIncorrect choice! Try again" << endl;
}
} while (choice != 3);
return 0;
}
