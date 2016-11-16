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
	Stack s1; // Созддаём объект стека с начальной глубиной -1
	int i;
	for (i = 1; i < 5; i++) // Заполняе его 4 значениями
		s1.push(i);
	// После цикла sp=3 значения 
	// Создаём ещё 4 объекта стека
	Stack s2(s1), s3(s1), s4(s1), s5(s1);
	s3.pop();	// -1 из s3(sp=2 значения)
	s5.pop();	// -1 из s5(sp=2 значения)
	s4.push(2);	// +1 в s4(sp=4 значений)
	s5.push(9);	// +1 в s5(sp=3 значений)
	std::cout << "1 == 2 is " << (s1 == s2) << std::endl; // 1
	std::cout << "1 == 3 is " << (s1 == s3) << std::endl; // 0
	std::cout << "1 == 4 is " << (s1 == s4) << std::endl; // 0
	std::cout << "1 == 5 is " << (s1 == s5) << std::endl; // 0
	std::cin.get();
	return 0;
}
