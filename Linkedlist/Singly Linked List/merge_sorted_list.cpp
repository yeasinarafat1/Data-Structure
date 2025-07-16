#include <bits/stdc++.h>
using namespace std;

// Node class represents a single element of the linked list
class Node
{
public:
    int val;    // Value stored in the node
    Node *next; // Pointer to the next node

    Node(int val)
    {
        this->val = val;
        this->next = NULL;
    }
};

// Singly linked list class with various utility methods
class link_list
{
private:
    int size; // Number of elements in the list

public:
    Node *head; // Points to the first node
    Node *tail;
    // Constructor initializes empty list
    link_list()
    {

        size = 0;
        head = NULL;
        tail = NULL;
    }

    // Destructor deletes all nodes to prevent memory leaks

    // Returns current number of nodes
    int get_size()
    {
        return size;
    }

    // Takes input and builds the list until -1 is entered
    void take_input()
    {
        while (true)
        {
            int val;
            cin >> val;
            if (val == -1)
            {
                return;
            }
            insert_at_tail(val);
        }
    }

    // Inserts new node at the beginning
    void insert_at_head(int val)
    {
        Node *newNode = new Node(val);
        newNode->next = head;
        head = newNode;

        if (tail == NULL) // If list was empty
        {
            tail = head;
        }

        size++;
    }

    // Inserts new node at the end
    void insert_at_tail(int val)
    {
        Node *newNode = new Node(val);
        if (head != NULL)
        {
            tail->next = newNode;
            tail = newNode;
        }
        else
        {
            head = newNode;
            tail = newNode;
        }
        size++;
    }
};
Node *mergeTwoLists(Node *list1, Node *list2)
{

    Node *head = NULL;
    Node *current = NULL;
    if (list1 == NULL && list2 == NULL)
    {
        return head;
    }
    if (list1 == NULL)
        return list2;
    if (list2 == NULL)
        return list1;
    Node *temp1 = list1;
    Node *temp2 = list2;
    if (temp1->val <= temp2->val)
    {
        head = temp1;
        current = temp1;
        temp1 = temp1->next;
    }
    else
    {
        head = temp2;
        current = temp2;
        temp2 = temp2->next;
    }
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->val <= temp2->val)
        {
            current->next = temp1;
            current = temp1;
            temp1 = temp1->next;
        }
        else
        {
            current->next = temp2;
            current = temp2;
            temp2 = temp2->next;
        }
    }

    if (temp1 == NULL)
    {
        current->next = temp2;
    }
    if (temp2 == NULL)
    {
        current->next = temp1;
    }
    return head;
}
int main()
{
    link_list list1;
    link_list list2;
    list1.take_input();
    list2.take_input();

    Node *head = mergeTwoLists(list1.head, list2.head);
    cout << "[";
    for (Node *temp = head; temp != NULL; temp = temp->next)
    {
        cout << temp->val << ",";
    }
    cout << "]" << endl;
    vector<int> v;
    v.push_back return 0;
}
