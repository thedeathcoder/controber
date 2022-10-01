#include <bits/stdc++.h>
using namespace std;

template <typename T>

class Node
{
public:
    T data;
    Node<T> *next;

    Node(T data)
    {
        this->data = data;
        next = NULL;
    }
};
template <typename T>

class QueueUsingLL
{
    Node<T> *head;
    Node<T> *tail;

    int size;

public:
    QueueUsingLL()
    {
        head = NULL;
        tail = NULL;
        size = 0;
    }

    void enqueue(T element)
    {

        Node<T> *newNode = new Node<T>(element);
        if (head == NULL)
        {
            head = newNode;
            tail = newNode;
            size++;
            return;
        }
        tail->next = newNode;
        tail = newNode;
        size++;
    }

    T front()
    {
        if (isEmpty())
            return 0;
        return head->data;
    }

    T dequeue()
    {
        if (isEmpty())
            return 0;
        T poppedData = head->data;
        Node<T> *temp = head;
        head = head->next;
        delete temp;
        size--;
        return poppedData;
    }
    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return size == 0;
    }
};

int main()
{
    QueueUsingLL<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout << q.front() << endl;
    cout << q.dequeue() << endl;

    cout << q.dequeue() << endl;

    cout << q.isEmpty() << endl;
    cout << q.getSize() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;
    cout << q.dequeue() << endl;

    cout << q.isEmpty() << endl;
}
