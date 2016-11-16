#include <iostream>
#include "Classes.h"

int main()
{
	/////////////////// Bridge ////////////////////
	std::cout << "/////////////////// Bridge ////////////////////" << std::endl;
	ConcreteImplementorA implA;
	ConcreteImplementorB implB;

	RefinedAbstraction rabA(implA);
	RefinedAbstraction rabB(implB);

	rabA.operation();
	rabB.operation();

	////////////////// Iterator ///////////////////
	std::cout << std::endl;
	std::cout << "////////////////// Iterator ///////////////////" << std::endl;
	Stack s1; // Make object with initial "sp = -1"
	int i;
	for (i = 1; i < 5; i++) // Fill it with 4 values
		s1.push(i);
	// After loop, we have sp=3 value 
	// Make 4 objects of stack
	Stack s2(s1), s3(s1), s4(s1), s5(s1);
	s3.pop();	// -1 из s3(sp=2)
	s5.pop();	// -1 из s5(sp=2)
	s4.push(2);	// +1 в s4(sp=4)
	s5.push(9);	// +1 в s5(sp=3)
	std::cout << "1 == 2 is " << (s1 == s2) << std::endl; // 1
	std::cout << "1 == 3 is " << (s1 == s3) << std::endl; // 0
	std::cout << "1 == 4 is " << (s1 == s4) << std::endl; // 0
	std::cout << "1 == 5 is " << (s1 == s5) << std::endl; // 0
	std::cin.get();
	return 0;
}
