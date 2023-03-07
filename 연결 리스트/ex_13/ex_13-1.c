#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int value;
	struct Node* next;
} Node;

Node* createNode(int value) {
	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->next = NULL;
	return newNode;
}

void addNode(Node** head, int value) {
	Node* newNode = createNode(value);

	if (*head == NULL) {
		*head = newNode;
	}
	else
	{
		Node* curr = *head;
		while (curr->next != NULL)
		{
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

void printList(Node* head) {
	if (head == NULL) {
		printf("List is empty\n");
	}
	else
	{
		Node* curr = head;
		while (curr != NULL)
		{
			printf("%d -> ", curr->value);
			curr = curr->next;
		}
		printf("NULL\n");
	}
}

int main(void) {
	Node* head = NULL;

	addNode(&head, 1);
	addNode(&head, 2);
	addNode(&head, 3);

	printList(head);

	Node* curr = head;
	while (curr != NULL)
	{
		Node* temp = curr;
		curr = curr->next;
		free(temp);
	}

	return 0;
}