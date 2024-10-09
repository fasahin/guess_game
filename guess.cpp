#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <time.h>
using namespace std;
int s[4];

int main(int argc, char* argv)
{
	bool falsein = true;
	bool result = false;
	string g;
	int x;
	int plus = 0;
	int minus = 0;
	int count = 0;
	int t[4];
	srand(time(0));
	while (s[3] == s[2] || s[3] == s[1] || s[3] == s[0] || s[2] == s[1] || s[2] == s[0] || s[1] == s[0] || s[0] == 48)
	{
		s[0] = (rand() % 10) + 48;
		s[1] = (rand() % 10) + 48;
		s[2] = (rand() % 10) + 48;
		s[3] = (rand() % 10) + 48;
	}
	cout << "I kept a four-digit number in my mind. \n";
	cout << "Can you find the number? \n";
	cout << "Enter your guess please .. \n";

	while (!result)
	{
		g = "";
		plus = 0;
		minus = 0;
		falsein = true;
		while (falsein)
		{
			cin >> g;
			if (g.length() != 4 || g[0] == 48 || g[0] == g[1] || g[0] == g[2] || g[0] == g[3] || g[1] == g[2] || g[1] == g[3] || g[2] == g[3] || g[0] > 57 || g[0] < 48 || g[1]>57 || g[1] < 48 || g[2]>57 || g[2] < 48 || g[3]>57 || g[3] < 48)
			{
				cout << "Wrong enter, please try again.. \n";
			}
			else
			{
				falsein = false;
			}
		}
		count++;
		if (g[0] == s[0]) plus++;
		if (g[1] == s[1]) plus++;
		if (g[2] == s[2]) plus++;
		if (g[3] == s[3]) plus++;
		if (g[0] == s[1] || g[0] == s[2] || g[0] == s[3])minus++;
		if (g[1] == s[0] || g[1] == s[2] || g[1] == s[3])minus++;
		if (g[2] == s[0] || g[2] == s[1] || g[2] == s[3])minus++;
		if (g[3] == s[0] || g[3] == s[1] || g[3] == s[2])minus++;
		cout << count << "\t + " << plus << " \t - " << minus << "\n";
		if (plus == 4)
		{
			cout << "Congratulations, you have found the number..\n";
			result = true;
			break;
		}
		if (count == 10)
		{
			cout << "Sorry, you could not find the number..\n";
			cout << s[0] - 48 << s[1] - 48 << s[2] - 48 << s[3] - 48 << "\n";
			result = false;
			break;
		}
	}
	return 0;
}
