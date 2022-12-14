#include <iostream>

int main()
{
	unsigned short n;
	setlocale(LC_ALL, "Rus");
	std::cout << "Введите положительное число: " << std::endl;
	std::cin >> n;
	unsigned short* a = &n;
	for (int i = 0; i < sizeof(short); i++)
	{
		unsigned char* b = (unsigned char*)a + i;
		std::cout << (short)*b << "  ";
	}
}