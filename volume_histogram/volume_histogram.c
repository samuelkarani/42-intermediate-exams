int min(int a, int b)
{
	return a < b ? a : b;
}

int max_index(int *histogram, int start, int end)
{
	int max = 0;
	int max_idx = start;
	while (start < end)
	{
		if (histogram[start] > max)
		{
			max = histogram[start];
			max_idx = start;
		}
		start++;
	}
	return max == 0 ? -1 : max_idx;
}

int calc(int *histogram, int a, int b)
{
	if (a < 0 || b < 0)
		return 0;
	int sum = (b - a - 1) * min(histogram[a], histogram[b]);
	a += 1;
	while (a < b)
		sum -= histogram[a++];
	return sum;
}

int calc_left(int *histogram, int max_idx, int sum)
{
	if (max_idx <= 0)
		return sum;
	int next_max = max_index(histogram, 0, max_idx);
	sum += calc(histogram, next_max, max_idx);
	return calc_left(histogram, next_max, sum);
}

int calc_right(int *histogram, int size, int max_idx, int sum)
{
	if (max_idx == -1 || max_idx == size - 1)
		return sum;
	int next_max = max_index(histogram, max_idx + 1, size);
	sum += calc(histogram, max_idx, next_max);
	return calc_right(histogram, size, next_max, sum);
}

int    volume_histogram(int *histogram, int size)
{
	int sum, max;
	sum = 0;
	max = max_index(histogram, 0, size);
	sum += calc_left(histogram, max, 0);
	sum += calc_right(histogram, size, max, 0);
	return sum;
}

int    volume_histogram2(int *histogram, int size)
{
	int i, j, imax, jmax, sum;
	i = sum = imax = jmax = 0;
	j = size - 1;
	while (i < j)
	{
		if (histogram[i] < histogram[j])
		{
			if (histogram[i] > imax)
				imax = histogram[i];
			else
				sum += imax - histogram[i];
			i++;
		}
		else
		{
			if (histogram[j] > jmax)
				jmax = histogram[j];
			else
				sum += jmax - histogram[j];
			j--;
		}
	}
	return sum;
}

#include <stdio.h>
int main()
{
	int    histogram1[] = {1, 0, 2, 0, 2};
	int    size = 5;
	printf("%d\n", volume_histogram2(histogram1, size));
	int    histogram2[] = {0, 0, 4, 0, 0, 6, 0, 0, 3, 0, 5, 0, 1, 0, 0, 0};
	size = 16;
	printf("%d\n", volume_histogram2(histogram2, size));
	return 0;
}
