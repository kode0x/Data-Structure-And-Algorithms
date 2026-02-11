#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;

    Node(int value)
    {
        data = value;
        prev = nullptr;
        next = nullptr;
    }
};

class DoublyLinkedList
{
private:
    Node *head;
    Node *tail;
    int length;

public:
    DoublyLinkedList(int value)
    {
        Node *newNode = new Node(value);
        head = newNode;
        tail = newNode;
        length = 1;
    }

    ~DoublyLinkedList()
    {
        Node *temp = head;
        while (head)
        {
            head = head->next;
            delete temp;
            temp = head;
        }
    }

    // Traversal

    // Forward Traversal
    void display()
    {
        Node *temp = head;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->next != nullptr)
            {
                cout << " <-> ";
            }
            temp = temp->next;
        }
        cout << " <-> NULL" << endl;
    }

    // Backward Traversal
    void rdisplay()
    {
        Node *temp = tail;
        while (temp != nullptr)
        {
            cout << temp->data;
            if (temp->prev != nullptr)
            {
                cout << " <-> ";
            }
            temp = temp->prev;
        }
        cout << " <-> NULL" << endl;
    }

    // Insertion

    // Insert At The Beginning (Prepend)
    void prepend(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = tail = newNode;
            length++;
            return;
        }

        newNode->next = head;
        head->prev = newNode;
        head = newNode;
        length++;
    }

    // Insert At A Specific Index
    void insert(int index, int data)
    {
        if (index == 0)
        {
            prepend(data);
            return;
        }

        Node *temp = head;
        int count = 0;

        while (temp != nullptr && count < index - 1)
        {
            temp = temp->next;
            count++;
        }

        if (temp == nullptr)
            return;

        Node *newNode = new Node(data);

        newNode->next = temp->next;
        newNode->prev = temp;

        if (temp->next != nullptr)
            temp->next->prev = newNode;
        else
            tail = newNode;

        temp->next = newNode;
        length++;
    }

    // Insert At The End (Append)
    void append(int data)
    {
        Node *newNode = new Node(data);

        if (head == nullptr)
        {
            head = tail = newNode;
            length++;
            return;
        }

        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
        length++;
    }

    // Deletion

    // Delete From The Beginning
    void shift()
    {
        if (length == 0)
        {
            cout << "Doubly Linked List Is Empty" << endl;
            return;
        }

        Node *temp = head;

        if (length == 1)
        {
            head = NULL;
        }
        else
        {
            head = head->next;
            head->prev = NULL;
        }

        delete temp;
        length--;
    }

    // Delete From The End
    void pop()
    {
        if (length == 0)
        {
            cout << "Doubly Linked List Is Empty" << endl;
            return;
        }

        if (length == 1)
        {
            delete tail;
            head = nullptr;
            tail = nullptr;
            length--;
            return;
        }

        Node *temp = tail;
        tail = tail->prev;
        tail->next = nullptr;

        delete temp;
        length--;
    }

    // Delete At A Specific Position
    void removeAtIndex(int index)
    {
        if (index < 0 || index >= length)
        {
            cout << "Invalid Index" << endl;
            return;
        }

        if (index == 0)
        {
            cout << "Doubly Linked List Is Empty" << endl;
            return;
        }

        if (index == length - 1)
        {
            pop();
            return;
        }

        Node *current = head;
        for (int i = 0; i < index; i++)
        {
            current = current->next;
        }

        current->prev->next = current->next;
        current->next->prev = current->prev;

        delete current;
        length--;
    }

    

    /*
        TODO: Add Operations:
        1. Searching
        2. Count
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
