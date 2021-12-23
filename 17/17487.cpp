#include <cstdio>
#include <cctype>

int main()
{
	const bool type[26] = {0, 0, 0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0};

	int left = 0;
	int right = 0;
	int other = 0;
	
	while (true)
	{
		char c;
		c = getchar();

		if (c == ' ')
			++other;
		else if (isupper(c))
		{
			++other;
			type[c - 'A']? ++right : ++left;
		}
		else if (islower(c))
			type[c - 'a']? ++right : ++left;
		else
			break;
	}

	if (left <= right)
	{
		left += other;
		if (left > right)
		{
			int diff = left - right;
			left -= diff / 2;
			right += diff / 2;
		}
	}
	else
	{
		right += other;
		if (left < right)
		{
			int diff = right - left;
			left += (diff + 1) / 2;
			right -= (diff + 1) / 2;
		}
	}

	printf("%d %d\n", left, right);
	return 0;
}