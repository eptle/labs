#include <iostream>

class Rectangle
{
private:
	int m_a = 0;
	int m_b = 0;
	int m_perimeter = 0;

public:
	void Perimeter(int a, int b)
	{
		if (a > 0 and b > 0)
		{
			m_a = a;
			m_b = b;
			m_perimeter = 2 * (m_a + m_b);
			std::cout << "Petimeter = " << m_perimeter << std::endl;
		}
		else
			std::cout << "Wrong values" << std::endl;
	}
};

int main()
{
	int a, b;
	std::cin >> a;
	std::cin >> b;
	Rectangle Rect1;
	Rect1.Perimeter(a, b);
}