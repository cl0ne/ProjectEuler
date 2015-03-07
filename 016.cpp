/*
 * Project Euler problem #16
 *
 *
 *  2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.
 *
 *  What is the sum of the digits of the number 2^1000?
 *
 */

#include <iostream>

unsigned long getDigitSum_PowersOfTwo(unsigned short power)
{
    const size_t reserve = 1 + power * 30103 / 100000; // 30103/100000 is approximately log10(2)
    char digits[reserve] = { 1 };

    for (size_t i = 0; i < power; ++i)
    {
        char carry = 0;
        for (size_t c = 0; c < reserve; ++c)
        {
            digits[c] += digits[c] + carry;
            carry = 0;

            if (digits[c] > 9)
            {
                carry = 1;
                digits[c] -= 10;
            }
        }
    }

    unsigned long sum = 0;
    for (size_t i = 0; i < reserve; ++i)
    {
        sum += digits[i];
    }

    return sum;
}

int main(int, const char *[])
{
    std::cout << "2^15: " << getDigitSum_PowersOfTwo(15) << std::endl;
    std::cout << "2^1000: " << getDigitSum_PowersOfTwo(1000) << std::endl;
    return 0;
}

