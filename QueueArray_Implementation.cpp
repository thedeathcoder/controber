#include <bits/stdc++.h>
using namespace std;

template <typename T>
class QueueUsingArray
{
    T *data;
    int nextIndex;
    int capacity;
    int size;
    int firstIndex;

public:
    QueueUsingArray(int s)
    {
        data = new int(s);
        nextIndex = 0;
        firstIndex = -1;
        capacity = s;
        size = 0;
    }

    int getSize()
    {
        return size;
    }

    bool isEmpty()
    {
        return firstIndex == -1;
    }

    T dequeue()
    {

        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        T ans = data[firstIndex];
        size--;
        firstIndex = (firstIndex + 1) % capacity;
        if (size == 0)
        {
            firstIndex = -1;
            nextIndex = 0;
        }
        return ans;
    }

    void enqueue(T element)
    {
        if (capacity == size)
        {
            cout << "Queue is full";
            return;
        }
        size++;
        data[nextIndex] = element;
        nextIndex = (nextIndex + 1) % capacity;
        if (firstIndex == -1)
            firstIndex++;
    }

    T front()
    {
        if (isEmpty())
        {
            cout << "Queue is empty" << endl;
            return 0;
        }
        return data[firstIndex];
    }
};

int main()
{
    QueueUsingArray<int> q(5);
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
