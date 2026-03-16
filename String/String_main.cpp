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

// 使用 stack 来反转 字符串
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

// 使用 stack 来反转链表
void ReverseLinkedListByStack()
{
	if (head == NULL) return;
	std::stack<Node*> S;
	Node* temp = head;
}

int main()
{
	char C[51];
	printf("Enter a string: ");
	gets_s(C);
	Reverse_String(C, strlen(C));
	printf("Output = %s", C);
	std::cin.get();
}