#include <iostream>
#include <string>
using namespace std;

struct Task {
    string name;
    int priority;
    int time;
    Task* next;
};

Task* head = NULL;

void addTask(string name, int priority, int time) {
    Task* newTask = new Task;
    newTask->name = name;
    newTask->priority = priority;
    newTask->time = time;
    newTask->next = NULL;

    if (head == NULL || priority < head->priority) {
        newTask->next = head;
        head = newTask;
    } else {
        Task* temp = head;
        while (temp->next != NULL && temp->next->priority <= priority) {
            temp = temp->next;
        }
        newTask->next = temp->next;
        temp->next = newTask;
    }
}

void showTasks() {
    Task* temp = head;
    cout << "\nTasks in order of execution:\n";
    while (temp != NULL) {
        cout << "Task Name: " << temp->name
             << " | Priority: " << temp->priority
             << " | Time: " << temp->time << endl;
        temp = temp->next;
    }
}

int main() {
    int n;
    cout << "How many tasks do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        string name;
        int priority, time;
        cout << "\nEnter task " << i + 1 << " details:\n";
        cout << "Task Name: ";
        cin >> name;
        cout << "Priority: ";
        cin >> priority;
        cout << "Time: ";
        cin >> time;

        addTask(name, priority, time);
    }

    showTasks();
    return 0;
}
