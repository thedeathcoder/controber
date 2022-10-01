#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

    Node(int data)
    {
        this->data = data;
        next = NULL;
    }
};

class Pair
{
public:
    Node *head;
    Node *tail;
};

Node *TakeInput()
{
    cout << "Enter Data: " << endl;
    int data;
    cin >> data;

    Node *head = NULL;
    Node *tail = NULL;
    while (data != -1)
    {
        Node *n = new Node(data);
        if (head == NULL)
        {
            head = n;
            tail = n;
        }
        else
        {
            tail->next = n;
            tail = tail->next;
        }

        cin >> data;
    }
    return head;
}

void print(Node *head)
{
    if (head == NULL)
        return;
    Node *temp = head;
    cout << temp->data << " ";
    temp = temp->next;
    print(temp);
}

Node *insertNode(Node *head, int n, int pos)
{
    Node *newNode = new Node(n);
    Node *temp = head;
    if (pos == 0)
    {
        newNode->next = head;
        head = newNode;
    }
    else if (temp != NULL)
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        newNode->next = temp->next;
        temp->next = newNode;
    }
    return head;
}

Node *deleteNode(Node *head, int pos)
{
    Node *temp = head;

    if (pos == 0)
    {
        head = head->next;
    }
    else
    {
        for (int i = 0; i < pos - 1; i++)
        {
            temp = temp->next;
        }
        Node *check = temp->next;
        temp->next = check->next;
        delete (check);
    }
    return head;
}

Node *delNodeRecur(Node *head, int pos)
{
    if (head == NULL)
        return NULL;

    if (pos == 0)
    {
        Node *check = head->next;
        delete (head);
        return check;
    }

    head->next = delNodeRecur(head->next, pos - 1);
    return head;
}

Node *findMid(Node *head)
{
    Node *slow = head;
    Node *fast = head->next;

    while (fast != NULL)
    {
        fast = fast->next;
        if (fast != NULL)
        {
            slow = slow->next;
            fast = fast->next;
        }
    }
    return slow;
}

Node *mergeList(Node *head, Node *head2)
{
    Node *finalHead = NULL;
    Node *finalTail = NULL;

    if (head->data >= head2->data)
    {
        finalHead = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    else
    {
        finalHead = head;
        finalTail = head;
        head = head->next;
    }

    while (head != NULL && head2 != NULL)
    {
        if (head->data >= head2->data)
        {
            finalTail->next = head2;
            finalTail = head2;
            head2 = head2->next;
        }
        else
        {
            finalTail->next = head;
            finalTail = head;
            head = head->next;
        }
    }

    while (head2 != NULL)
    {
        finalTail->next = head2;
        finalTail = head2;
        head2 = head2->next;
    }
    while (head != NULL)
    {
        finalTail->next = head;
        finalTail = head;
        head = head->next;
    }
    return finalHead;
}

Node *mergeSort(Node *head)
{
    if (head->next == NULL)
    {
        return head;
    }
    Node *mid = findMid(head);
    Node *head2 = mid->next;
    mid->next = NULL;

    Node *firstList = mergeSort(head);
    Node *secondList = mergeSort(head2);

    Node *mergedList = mergeList(firstList, secondList);
    return mergedList;
}

Pair reverseLL(Node *head)
{

    if (head == NULL || head->next == NULL)
    {
        Pair ans;
        ans.head = head;
        ans.tail = head;
        return ans;
    }
    Pair finalHead = reverseLL(head->next);

    finalHead.tail->next = head;
    head->next = NULL;

    Pair ans;
    ans.head = finalHead.head;
    ans.tail = head;
    return ans;
}

Node *reverseList(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *finalHead = reverseList(head->next);

    Node *temp = finalHead;

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    temp->next = head;
    head->next = NULL;
    return finalHead;
}

Node *reverseListEasy(Node *head)
{
    if (head == NULL || head->next == NULL)
        return head;
    Node *finalHead = reverseListEasy(head->next);

    Node *tail = head->next;
    tail->next = head;
    head->next = NULL;
    return finalHead;
}

Node *reverseIter(Node *head)
{
    Node *curr = head;
    Node *prev = NULL;
    Node *nxt = head->next;

    while (1)
    {
        curr->next = prev;
        prev = curr;
        curr = nxt;
        if (curr == NULL)
            break;
        nxt = nxt->next;
    }
    return prev;
}

Node *findSumZero(Node *head)
{
    Node *track = head;
    Node *nxt = head->next;

    while (nxt->next != NULL)
    {
        if (nxt->data != 0)
        {
            track->data = track->data + nxt->data;
        }
        else
        {
            track->next = nxt;
            track = nxt;
        }
        nxt = nxt->next;
    }
    track->next = NULL;
    return head;
}

int main()
{
    Node *head = TakeInput();
    // Node *head2 = TakeInput();

    // Node *mergeSorted = mergeSort(head);

    // Pair reversedList = reverseLL(head);
    // Node *reversedList = reverseListEasy(head);
    // Node *reversedList = reverseIter(head);

    // Node *summed = findSumZero(head);

    // Node *sortedHead = mergeList(head, head2);
    // head = insertNode(head, 100, 0);

    // head = delNodeRecur(head, 2);

    // Node *mid = findMid(head);
    // cout << "Mid Value: " << mid->data << endl;
    // print(reversedList.head);

    print(head);

    return 0;
}
