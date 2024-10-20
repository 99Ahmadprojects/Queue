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

    int countElements() {
        node *temp = front;
        int count = 0;
        while (temp != NULL) {
            count++;
            temp = temp->next;
        }
        return count;
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
    
    cout << "Number of elements in the queue: " << q1.countElements() << endl;
    
    q1.Dequeue();
    cout << "Queue after Dequeue:" << endl;
    q1.display();
    
    cout << "Number of elements in the queue: " << q1.countElements() << endl;

    return 0;
}
