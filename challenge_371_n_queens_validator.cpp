// 20190104
// r/dailyprogrammer Challenge #371 [Easy] N queens validator
// https://www.reddit.com/r/dailyprogrammer/comments/ab9mn7/20181231_challenge_371_easy_n_queens_validator/

#include <iostream>

// This algorithm will go through all the queens from left to right (left being
// the lowest index and right being the highest). It will check if the current
// queen is in the same row or diagonal as any of the queens to its left. If
// this is ever the case, the check fails and returns false. If all the queens
// pass the check, true is returned.
// Note: An empty board is considered a valid solution.
bool qCheck(const int * input, const int & size)
{
	for (int i = 0; i < size; i++)
	{
		const int & currentQueenRow = input[i];
		
		for (int j = 0; j < i; j++)
		{
			const int & oldQueenRow = input[j];
			
			// Same row check
			if (currentQueenRow == oldQueenRow) return false;
			
			// Diagonal check (slope should be 1 or -1)
			if (std::abs(currentQueenRow - oldQueenRow) == std::abs(i - j))
			{
				return false;
			}
		}
	}
	return true;
}

int main(int argc, char *argv[])
{
	// Test samples00 - 04 were provided by the reddit post
	// -------------------------------------------------------------------------
	const int sample00[] = {4, 2, 7, 3, 6, 8, 5, 1};
	const int size00 = 8;
	const bool result00 = qCheck(sample00, size00);
	std::cout << (result00 ? "true" : "false") << std::endl; // true
	
	const int sample01[] = {2, 5, 7, 4, 1, 8, 6, 3};
	const int size01 = 8;
	const bool result01 = qCheck(sample01, size01);
	std::cout << (result01 ? "true" : "false") << std::endl; // true
	
	const int sample02[] = {5, 3, 1, 4, 2, 8, 6, 3};
	const int size02 = 8;
	const bool result02 = qCheck(sample02, size02);
	std::cout << (result02 ? "true" : "false") << std::endl; // false
	
	const int sample03[] = {5, 8, 2, 4, 7, 1, 3, 6};
	const int size03 = 8;
	const bool result03 = qCheck(sample03, size03);
	std::cout << (result03 ? "true" : "false") << std::endl; // false
	
	const int sample04[] = {4, 3, 1, 8, 1, 3, 5, 2};
	const int size04 = 8;
	const bool result04 = qCheck(sample04, size04);
	std::cout << (result04 ? "true" : "false") << std::endl; // false
	
	// Test samples05 - 09 are testing different sizes
	// -------------------------------------------------------------------------
	const int sample05[] = {};
	const int size05 = 0;
	const bool result05 = qCheck(sample05, size05);
	std::cout << (result05 ? "true" : "false") << std::endl; // true
	
	const int sample06[] = {1};
	const int size06 = 1;
	const bool result06 = qCheck(sample06, size06);
	std::cout << (result06 ? "true" : "false") << std::endl; // true
	
	const int sample07[] = {1, 4, 2};
	const int size07 = 3;
	const bool result07 = qCheck(sample07, size07);
	std::cout << (result07 ? "true" : "false") << std::endl; // true
	
	const int sample08[] = {9, 2, 5, 7, 4, 1, 8, 6, 3, 10};
	const int size08 = 10;
	const bool result08 = qCheck(sample08, size08);
	std::cout << (result08 ? "true" : "false") << std::endl; // false
	
	return 0;
}

