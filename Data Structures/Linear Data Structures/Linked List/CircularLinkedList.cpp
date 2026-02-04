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
        this->next = nullptr;
    }
};

class CircularLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    CircularLinkedList(int data)
    {
        Node *newNode = new Node(data);
        head = newNode;
        tail = newNode;
        tail->next = head;
        length = 1;
    }
    /*
       TODO: Add Operations:
       1. Searching
       2. Count
       3. Insertion
           > At The Beginning
           > At The End
           > At A Specific Position
       4. Deletion
           > At The Beginning
           > At The End
           > At A Specific Position
       5. Clear
       6. Get
       7. Set
       8. Reverse
       9. Middle
   */
};

int main()
{
}
