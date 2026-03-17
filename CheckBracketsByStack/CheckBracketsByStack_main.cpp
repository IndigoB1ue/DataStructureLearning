#include<iostream>
#include<stack>

bool isValid(std::string s)
{
	std::stack<char> st;

	for (char c : s)
	{
		// 左括号入栈
		if (c == '(' || c == '{' || c == '[')
		{
			st.push(c);
		}
		else
		{
			// 栈为空直接失败
			if (st.empty()) return false;

			char top = st.top();
			if ((c == ')' && top == '(') ||
				(c == '}' && top == '{') ||
				(c == ']' && top == '['))
			{
				st.pop();
			}
			else
			{ 
				return false;
			}
		}
	}

	// 最后栈必须为空
	return st.empty();
}



int main()
{
	std::string s = "{[()]}";
	std::cout << (isValid(s) ? "匹配" : "不匹配") << std::endl;

	std::cin.get();
}