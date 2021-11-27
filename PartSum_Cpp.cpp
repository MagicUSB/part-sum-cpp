#include <iostream>
#include <vector>
#include <cmath>

constexpr int CORE_NUMBER = 2;

using namespace std;

void init_array(vector<int> &arr) {
	for (size_t i = 0; i < arr.size(); i++)
	{
		arr[i] = i + 1;
	}
}

long long part_sum(vector<int>& arr, int start_index, int end_index) {
	long long result_sum = 0;
	for (int i = start_index; i <= end_index; i++)
	{
		result_sum += arr[i];
	}
	return result_sum;
}

int main()
{
	cout << "Enter the array size: ";
	int arr_size;
	cin >> arr_size;
	vector<int> arr(arr_size);
	init_array(arr);
	long long sum = 0;
	int step = arr_size > 1 ? arr_size / (log(arr_size) / log(CORE_NUMBER)) : 1;
	int i = 0;
	while (i < arr_size)
	{
		sum += part_sum(arr, i, min(i + step, arr_size - 1));
		i += step + 1;
	}
	cout << "Sum: " << sum << endl;
	return 0;
}

