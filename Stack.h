#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include <cstring>
#include <sstream>

using namespace std;

template <class T>
struct Node {

	T data;
	Node* next;

};

template <class T>
class Stack {

private:
	Node<T>* top;
	Node <T>* bottom;


public:

	Stack() : top(NULL), bottom(NULL) {}

	~Stack() 
	{
		Node<T>* current = bottom;

		while (bottom != NULL) 
		{
			current = bottom;
			bottom = bottom->next;
			delete current;
		}

		top = NULL;
	}

	void Push(T dataitem)
	{
		Node<T>* newnode = new Node<T>;
		newnode->data = dataitem;
		newnode->next = NULL;

		if (bottom == NULL && top == NULL) 
		{
			bottom = newnode;
			top = newnode;

			return;
		}

		top->next = newnode;
		top = newnode;

	}

	T Pop()
	{
		T value;
		if (bottom == NULL)
		{
			cout << "Stack is Empty." << endl;
			return 0;
		}

		else if (bottom->next == NULL)
		{

			value = top->data;

			delete top;

			bottom = NULL;
			top = NULL;

			return value;
		}

		else
		{
			Node<T>* current = new Node <T>;
			current = bottom;

			while (current->next != top)
			{
				current = current->next;
			}
			
			value = top->data;
			delete top;
			top = current;
			top->next = NULL;
			
			return value;
		}
		
	}

	void clear() 
	{
		while (top != NULL) 
		{
			this->Pop();
		}
	}

	bool isEmpty() 
	{
		if (top == NULL)
			return true;

		return false;
	}
	T Top()
	{
		if (!isEmpty())
		{
			return top->data;
		}
	}

	void Display() 
	{
		Node<T>* temp = bottom;

		while (temp != NULL) 
		{
			cout << temp->data << " ";
			temp = temp->next;
		}

		cout << endl;
	}



};

bool delimitersOk(const string exp)
{
	Stack<char> obj;
	int len = exp.length();
	char str;

	if (len == 0)
	{
		cout << "String is empty"<<"\t";
		return false;
	}

	else
	{
		int i = 0;
		while (exp[i] != '\0')
		{
			if (exp[i] == '[' or exp[i] == '{' or exp[i] == '(')
			{
				obj.Push(exp[i]);
			}

			else if (exp[i] == ']' or exp[i] == '}' or exp[i] == ')')
			{
				if (obj.isEmpty())
					return false;

				str = obj.Pop();

				if (exp[i] == ']') {
					if (str != '[')
						return false;
				}

				if (exp[i] == ')') {
					if (str != '(')
						return false;
				}

				if (exp[i] == '}') {
					if (str != '{')
						return false;
				}
			}

			i++;
		}

		if (!obj.isEmpty())
			return false;

		return true;
	}
}

int Prec(char c)
{
	
	switch (c) 
	{
	case '$': return 3;
		break;
	
	case '*': return 2;
		break;
	case '/': return 2;
		break;

	case '+': return 1;
		break;
	case '-': return 1;
		break;

	default : return -1;
	}
}
 
string InfixToPostfix(string exp)
{
	Stack<char> str;
	str.Push('~');
	int len = exp.length();
	string temp;

	for (int i = 0; i < len; i++)
	{ 
		if ((exp[i] >= 'a' and exp[i] <= 'z') or (exp[i] >= 'A' and exp[i] <= 'Z') or (exp[i] >= '0' and exp[i] <= '9'))
		{
			temp += exp[i];
		}	
		else if (exp[i] == '(')
		{
			str.Push('(');
		}
		
		else if (exp[i] == ')')
		{
			while (str.Top() != '~' and str.Top() != '(')
			{
				char s = str.Top();
				str.Pop();
				temp += s;
			}
			if (str.Top() == '(')
			{
				char s = str.Top();
				str.Pop();
			}
		}

		else 
		{
			while (str.Top() != '~' and Prec(exp[i]) <= Prec(str.Top()))
			{
				char s = str.Top();
				str.Pop();
				temp += s;
			}
			str.Push(exp[i]);
		}

	} 
	while (str.Top() != '~')
	{
		char s = str.Top();
		str.Pop();
		temp += s;
	}

		return temp;
}

int convertToInt(string str) 
{
	stringstream ss(str);
	int val;
	ss >> val;
	return val;
}

string convertToString(int val) 
{
	stringstream ss;
	ss << val;
	string str = ss.str();
	return str;
}

string evaluateExp (string opnd1, string opnd2, string symb) 
{
	int op1 = convertToInt(opnd1);
	int op2 = convertToInt(opnd2);

	int result = 0;
	string res;

	switch (symb[0]) 
	{
		case '+':
			result = op1 + op2;
			break;

		case '-':
			result = op1 - op2;
			break;

		case '*':
			result = op1 * op2;
			break;

		case '/':
			result = op1 / op2;
			break;

		case '$':
			result = pow(op1, op2);
			break;
		default:
			cout << "Error\n";
	}

	res = convertToString(result);
	return res;
}

int evaluatePostfix(string exp) 
{
	Stack<string> obj;
	int i = 0;
	string symb;
	 
	while (exp[i] != '\0') 
	{
		symb.clear();
		symb += exp[i];

		if (symb[0] != '+' and symb[0] != '-' and symb[0] != '*' and symb[0] != '/' and symb[0] != '$')
			obj.Push(symb);

		else 
		{
			string opnd2 = obj.Pop();
			string opnd1 = obj.Pop();

			string value = evaluateExp(opnd1, opnd2, symb);

			obj.Push(value);
		}

		i++;
	}

	int result = convertToInt(obj.Pop());
	return result;
} 