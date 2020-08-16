#include <iostream>
#include <cmath>

/*
	Project Euler Problem 04
	Largest palindrome product
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.
Find the largest palindrome made from the product of two 3-digit numbers.
*/

bool isPalindrome(int* array, int n)
{
	for (int i = 0; i < n; i++)
	{
		if (!(array[i] == array[n - 1 - i]))
		{
			return false;
		}
	}

	return true;
}

int find_digit(int value)
{
	int digit = 0;
	do {
		digit++;
		value /= 10;
	} while (value >= 1);

	return digit;
}

int number_at_i_digit(int number, int i)
{
	return int( std::fmod(number,std::pow(10, i))/ std::pow(10, i - 1));
}

int* number_to_array(int value)
{
	int n = find_digit(value);
	int* array = new int[n];
	for (int i = 0; i < n; i++)
	{
		array[i] = number_at_i_digit(value, i + 1);
	}

	return array;
}

int main()
{
	int max_palindrome = 0;
	for (int i = 100; i < 1000; i++)
	{
		for (int j = 100; j < 1000; j++)
		{
			int product = i * j;
			int n = find_digit(product);
			int* array_product = number_to_array(product);
			if (isPalindrome(array_product, n) && product > max_palindrome)
			{
				max_palindrome = product;
			}
		}
	}
	std::cout << max_palindrome;

	return 0;
}

/*
 ans = 906609
*/