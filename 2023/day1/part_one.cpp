#include "day1.hpp"

int is_numeric(char c)
{
    if (c > 47 && c < 58)
        return 1;
    return 0;
}

int getnbr(string str)
{
    int nb = 0;
    int sign = 1;

    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '-')
            sign *= -1;
        if (is_numeric(str[i])) {
            nb = (nb * 10) + (str[i] - 48);
        }
    }
    return (nb * sign);
}

int get_first_digit(int number)
{
    while (number / 10) {
        number /= 10;
    }
    return number;
}

void part_one(void)
{
    string x;
    int number;
    int output = 0;

    freopen("input", "r", stdin);

    while (cin >> x) {
        number = get_first_digit(getnbr(x));
        number *= 10;
        number += getnbr(x) % 10;
        output += number;
    }
    cout << "The answer of part one is: " << output << endl;
}
