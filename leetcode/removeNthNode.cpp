#include <iostream>

using namespace std;

struct Node
{
    int data;
    struct Node* next;
};

void push(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node = new struct Node;

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}

void print(Node* head)
{
    while (head != NULL) {
	cout << head->data << "->";
	head = head->next;
    }
    return;
}

Node* printNthFromLast(Node* head, int n)
{
    Node* main_ptr = head;
    Node* ref_ptr = head;
    int count = 0;

    n++;
    while (count < n) {
	ref_ptr = ref_ptr->next;
	count++;
    }

    while (ref_ptr != NULL) {
	main_ptr = main_ptr->next;
	ref_ptr = ref_ptr->next;
    }
    main_ptr->next = main_ptr->next->next;
    cout << main_ptr->next->data << endl;
    return head;
}
int main()
{
    struct Node* head = NULL;
    push(&head, 5);
    push(&head, 4);
    push(&head, 3);
    push(&head, 2);
    push(&head, 1);
    head = printNthFromLast(head, 2);
    print(head);
}
