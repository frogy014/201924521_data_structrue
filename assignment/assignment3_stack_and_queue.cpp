/*
�ؾ��� ��
1. Eval �Լ� ����
	���ڴ� stack��, operand�� �Ἥ ����
2. Postfix ����
	�Ѱ��� ���ڸ� ����ϴ� ���� �������� ���ڿ��� �����ϵ���
3. Eval �Լ� ����
	1���� 2���� ��ģ��

	����� ��ũ: https://github.com/frogy014/201924521_data_structrue/blob/main/assignment/assignment3_stack_and_queue.cpp
*/





#include <iostream>
#include <memory>

using namespace std;

template <class T>
class Stack {
public:
	Stack(int stackCapacity = 10);
	bool IsEmpty() const;
	T& Top() const;
	void Push(const T& item);
	void Pop();
private:
	T* stack;
	int top;
	int capacity;
};

template <class T>
Stack<T>::Stack(int stackCapacity) : capacity(stackCapacity) {
	if (capacity < 1) throw "Stack capacity must be > 0";
	stack = new T[capacity];
	top = -1;
}

template <class T>
void ChangeSizeID(T*& a, const int oldSize, const int newSize) {
	if (newSize < 0) throw "New length must be >=0";

	T* temp = new T[newSize];
	int number = oldSize;
	if (oldSize > newSize) number = newSize;
	//copy(a, a+number, temp);
	memcpy(temp, a, number);
	delete[] a;
	a = temp;
}

template <class T>
inline bool Stack<T>::IsEmpty() const { return top == -1 };

template <class T>
inline T& Stack<T>::Top() const
{
	if (top == capacity - 1)
	{
		ChangeSizeID(stack, capacity, 2 * capacity);
		capacity *= 2;
	}
	stack[++top] = x;
}

template <class T>
void Stack<T>::Pop()
{
	if (IsEmpty()) throw "Stack is empty. Cannot delete.";
	stack[top--]. - T();
}



typedef char* Expression;
typedef char Token;
using namespace std;

int index = 0;

char NextToken(char* e) {
	char token = e[index];
	index++;
	return token;
}

bool isOperand(char x)
{
	if (x == '+' || x == '-' || x == '*' || x == '/' ||
		x == '(' || x == ')' || x == '%' || x == '#')
		return false;
	else
		return true;
}

int isp(char a) {
	if (a == '(')											
		return 0;											//���� ��ȣ
	else if (a == ')')										//������ ��ȣ
		return 19;
	else if (a == '+' || a == '-')							//priority 1
		return 12;
	else if (a == '*' || a == '%' || a == '/')				//priority 2
		return 12;
	else
		return 0;
}

int icp(char a) {
	if (a == '(')
		return 20;											//���� ��ȣ
	else if (a == ')')										//������ ��ȣ
		return 19;
	else if (a == '+' || a == '-')							//priority 1
		return 12;
	else if (a == '*' || a == '%' || a == '/')				//priority 2
		return 12;
	else
		return 0;
}

Expression Postfix(Expression e) {

	Stack<char> stack;
	stack.Push ('#');
	for (char x = NextToken(e); x != NULL;x = NextToken(e))
	{
		//cout << "x= " << x << endl;
		if (isOperand(x))
			cout << x;
		else  if (x == ')')
		{
			while (stack.Top() != '(')
			{
				cout << stack.Top();
				stack.Pop();
			}
			stack.Pop();
		}
		else {
			for (;isp(stack.Top()) >= icp(x);stack.Pop())
				cout << stack.Top();
			stack.Push(x);
		}
	}
	char x;
	while ((x = stack.Top()) != '#')
	{
		cout << x;
		stack.Pop();		
	}
	cout << endl;
}

void Eval(Expression e) {
	Stack<Token> stack;
	stack.Push('#');
	for (Token x = NextToken(e); x != '#';x = NextToken(e))
		if (isOperand(x)) stack.Push(x);
		else {
			//�����ؾ���
		}
}

void main() {
	index = 0;
	Expression infix, postfix;
	scanf("%s", infix);
	cout << infix << endl;
	postfix = Postfix(infix);
	Eval(postfix);
	cout << postfix << endl;
}
