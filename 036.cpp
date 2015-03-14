/*
 * Project Euler problem #36
 *
 *
 * The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.
 *
 * Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.
 *
 * (Please note that the palindromic number, in either base, may not include leading zeros.)
 *
 */

#include <iostream>
#include <bitset>
#include <vector>

typedef std::vector<unsigned char> DigitVector;
static unsigned int buildPalindrome(const DigitVector &base, int halfWidth, int oddLength)
{
    int num = base[0];
    size_t middleDigit = halfWidth + oddLength - 1;
    for (int i = 1; i <= middleDigit; ++i)
    {
        num *= 10;
        num += base[i];
    }

    for (int i = 0; i < halfWidth; ++i)
    {
        num *= 10;
        num += base[middleDigit - i - oddLength];
    }

    return num;
}
static bool updatePalindromeBase(DigitVector &base)
{
    size_t index = base.size();
    for (DigitVector::reverse_iterator it = base.rbegin(); it != base.rend(); ++it)
    {
        --index;
        if (*it < 9)
        {
            *it += 1 + (index == 0); // skip even for maximum digit
            return true;
        }

        *it = 0;
    }
    return false;
}

int isBinaryPalindrome(unsigned int value)
{
    size_t bitLength = sizeof(value) * 8;
    for (; bitLength != 0 && !(value >> (bitLength - 1)); --bitLength);

    for (size_t i = 0; i < (bitLength / 2); ++i)
    {
        int h = value >> (bitLength - i - 1);
        int l = value >> i;
        bool equal = ((h ^ l) & 1) == 0;
        if (!equal)
        {
            return false;
        }
    }
    return true;
}

unsigned int getBiPalindromesSum(unsigned int length)
{
    int halfWidth = length / 2;
    int oddLength = (length & 1);

    DigitVector base;
    base.reserve(halfWidth + oddLength);
    base.push_back(1);
    base.resize(base.capacity(), 0);

    unsigned int sum = 0;
    bool hasNext = true;
    do
    {
        unsigned int num = buildPalindrome(base, halfWidth, oddLength);

        if (isBinaryPalindrome(num))
        {
            sum += num;
            std::cout << num << " b"
                      << std::bitset<sizeof(num) * 8>(num) << std::endl;
        }

        hasNext = updatePalindromeBase(base);
    }
    while (hasNext);

    return sum;
}

int main(int, const char *[])
{
    unsigned int result = 0;
    for (int palindromLength = 1;  palindromLength < 7; ++palindromLength)
    {
        std::cout << "Length: " << palindromLength << std::endl;
        result += getBiPalindromesSum(palindromLength);
    }
    std::cout << std::endl << "result: " << result << std::endl;
    return 0;
}

