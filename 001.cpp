/*
 * Project Euler problem #1
 *
 *  If we list all the natural numbers below 10 that are multiples of 3 or 5, we get 3, 5, 6 and 9. The sum of these multiples is 23.
 *
 *  Find the sum of all the multiples of 3 or 5 below 1000.
 *
 */

#include <iostream>

int getMultiplesSum(int base, int multiplier, int maxExclusive)
{
    if (multiplier == 0 || maxExclusive <= base)
    {
        return 0;
    }

    int n = (maxExclusive - 1) / multiplier;
    int baseRemainder = base % multiplier;
    if (baseRemainder)
    {
        base += multiplier - baseRemainder;
    }
    int result = n * (2 * base + multiplier * (n - 1)) / 2;

    return result;
}

int main(int, const char *[])
{
    const int upperBound = 1000;

    const int triples = getMultiplesSum(1, 3, upperBound);
    const int fifths = getMultiplesSum(1, 5, upperBound);
    const int fifteens = getMultiplesSum(1, 15, upperBound);

    const int result = triples + fifths - fifteens;
    std::cout << result << std::endl;

    return 0;
}
