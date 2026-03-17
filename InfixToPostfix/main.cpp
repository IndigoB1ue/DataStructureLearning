#include<iostream>
#include<string>
#include<stack>
#include<sstream>

// 判断优先级
int precedance(char op)
{
	if (op == '+' || op == '-') return 1;
	if (op == '*' || op == '/') return 2;
	return 0;
}

// 中缀转后缀
std::string infixToPostfix(std::string expr)
{
	// 创建栈
	std::stack<char> st;
	std::string result = "";

	for (char ch : expr)
	{
		// 1. 操作数
		if (std::isalnum(ch))
		{
			result += ch;
		}

		// 2. 左括号
		else if (ch == '(')
		{
			st.push(ch);
		}

		// 3. 右括号
		else if (ch == ')')
		{
			while (!st.empty() && st.top() != '(')
			{
				result += st.top();
				st.pop();
			}
			st.pop(); // 弹出 '('
		}

		// 4. 运算符
		else
		{
			while (!st.empty() && precedance(st.top()) >= precedance(ch))
			{
				result += st.top();
				st.pop();
			}
			st.push(ch);
		}
	}

	while (!st.empty())
	{
		result += st.top();
		st.pop();
	}

	return result;
}

// 后缀表达式
int evaluatePostfix(std::string expr)
{
	std::stack<int> st;
	std::stringstream ss(expr);
	std::string token;

	while (ss >> token)
	{
		if (std::isdigit(token[0]))
		{
			st.push(std::stoi(token));
		}
		else
		{
			int b = st.top(); st.pop();
			int a = st.top(); st.pop();

			if (token == "+") st.push(a + b);
			else if (token == "-") st.push(a - b);
			else if (token == "+") st.push(a + b);
			else if (token == "*") st.push(a * b);
			else if (token == "/") st.push(a / b);
		}
	}
	return st.top();
}

int main()
{
	std::string expr = "1+2*3";
	std::cout << infixToPostfix(expr) << std::endl;

	std::string expr1 = "3 4 + 2 * 7 /";
	std::cout << evaluatePostfix(expr1) << std::endl;

	std::cin.get();
}