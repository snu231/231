#include <iostream>



int main()	
	{
		int a[5];
		int b;


		for(b=0; b<5;b++)

		{

			*(a+b) = b;

			std::cout << *(a+b) << " ";

		}

		std::cout << "숫자를 입력하시오";
		std::cin >> b;

		std::cout << a[b];
		
		return 0;
	}

