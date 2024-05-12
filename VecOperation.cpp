#include <iostream>
#include <conio.h>
#include <math.h>

struct vector
{
	double x;
	double y;
};

// Функция ввода вектора. Ограничим координаты вектора 100.
void enterVector(vector& vec, int number)
{
	std::cout << "Enter coordinates of vector " << number << "\nX: ";
	std::cin >> vec.x;
	while (vec.x < -100 || vec.x > 100)
	{
		std::cout << "Incorrect input. Repeat please.\n";
		std::cin >> vec.x;
	}
	std::cout << "Y: ";
	std::cin >> vec.y;
	while (vec.y < -100 || vec.y > 100)
	{
		std::cout << "Incorrect input. Repeat please.\n";
		std::cin >> vec.y;
	}
}

// Функция сложения векторов. Просто выводим сумму.
void addition(vector& vec1, vector& vec2)
{
	std::cout << "The total vector is equal to: {" << vec1.x + vec2.x << ", " << vec1.y + vec2.y << "}\n";
}

// Функция вычитания векторов. Выводим разность векторов
void subtraction(vector& vec1, vector& vec2)
{
	std::cout << "The total vector is equal to: {" << vec1.x - vec2.x << ", " << vec1.y - vec2.y << "}\n";
}

// Функция умножения векторов на число
void scaling(vector& vec1, vector& vec2)
{
	double number;
	std::cout << "Enter number for scalling: ";
	std::cin >> number;
	vec1.x *= number;
	vec1.y *= number;
	vec2.x *= number;
	vec2.y *= number;
}

// Функция определения длины векторов
double detLength(vector& vec)
{
	return sqrt(std::pow(vec.x, 2) + std::pow(vec.y, 2));
}

// Функция нормализации векторов, т.е. делим каждую координату на длину вектора
void normalization(vector& vec1, vector& vec2)
{
	vec1.x /= detLength(vec1);
	vec1.y /= detLength(vec1);
	vec2.x /= detLength(vec2);
	vec2.y /= detLength(vec2);
}

// Главная функция. Меню работы с векторами.
int main()
{
	vector operand1{};
	vector operand2{};
	char action;
	
	while(true)
	{
		std::cout << "We have vectors:\nVector 1: {" << operand1.x << ", " << operand1.y << "}\n" << \
			"Vector 2: {" << operand2.x << ", " << operand2.y << "}\n\n" << \
			"E - Enter / change vectors\n+ - Adding vectors\n" << \
			"- - Substract vectors\n* - Scaling vectors\nN - Normalization of vector\n" << \
			"L - Length of vector\nB - Bye\nChoice action: ";
		std::cin.clear();
		std::cin >> action;
		
		if (action == 'E' || action == 'e')
		{
			enterVector(operand1, 1);
			enterVector(operand2, 2);
		}
		else if (action == '+')
			addition(operand1, operand2);
		else if (action == '-')
			subtraction(operand1, operand2);
		else if (action == '*')
			scaling(operand1, operand2);
		else if (action == 'N' || action == 'n')
			normalization(operand1, operand2);
		else if (action == 'L' || action == 'l')
		{
			std::cout << "Length of vector 1: " << detLength(operand1) << '\n';
			std::cout << "Length of vector 2: " << detLength(operand2) << '\n';
		}
		else if (action == 'B' || action == 'b')
		{
			std::cout << "Thank you for use my program. Bye bye!\n";
			return 0;
		}
		else
			std::cout << "Unknown action. Repeat choice\n";
		std::cout << "Press any key ...";
		while (!_kbhit());
		std::cout << "\x1B[2J\x1B[H";
	}
}