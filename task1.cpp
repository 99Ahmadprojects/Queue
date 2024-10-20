#include <iostream>
using namespace std;

struct node {
    int data;
    node *next;
};

class Queue {
    node *front, *rear;
    int currentSize;
    const int maxSize;

public:
    Queue(int size): 
	maxSize(size) {
        front = rear = NULL;
        currentSize = 0;
    }

    void Enqueue(int data) {
        if (currentSize == maxSize) {
            cout << "Queue Overflow. Cannot add more elements." << endl;
            return;
        }

        node *newnode;
        newnode = new node;
        newnode->data = data;
        newnode->next = NULL;

        if (front == NULL) {
            front = rear = newnode;
        } else {
            rear->next = newnode;
            rear = newnode;
        }

        currentSize++;
    }

    void Dequeue() {
        if (front == NULL) {
            cout << "Queue is Empty." << endl;
        } 
		else {
            node *temp = front;
            front = front->next;
            delete temp;
            currentSize--;
        }
    }

    void display() {
        node *temp = front;
        while (temp != NULL) {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << endl;
    }
};

int main() {
    Queue q1(4);

    q1.Enqueue(5);
    q1.Enqueue(15);
    q1.Enqueue(25);
    q1.Enqueue(30);

    cout << "Queue after Enqueue:" << endl;
    q1.display();

    q1.Enqueue(40);

    q1.Dequeue();
    cout << "Queue after Dequeue:" << endl;
    q1.display();

    return 0;
}
