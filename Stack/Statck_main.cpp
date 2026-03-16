
struct Node
{
	int data;
	Node* link;
};
Node* top = nullptr;

void Push(int x)
{
	Node* temp = new Node();
	temp->data = x;
	temp->link = top;
	top = temp;
}

void Pop()
{
	Node* temp;
	if (top == nullptr) return;
	temp = top; // 用 temp 来保存前一个节点的地址来释放内存
	top = top->link;
	delete temp;
}

int main()
{

}