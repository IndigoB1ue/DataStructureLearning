#include<iostream>


struct Node
{
	int data;
	Node* next;
};
Node* head;


void Insert(int x) // 尾插法
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Insert(int data, int n) // 任意位置插入
{
	Node* temp1 = new Node();
	temp1->data = data;
	temp1->next = NULL;

	if (n == 1)
	{
		temp1->next = head;
		head = temp1;
		return;
	}

	Node* temp2 = head;
	for (int i = 0;i < n - 2;i++)
	{
		temp2 = temp2->next;
	}
	temp1->next = temp2->next;
	temp2->next = temp1;
}

void Delete(int n)
{
	Node* temp1 = head;
	
	if (n == 0) return;

	if (n == 1)
	{
		head = temp1->next;
		delete(temp1);
		return;
	}

	for (int i = 0;i < n - 2;i++)
	{
		temp1 = temp1->next; // 前结点 = 后结点
	}
	Node* temp2 = temp1->next;
	temp1->next = temp2->next;
	delete(temp2);
}

void Reverse()
{
	Node *current, *prev, *next;
	current = head;
	prev = NULL;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head = prev;
}

void Reverse_Digui(Node* p)
{
	if (p->next == NULL)
	{
		head = p;
		return;
	}
	Reverse_Digui(p->next);
	Node* q = p->next;
	q->next = p;
	p->next = NULL;
}



void Print()
{
	Node* temp = head;
	printf("List is: ");
	while (temp != NULL)
	{
		printf(" %d", temp->data);
		temp = temp->next;
	}
	printf("\n");
}

void Print_Digui(Node* p)
{
	if (p == NULL)
	{
		printf("\n");
		return;
	}
	printf("%d ", p->data);
	Print_Digui(p->next);
	//printf("%d ", p->data);
}


int main()
{
	
	head = NULL; //  lsit is empty

	/*printf("How many numbers?\n");
	int n, i, x;
	scanf_s("%d",&n);
	for (i = 0;i < n;i++)
	{
		printf("Enter the number \n");
		scanf_s("%d",&x);
		Insert(x);
		Print();
		std::cin.get();
	}*/

	Insert(2, 1);
	Insert(3, 2);
	Insert(4, 1);
	Insert(1, 2);
	Insert(5, 3); // 4 1 5 2 3

	/*Print();
	int n;
	std::cout << "Enter a position " << std::endl;
	std::cin >> n;
	Delete(n);
	Print();*/

	/*Print();
	Reverse();
	Print();*/

	Print_Digui(head);
	Reverse_Digui(head);
	Print_Digui(head);

	std::cin.get();
	std::cin.get();
}