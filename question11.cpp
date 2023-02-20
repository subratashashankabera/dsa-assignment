#include <iostream>

using namespace std;

class LinkedList {
private:
	class Node {
	public:
		int data;
		Node* next;

		Node(int data) {
			this->data = data;
			this->next = nullptr;
		}
	};

	Node* head;

public:
	LinkedList() {
		head = nullptr;
	}

	void addToFront(int data) {
		Node* newNode = new Node(data);
		newNode->next = head;
		head = newNode;
	}

	bool isCircular() {
		if (head == nullptr) {
			return false;
		}
		Node* slow = head;
		Node* fast = head->next;
		while (fast != nullptr && fast->next != nullptr) {
			if (slow == fast) {
				return true;
			}
			slow = slow->next;
			fast = fast->next->next;
		}
		return false;
	}
};

int main() {
	LinkedList list;
	list.addToFront(4);
	list.addToFront(3);
	list.addToFront(2);
	list.addToFront(1);
    list.addToFront(5);
    
	cout << boolalpha << list.isCircular() << endl;
	return 0;
}
