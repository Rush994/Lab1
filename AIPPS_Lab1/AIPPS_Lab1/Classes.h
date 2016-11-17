#include <iostream>


/////////////////////////////////////
///////////// Bridge ////////////////
class Implementor
{
public:
	virtual void implementation() = 0;
};

class ConcreteImplementorA : public Implementor
{
public:
	void implementation() override
	{
		std::cout << "ConcreteImplementorA::operation" << std::endl;
	}
};

class ConcreteImplementorB : public Implementor
{
public:
	void implementation() override
	{
		std::cout << "ConcreteImplementorB::operation" << std::endl;
	}
};

class Abstraction
{
protected:
	Implementor & implementor;
public:
	Abstraction(Implementor & impl) : implementor(impl) {}

	virtual void operation()
	{
		implementor.implementation();
	}
};

class RefinedAbstraction : public Abstraction
{
public:
	RefinedAbstraction(Implementor & impl) : Abstraction(impl)
	{}

	void operation() override
	{
		implementor.implementation();
	}
};

////////////////////////////////
///////// Iterator /////////////
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