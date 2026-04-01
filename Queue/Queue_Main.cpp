#include<iostream>
#define MAXSIZE 100

// 使用数组实现一个队列
// 循环队列
class CircularQueue
{
private:
	int* data;
	int front;
	int rear;
	int capacity;

public:
	// 构造函数
	CircularQueue(int size)
	{
		capacity = size;
		data = new int[capacity];
		front = 0;
		rear = 0;
	}

	// 队列满了
	bool isFull()
	{
		return (rear + 1) % capacity == front; // 浪费一个空间,用来确定是否满了
	}

	// 队列空了
	bool isEmpty()
	{
		return rear == front;
	}

	// 入队
	void enqueue(int value)
	{
		if (isFull())
		{
			std::cout << "队列满了" << std::endl;
			return;
		}
		data[rear] = value;
		rear = (rear + 1) % capacity; // 循环队列
	}

	// 出队
	void dequeue()
	{
		if (isEmpty())
		{
			std::cout << "队列空了" << std::endl;
			return;
		}
		std::cout << "出队元素: " << data[front] << std::endl;
		front = (front + 1) % capacity;
	}

	// 查看队头
	int peek()
	{
		if (isEmpty())
		{
			std::cout << "队列为空" << std::endl;
			return -1;
		}
		return data[front];
	}
};


// 使用链表实现一个队列
struct Node
{
	int data;
	Node* next;
};

class LinkedQueue
{
private:
	Node* front;
	Node* rear;

public:
	LinkedQueue()
	{
		front = nullptr;
		rear = nullptr;
	}

	// 入队
	void enqueue(int value)
	{
		Node* newNode = new Node;
		newNode->data = value;
		newNode->next = nullptr;

		if (rear == nullptr)
		{
			front = rear = newNode;
		}
		else
		{
			rear->next = newNode;
			rear = newNode;
		}
	}

	// 出队
	void dequeue()
	{
		if (isEmpty())
		{
			std::cout << "队列为空" << std::endl;
			return;
		}

		Node* temp = front;
		std::cout << "出队元素: " << temp->data <<std::endl;
		
		front = front->next;

		if (front == nullptr)
			rear == nullptr;

		delete temp;
	}

	// 查看队头
	int peek()
	{
		if (isEmpty())
		{
			std::cout << "队列为空" << std::endl;
			return -1;
		}
		return front->data;
	}

	bool isEmpty()
	{
		return front == nullptr;
	}
};

int main()
{
	CircularQueue q(5);

	q.enqueue(10);
	q.enqueue(20);
	q.enqueue(30);
	q.enqueue(40);

	q.dequeue();
	q.dequeue();

	q.enqueue(50);
	q.enqueue(60);

	std::cout << "队头元素: " << q.peek() << std::endl;;


	std::cout << "--------------------------" << std::endl;;


	LinkedQueue lq;
	lq.enqueue(1);
	lq.enqueue(2);
	lq.enqueue(3);

	std::cout << "队头元素: " << lq.peek() << std::endl;;

	std::cin.get();
}