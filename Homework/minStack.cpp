#include <iostream>
#include <stack>
#include <string>
#include <sstream>
using namespace std;

 
struct Stack
{
	stack<int> s;
	int min;

	
	void getMin()
	{
		if (s.empty())
			throw std::underflow_error("Stack is empty");

		else
			cout << min << "\n";
	}

	void peek()
	{
		if (s.empty())
		{
			throw std::underflow_error("Stack is empty");
			return;
		}
		int t = s.top(); 		
		(t < min) ? cout << min : cout << t;
		cout << "\n";
	}

	
	void pop()
	{
		if (s.empty())
		{
			throw std::underflow_error("Stack is empty");
			return;
		}

		int t = s.top();
		s.pop();

		if (t < min)
		{			
			min = 2 * min - t;
		}		
	}

	
	void push(int x)
	{
		
		if (s.empty())
		{
			min = x;
			s.push(x);
			return;
		}
				
		if (x < min)
		{
			s.push(2 * x - min);
			min = x;
		}

		else
			s.push(x);

	}
};

int main()
{
	Stack s;
	size_t n;
	cin >> n;
	int el;
	for (size_t i = 0; i <= n; i++) {
		string line;
		getline(cin, line);
		istringstream insert(line);
		string command;
		insert >> command;
		if (command == "push") {
			insert >> el;
			s.push(el);
		}
		if (command == "pop") {
			s.pop();
		}
		if (command == "peek") {
			s.peek() ;
		}
		if (command == "min") {
			s.getMin();
		}
	}
	system("pause");
}
