#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* next;
    Node(int x) : data(x), next(NULL) {}
    //Node() : data(0), next(NULL) {}
};

void push_head(struct Node** head_ref, int new_data)
{
    /* allocate node */
    struct Node* new_node;

    /* put in the data */
    new_node->data = new_data;

    /* link the old list off the new node */
    new_node->next = *head_ref;
    *head_ref = new_node;
    return;
}

void push(struct Node** head_ref, int new_data)
{
    if (*head_ref == NULL) {
	*head_ref = new Node(new_data);
	return;
    }
    struct Node* new_node = new Node(new_data);
    struct Node* headRef = *head_ref;
    while (headRef->next != NULL) {
	headRef = headRef->next;
    }
    headRef->next = new_node;
}

void MoveNode(struct Node** dstRef, struct Node** srcRef)
{
    struct Node* newNode = *srcRef;

    /* Advance the src pointer */
    *srcRef = newNode->next;

    /* Link the old dest off the newNode */
    newNode->next = *dstRef;

    *dstRef = newNode;

}

void printList(struct Node* node)
{
    while (node != NULL) {
	cout << node->data << " ";
	node = node->next;
    }
}

struct Node* mergeTwoLinkedList(struct Node* a, struct Node* b)
{
    struct Node* result = NULL;
    struct Node** lastPtrRef = &result;

    while (a != NULL && b != NULL) {
	
	if (a->data <= b->data) {
	    MoveNode(lastPtrRef, &a);
	}
	else {
	    MoveNode(lastPtrRef, &b);
	}
	lastPtrRef = &((*lastPtrRef)->next);
    }
    if (a != NULL) {
	*lastPtrRef = a;
    }
    else {
	*lastPtrRef = b;
    }
    return result;
}

int main()
{
    struct Node* a = NULL;
    struct Node* b = NULL;
    struct Node* res = NULL;
    //push(&a, 9);
    //push(&a, 4);
    push(&a, 2);
    push(&a, 6);

    //push(&b, 8);
    //push(&b, 7);
    push(&b, 3);
    push(&b, 5);

    res = mergeTwoLinkedList(a, b);
    printList(res);
    return 0;
}
