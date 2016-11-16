#include <iostream>

class Stack
{
	int items[10];
	int sp;
public:
	friend class StackIter;
	Stack()
	{
		sp = -1;
	}
	void push(int in)
	{
		items[++sp] = in;
	}
	int pop()
	{
		return items[sp--];
	}
	bool isEmpty()
	{
		return (sp == -1);
	}
};

class StackIter
{
	const Stack &stk;
	int index;
public:
	StackIter(const Stack &s) : stk(s)
	{
		index = 0;
	}
	void operator++()
	{
		index++;
	}
	bool operator()()
	{
		return index != stk.sp + 1;
	}
	int operator *()
	{
		return stk.items[index];
	}
};

bool operator == (const Stack &l, const Stack &r)
{
	StackIter itl(l), itr(r);
	for (; itl(); ++itl, ++itr)
	if (*itl != *itr)
		break;
	return !itl() && !itr();
}

int main()
{
	Stack s1; // Make object with initial "sp = -1"
	int i;
	for (i = 1; i < 5; i++) // Fill it with 4 values
		s1.push(i);
	// After loop, we have sp=3 value 
	// Make 4 objects of stack
	Stack s2(s1), s3(s1), s4(s1), s5(s1);
	s3.pop();	// -1 �� s3(sp=2)
	s5.pop();	// -1 �� s5(sp=2)
	s4.push(2);	// +1 � s4(sp=4)
	s5.push(9);	// +1 � s5(sp=3)
	std::cout << "1 == 2 is " << (s1 == s2) << std::endl; // 1
	std::cout << "1 == 3 is " << (s1 == s3) << std::endl; // 0
	std::cout << "1 == 4 is " << (s1 == s4) << std::endl; // 0
	std::cout << "1 == 5 is " << (s1 == s5) << std::endl; // 0
	std::cin.get();
	return 0;
}
