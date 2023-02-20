// C++ program to find modular node in a linked list
#include <bits/stdc++.h>
using namespace std;

/* Linked list node */
struct Node {
	int data;
	Node* next;
};

/* Function to create a new node with given data */
Node* newNode(int data)
{
	Node* new_node = new Node;
	new_node->data = data;
	new_node->next = NULL;
	return new_node;
}

/* Function to find modular node in the linked list */
Node* modularNode(Node* head, int k)
{
	// Corner cases
	if (k <= 0 || head == NULL)
		return NULL;

	// Traverse the given list
	int i = 1;
	Node* modularNode = NULL;
	for (Node* temp = head; temp != NULL; temp = temp->next) {
		if (i % k == 0)
			modularNode = temp;
		
		i++;
	}
	return modularNode;
}

/* Driver program to test above function */
int main(void)
{
	Node* head = newNode(1);
	head->next = newNode(2);
	head->next->next = newNode(3);
	head->next->next->next = newNode(4);
	head->next->next->next->next = newNode(5);
   // head->next->next->next->next->next = newNode(6);
	int k = 2;
	Node* answer = modularNode(head, k);
	cout<<"Modular node is ";
	if (answer != NULL)
		cout<<"\n"<< answer->data;
	else
		cout<<"null\n";
	return 0;
}

/*#include <bits/stdc++.h>
using namespace std;
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};
 /*
// Helper function to create a new node with the given data and
// pushes it onto the list's front
void push(struct Node** head, int data)
{
    // create a new linked list node from the heap
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
 
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
}
 
// Iterative function to return the k'th node from the end in a linked list
struct Node* findKthNode(struct Node* head, int k)
{
    int n = 0;
    struct Node* curr = head;
 
    // count the total number of nodes in the linked list
    while (curr)
    {
        curr = curr->next;
        n++;
    }
    // if the total number of nodes is more than or equal to `k`
    if (n >= k)
    {
        // return (n-k+1)'th node from the beginning
        curr = head;
        for (int i = 0; i < n - k; i++) {
            curr = curr->next;
        }
    }
 
    return curr;
}
 
int main(void)
{
    // input keys
    int keys[] = { 1, 2, 3, 4, 5 };
    int n = sizeof(keys) / sizeof(keys[0]);
 
    struct Node* head = NULL;
    for (int i = n - 1; i >= 0; i--) {
        push(&head, keys[i]);
    }
 
    int k = 3;
    struct Node* node = findKthNode(head, k);
 
    if (node) {
        cout<<"k'th node from the end is "<< node->data;
    }
 
    return 0;
}
*/