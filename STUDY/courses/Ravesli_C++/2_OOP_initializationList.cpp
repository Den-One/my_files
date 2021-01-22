#include <iostream>
#include <cstdint>

using namespace std;

class RGBA
{
private:
	uint8_t m_red;
	uint8_t m_green;
	uint8_t m_blue;
	uint8_t m_alpha;

public:
	RGBA(uint8_t a = 0, uint8_t b = 0, uint8_t c = 0, uint8_t d = 255)
		:m_red{a}, m_green{b}, m_blue{c}, m_alpha{d}
	{
	}

	void print()
	{
		cout << "r = " << static_cast<int>(m_red) <<
			" g = " << static_cast<int>(m_green) <<
			" b = " << static_cast<int>(m_blue) <<
			" a = " << static_cast<int>(m_alpha);
	}
};

int main()
{
	RGBA color(0, 135, 135);
	color.print();

}

// r=0 g=135 b=135 a=255
