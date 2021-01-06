#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <ctime>
using namespace std;

int main()
{
	int q = 1;
		while (q != 0)
		{
			srand(static_cast<unsigned int>(time(0)));

			for (int count = 0; count < 100; ++count)
			{
				std::cout << rand() << "\t";

				// Åñëè âûâåëè 5 ÷èñåë, òî âñòàâëÿåì ñèìâîë íîâîé ñòðîêè
				if ((count + 1) % 5 == 0)
					std::cout << "\n";
			}

		_getch();
		}
	return 0;
}
