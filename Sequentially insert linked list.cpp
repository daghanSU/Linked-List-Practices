#include <iostream>

using namespace std;

struct Node{
	int data;
	Node* next;
};

Node* head = NULL;
Node* tail = NULL;

void addNodeSequentially(int data) {
	Node* temp = (Node*)malloc(sizeof(Node));
	temp->data = data;

	if (head == NULL) {
		temp->next = NULL;
		head = temp;
		tail = temp;
	}
	else {
		Node* iter = head;
		if (temp->data <= iter->data) {
			temp->next = iter;
			head = temp;
		}
		else {
			while (true) {
				if (iter->next == NULL) {
					temp->next = NULL;
					iter->next = temp;
					tail = temp;

					break;
				}
				else if (temp->data <= iter->next->data) {
					temp->next = iter->next;
					iter->next = temp;

					break;
				}
				else {
					iter = iter->next;
				}
			}
		}
	}
}

void showList() {
	Node* iter = head;
	while (iter != NULL) {
		cout << iter->data << " ";
		iter = iter->next;
	}
}

int main() {
	srand(time(0));

	unsigned int n;
	cout << "How much random numbers: ";
	cin >> n;

	for (int i = 0; i < n; i++) {
		unsigned int random = rand() % 100;
		addNodeSequentially(random);
	}

	showList();

	return 0;
}