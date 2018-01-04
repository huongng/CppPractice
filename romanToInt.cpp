#include <iostream>
#include <string>

using namespace std;

int getNum(char c)
{
    if (c == 'I') return 1;
    if (c == 'V') return 5;
    if (c == 'X') return 10;
    if (c == 'L') return 50;
    if (c == 'C') return 100;
    if (c == 'D') return 500;
    if (c == 'M') return 1000;
    return 0;
}

int romanToInt(string input)
{
    int res = 0;
    int i = 0;
    while (i < input.length() - 1) {
	switch(input.at(i)) {
	case 'I':
	    if (input.at(i+1) == 'V' || input.at(i+1) == 'X') {
		res += getNum(input.at(i+1)) - 1;
		i++;
	    }
	    else {
		res += 1;
	    }
	    break;
	case 'X':
	    if (input.at(i+1) == 'L' || input.at(i+1) == 'C') {
		res += getNum(input.at(i+1)) - 10;
		i++;
	    }
	    else {
		res += 10;
	    }
	    break;
	case 'C':
	    if (input.at(i+1) == 'D' || input.at(i+1) == 'M') {
		res += getNum(input.at(i+1)) - 100;
		i++;
	    }
	    else {
		res += 100;
	    }
	    break;
	default:
	    res += getNum(input.at(i));
	    break;
	}
	i++;
    }
    if (i < input.length())
	res += getNum(input.at(i));
    return res;

}
int main()
{
    string input;
    int res;
    cin >> input;
    res = romanToInt(input);
    cout << res << endl;
    return 0;
}
