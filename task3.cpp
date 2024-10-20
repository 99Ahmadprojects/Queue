#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class Queue {
    node *front, *rear;
public:
    Queue() {
        front = rear = NULL;
    }

    void Enqueue(int data) {
        node *newnode;
        newnode = new node;
        newnode->data = data;
        newnode->next = NULL;

        if (front == NULL)
            front = rear = newnode;
        else {
            rear->next = newnode;
            rear = newnode;
        }
    }

    void Dequeue() {
        node *temp;
        if (front == NULL) {
            cout << "Queue is Empty." << endl;
        } else {
            temp = front;
            front = front->next;
            delete temp;
        }
    }

    void display() {
        node *temp;
        temp = front;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }

    void clearQueue() {
        node *temp;
        while (front != NULL) {
            temp = front;
            front = front->next;
            delete temp;
        }
        rear = NULL;
        cout << "Queue has been cleared." << endl;
    }
};

int main() {
    Queue q1;
    q1.Enqueue(5);
    q1.Enqueue(15);
    q1.Enqueue(25);
    q1.Enqueue(30);
    cout << "Queue after Enqueue:" << endl;
    q1.display();
    
    q1.Dequeue();
    cout << "Queue after Dequeue:" << endl;
    q1.display();

    q1.clearQueue();
    cout << "Queue after clearing:" << endl;
    q1.display();

    return 0;
}
