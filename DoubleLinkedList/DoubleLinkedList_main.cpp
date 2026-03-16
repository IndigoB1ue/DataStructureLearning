// 双向链表
#include<iostream>

struct Node
{
	int data;
	Node* prev;
	Node* next;
};

// 全局变量
Node* head;

Node* GetNewNode(int x)
{
	Node* myNode = new Node();
	myNode->data = x;
	myNode->prev = nullptr;
	myNode->next = nullptr;
	return myNode;
}

void InsertAtHead(int x)
{
	Node* newNode = GetNewNode(x);
	if (head == nullptr)
	{
		head = newNode;
		return;
	}
	head->prev = newNode;
	newNode->next = head;
	head = newNode;
}


void Print()
{
	Node* temp = head;
	
	printf("Forward: ");
	while (temp != nullptr)
	{
		printf("%d ", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void ReversePrint()
{
	Node* temp = head;
	if (temp == nullptr) return; // list is empty

	while (temp->next != nullptr)
	{
		temp = temp->next;
	}
	printf("Reverse: ");
	while (temp != nullptr)
	{
		printf("%d ", temp->data);
		temp = temp->prev;
	}
	printf("\n");
}

int main()
{
	InsertAtHead(1);Print();ReversePrint();
	InsertAtHead(3);Print();ReversePrint();
	InsertAtHead(5);Print();ReversePrint();

	std::cin.get();
}