//栈可以用来反转字符串和链表
//这里使用 stl 中的stack
#include<iostream>
#include<stack>


struct Node
{
	int data;
	Node* next;
};
Node* head;

void Insert_LinkedList(int x) // 尾插法
{
	Node* temp = new Node();
	temp->data = x;
	temp->next = head;
	head = temp;
}

void Print_LinkedList()
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

// 使用 stack 来反转 字符串
// 也可以使用双指针进行遍历
void Reverse_String(char *C, int n)
{
	std::stack<char> S;
	// loop for push
	for (int i = 0;i < n;i++)
	{
		S.push(C[i]);
	}
	// loop for pop
	for (int i = 0;i < n;i++)
	{
		C[i] = S.top(); // overwrite the character at index i.
		S.pop(); // perform pop.
	}
}

// 使用 stack 来反转 链表
void Reverse_LinkedList()
{
	if (head == NULL) return;
	std::stack<Node*> S;
	Node* temp = head;
	while (temp != nullptr)
	{
		S.push(temp);
		temp = temp->next;
	}
	temp = S.top();
	head = temp;
	S.pop();
	while (!S.empty())
	{
		temp->next = S.top();
		S.pop();
		temp = temp->next;
	}
	temp->next = nullptr;
}

int main()
{

	/*char C[51];
	printf("Enter a string: ");
	gets_s(C);
	Reverse_String(C, strlen(C));
	printf("Output = %s", C);*/

	printf("How many numbers?\n");
	int n, i, x;
	scanf_s("%d",&n);
	for (i = 0;i < n;i++)
	{
		printf("Enter the number \n");
		scanf_s("%d",&x);
		Insert_LinkedList(x);
		Print_LinkedList();
		std::cin.get();
	}
	Reverse_LinkedList();
	printf("Reverse LinkedList: \n");
	Print_LinkedList();

	std::cin.get();
}