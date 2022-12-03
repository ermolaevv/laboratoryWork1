#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <malloc.h>

// Global Variable
int n, output_flag;

// Reference Array
int *arr;

// Work Array
int *arr1;

void swap(int* a, int* b);
void update_seed_rand();
void copy_array_values(int arr[], int arr1[]);
void update_values(int arr[]);
void update_size(int** arr, int** arr1);
void print_array(int arr[], int output_flag);
void print_search(int index, unsigned long long c_i, double timer);
int line_search(int arr[], int n, int key, unsigned long long* counter_iterations, int* opt = NULL);
int binary_search(int arr[], int n, int key, unsigned long long* counter_iterations, int* opt = NULL);
void stupid_bubble_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void bubble_sort_with_break(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void shake_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void insert_sort_with_line_search(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void insert_sort_with_binary_search(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void selection_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void calculation_sort(int arr[], unsigned long long* counter_iterantions);
void quick_sort(int arr[], int first, int last, unsigned long long* counter_comparisons, unsigned long long* counter_swaps,
	unsigned long long* deep_recursion, int deep = 0);
void q_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps,
	unsigned long long* deep_recursion);
void call_sort(void (*funcion_pointer) (int arr1[], unsigned long long* c_c, unsigned long long* c_s));
void call_sort(void (*funcion_pointer) (int arr1[], unsigned long long* c_c, unsigned long long* c_s, unsigned long long* deep));
void call_sort(void (*funcion_pointer) (int arr1[], unsigned long long* c_i));
void merge_arrays(int arr[], int left, int mid, int right, unsigned long long* counter_comparisons, unsigned long long* counter_swaps);
void merge_sort(int arr[], int left, int right, unsigned long long* counter_comparisons, unsigned long long* counter_swaps,
		unsigned long long* deep_recursion, unsigned long long deep = 0);
void m_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps,
	unsigned long long* deep_recursion);

int main() {
	int op, op1, loop_flag, key, response;
	unsigned long long c_c = 0, c_s = 0, c_i = 0, deep = 0;
	clock_t start;

	do {
		printf("Enter lenght array: ");
		scanf_s("%d", &n);
	} while (n <= 0);

	arr = (int*)malloc(sizeof(int) * n);
	arr1 = (int*)malloc(sizeof(int) * n);
	update_seed_rand();
	update_values(arr);
	copy_array_values(arr, arr1);

	printf("Print arrays? (1/0): ");
	scanf_s("%d", &output_flag);
	printf("Config is complite.\n\n");

	while (1) {
		printf("Menu: \n"
			"1. Config\n"
			"2. Sorts\n"
			"3. Searches\n"
			"0. Exit\n"
			"Enter operation: ");

		scanf_s("%d", &op);
		printf("\n");

		switch (op)
		{
		case 0:
			system("cls");
			printf("See you next time.\n"
				"@ Yermolaev Vladislav\n");

			return 0;
			break;
		case 1:
			system("cls");
			loop_flag = 1;

			while (loop_flag) {
				printf("Config: \n"
					"1. Update seed rand\n"
					"2. Update values in array\n"
					"3. Toggle print arrays\n"
					"4. Resize arrays\n"
					"5. Print current array\n"
					"0. To main menu\n"
					"Enter operation: ");

				scanf_s("%d", &op1);
				printf("\n");

				switch (op1)
				{
				case 1:
					system("cls");
					update_seed_rand();
					printf("Successfully updated.\n\n");
					break;
				case 2:
					system("cls");
					update_values(arr);
					printf("Successfully updated.\n\n");
					break;
				case 3:
					system("cls");
					printf("Enter (1/0): ");
					scanf_s("%d", &output_flag);
					printf("Successfully updated.\n\n");
					break;
				case 4:
					system("cls");
					update_size(&arr, &arr1);
					printf("Successfully updated.\n\n");
					break;
				case 5:
					system("cls");
					print_array(arr, 1);
					printf("\n");
					break;
				case 0:
					loop_flag = 0;
					system("cls");
					break;

				default:
					system("cls");
					printf("Operation not found.\n\n");
				}
			}
			break;
		case 2:
			system("cls");
			loop_flag = 1;

			while (loop_flag) {
				printf("Sorts: \n"
					"1. All sorts\n"
					"2. Stupid bubble sort\n"
					"3. Bubble sort with break\n"
					"4. Shake sort\n"
					"5. Select sort\n"
					"6. Insert sort with line search\n"
					"7. Insert sort with binary search\n"
					"8. Calculation sort\n"
					"9. Quick sort\n"
					"10. Merge sort\n"
					"0. To main menu\n"
					"Enter operation: ");

				scanf_s("%d", &op1);
				printf("\n");

				switch (op1)
				{
				case 1:
					system("cls");
				case 2:
					if (op1 != 1) system("cls");
					printf("Stupid bubble sort:\n");
					call_sort(stupid_bubble_sort);
					if (op1 != 1) break;
				case 3:
					if (op1 != 1) system("cls");
					printf("Bubble sort with break:\n");
					call_sort(bubble_sort_with_break);
					if (op1 != 1) break;
				case 4:
					if (op1 != 1) system("cls");
					printf("Shake sort:\n");
					call_sort(shake_sort);
					if (op1 != 1) break;
				case 5:
					if (op1 != 1) system("cls");
					printf("Select sort:\n");
					call_sort(selection_sort);
					if (op1 != 1) break;
				case 6:
					if (op1 != 1) system("cls");
					printf("Insert sort with line search:\n");
					call_sort(insert_sort_with_line_search);
					if (op1 != 1) break;
				case 7:
					if (op1 != 1) system("cls");
					printf("Insert sort with binary search:\n");
					call_sort(insert_sort_with_binary_search);
					if (op1 != 1) break;
				case 8:
					if (op1 != 1) system("cls");
					printf("Calculation sort:\n");
					call_sort(calculation_sort);
					if (op1 != 1) break;
				case 9:
					if (op1 != 1) system("cls");
					printf("Quick sort:\n");
					call_sort(q_sort);
					if (op1 != 1) break;
				case 10:
					if (op1 != 1) system("cls");
					printf("Merge sort:\n");
					call_sort(m_sort);
					break;
				case 0:
					loop_flag = 0;
					system("cls");
					break;
				default:
					system("cls");
					printf("Operation not found\n\n");
				}
			}
			break;
		case 3:
			system("cls");
			loop_flag = 1;

			while (loop_flag) {
				printf("Searches:\n"
					"1. All searches\n"
					"2. Line search\n"
					"3. Binary search\n"
					"0. To main menu\n"
					"Enter operation: ");

				scanf_s("%d", &op1);
				printf("\n");

				switch (op1)
				{
				case 0:
					loop_flag = 0;
					system("cls");
					break;
				case 1:
					system("cls");
					q_sort(arr1, &c_c, &c_s, &deep);
					print_array(arr1, output_flag);
					printf("Enter digit: ");
					scanf_s("%d", &key);
					printf("\n");
				case 2:
					if (op1 != 1) {
						system("cls");
						q_sort(arr1, &c_c, &c_s, &deep);
						print_array(arr1, output_flag);
						printf("Enter digit: ");
						scanf_s("%d", &key);
						printf("\n");
					}

					printf("Line search:\n");
					start = clock();
					response = line_search(arr1, n, key, &c_i);
					print_search(response, c_i, (clock() - start) / (float)CLOCKS_PER_SEC);

					if (op1 != 1) {
						copy_array_values(arr, arr1);
						break;
					}
				case 3:
					if (op1 != 1) {
						system("cls");
						q_sort(arr1, &c_c, &c_s, &deep);
						print_array(arr1, output_flag);
						printf("Enter digit: ");
						scanf_s("%d", &key);
						printf("\n");
					}
				
					printf("Binary search:\n");
					start = clock();
					response = binary_search(arr1, n, key, &c_i);
					print_search(response, c_i, (clock() - start) / (float)CLOCKS_PER_SEC);

					copy_array_values(arr, arr1);
					break;
				default:
					system("cls");
					printf("Operation not found\n\n");
				}
			}
			break;
		default:
			system("cls");
			printf("Operation not found\n\n");
		}
	}

	free(arr);
	free(arr1);
}

int line_search(int arr[], int n, int key, unsigned long long* counter_iterations, int* opt) {
	int i, c_i = 0, ind = -1;

	for (i = 0; i < n; i++) {
		if (arr[i] == key) {
			ind = i;
			break;
		}
		c_i++;
	}

	*counter_iterations = c_i;
	return ind;
}

int binary_search(int arr[], int n, int key, unsigned long long* counter_iterations, int* opt) {
	int l = 0, r = n - 1, mid;
	unsigned long long c_i = 0;

	while (r >= l) {
		mid = (l + r) / 2;

		if (arr[mid] == key) {
			*counter_iterations = c_i;
			if (opt != NULL)
				*opt = mid;
			return mid;
		}
		else if (arr[mid] > key)
			r = mid - 1;
		else
			l = mid + 1;

		c_i++;
	}

	if (l > r && opt != NULL) {
		*opt = l;
	}

	*counter_iterations = c_i;
	return -1;
}

void swap(int* a, int* b) { 
	int c = *a;
	*a = *b;
	*b = c;
}

void update_seed_rand() {
	srand((unsigned int)time(NULL));
}

void copy_array_values(int arr[], int arr1[]) {
	int i;

	for (i = 0; i < n; i++) {
		arr1[i] = arr[i];
	}
}

void update_values(int arr[]) {
	int i;

	if (n > 10) 
		for (i = 0; i < n; i++) 
			arr[i] = rand();

	else 
		for (i = 0; i < n; i++) {
			printf("Enter digit (index %d): ", i);
			scanf_s("%d", &arr[i]);
		}
}

void update_size(int** arr, int** arr1) {
	free(*arr);
	free(*arr1);

	do {
		printf("Enter new size: ");
		scanf_s("%d", &n);
	} while (n <= 0);

	*arr = (int*)malloc(sizeof(int) * n);
	*arr1 = (int*)malloc(sizeof(int) * n);

	update_values(*arr);
	copy_array_values(*arr, *arr1);
}

void print_array(int arr[], int output_flag) {
	int i;
	
	if (output_flag) {
		printf("Current array: ");
		for (i = 0; i < n; i++)
			printf("%d ", arr[i]);
		printf("\n");
	}
}

void print_search(int index, unsigned long long c_i, double timer) {
	if (index == -1)
		printf("Not found!\n");
	else	
		printf("Element found on index %d\n", index);
	printf("Iterations: %lli\n", c_i);
	printf("Time: %lf seconds\n\n", timer);
}

void stupid_bubble_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i, j;
	unsigned long long c_s = 0, c_c = 0;
	
	for (j = 0; j < n; j++) {
		for (i = 0; i < n - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				c_s++;
			}
			c_c++;
		}
	}

	*counter_comparisons = c_c;
	*counter_swaps = c_s;
}

void bubble_sort_with_break(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i, j, flag;
	unsigned long long c_s = 0, c_c = 0;

	for (j = 0; j < n; j++) {
		flag = 1;

		for (i = 0; i < n - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				flag = 0;
				c_s++;
			}
			c_c++;
		}

		if (flag)
			break;
	}

	*counter_comparisons = c_c;
	*counter_swaps = c_s;
}

void shake_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i, j, flag;
	unsigned long long c_s = 0, c_c = 0;

	for (j = 0; j < n; j++) {
		flag = 1;

		for (i = j; i < n - j - 1; i++) {
			if (arr[i] > arr[i + 1]) {
				swap(&arr[i], &arr[i + 1]);
				c_s++;
				flag = 0;
			}
			c_c++;
		}
		if (flag)
			break;

		for (i = n - j - 1; i > j; i--) {
			if (arr[i] < arr[i - 1]) {
				swap(&arr[i], &arr[i - 1]);
				c_s++;
				flag = 0;
			}
			c_c++;
		}
		if (flag)
			break;

	}

	*counter_swaps = c_s;
	*counter_comparisons = c_c;
}

void insert_sort_with_line_search(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i, j, ind;
	unsigned long long c_c = 0, c_s = 0;

	for (i = 1; i < n; i++) {
		ind = i;

		for (j = 0; j < i; j++) {
			c_c++;
			if (arr[i] < arr[j]) {
				ind = j;
				break;
			}
		}
		
		for (j = i; j > ind; j--) {
			swap(&arr[j], &arr[j - 1]);
			c_s++;
		}

	}

	*counter_comparisons = c_c;
	*counter_swaps = c_s;
}

void insert_sort_with_binary_search(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i, j, ind;
	unsigned long long c_c = 0, c_s = 0, c_i;

	for (i = 1; i < n; i++) {
		binary_search(arr, i, arr[i], &c_i, &ind);

		for (j = i; j > ind; j--) {
			swap(&arr[j], &arr[j - 1]);
			c_s++;
		}

		c_c += c_i;
	}

	*counter_comparisons = c_c;
	*counter_swaps = c_s;
}

void selection_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i, j, mn_ind;
	unsigned long long c_c = 0, c_s = 0;

	for (i = 0; i < n; i++) {
		mn_ind = i;

		for (j = i; j < n; j++) {
			if (arr[j] < arr[mn_ind]) {
				mn_ind = j;
			}
			c_c++;
		}

		if (mn_ind != i) {
			swap(&arr[mn_ind], &arr[i]);
			c_s++;
		}
	}

	*counter_comparisons = c_c;
	*counter_swaps = c_s;
}

void calculation_sort(int arr[], unsigned long long* counter_iterantions) {
	int i, j, k = 0, mn = arr[0], mx = arr[0];
	unsigned long long c_i = 0;

	for (i = 0; i < n; i++) {
		if (arr[i] < mn) mn = arr[i];
		if (arr[i] > mx) mx = arr[i];
		c_i++;
	}

	int step = mx - mn + 1;
	if (step == 0) step = 1;
	int* counter = (int*)malloc(sizeof(int) * step);

	if (counter != NULL) {
		for (i = 0; i < step; i++) {
			counter[i] = 0;
			c_i++;
		}

		for (i = 0; i < n; i++) {
			counter[arr[i] - mn]++;
			c_i++;
		}
		
		for (i = 0; i < step; i++) {
			for (j = 0; j < counter[i]; j++) {
				arr[k++] = i + mn;
				c_i++;
			}
		}
	}

	free(counter);
	*counter_iterantions = c_i;
}

void quick_sort(int arr[], int first, int last, unsigned long long* counter_comparisons, unsigned long long* counter_swaps,
	unsigned long long* deep_recursion, int deep) {
	unsigned long long c_s = 0, c_c = 0;
	int mid = arr[(first + last) / 2];
	int left = first, right = last;

	while (left < right) {
		while (arr[left] < mid) {
			left++;
			c_c++;
		}

		while (arr[right] > mid) {
			right--;
			c_c++;
		}
		
		if (left <= right) {
			swap(&arr[left], &arr[right]);
			c_c++;
			c_s++;
			left++;
			right--;
		}
	}

	*counter_comparisons += c_c;
	*counter_swaps += c_s;
	if (*deep_recursion < deep)
		*deep_recursion = deep;
	
	if (first < right) 
		quick_sort(arr, first, right, counter_comparisons, counter_swaps, deep_recursion, deep + 1);
	if (left < last) 
		quick_sort(arr, left, last, counter_comparisons, counter_swaps, deep_recursion, deep + 1);
}

void q_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps, 
	unsigned long long* deep_recursion) {
	quick_sort(arr, 0, n-1, counter_comparisons, counter_swaps, deep_recursion);
}

void call_sort(void (*funcion_pointer) (int arr1[], unsigned long long* c_c, unsigned long long* c_s))
{
	unsigned long long c_c = 0, c_s = 0;
	clock_t start = clock();
	int i;

	funcion_pointer(arr1, &c_c, &c_s);

	if (output_flag) {
		printf("Old array: ");
		for (i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		printf("Sorted array: ");
		for (i = 0; i < n; i++) {
			printf("%d ", arr1[i]);
		}
		printf("\n");
	}
	printf("Comparisons: %lli\nSwaps: %lli\n", c_c, c_s);
	printf("Time: %lf seconds\n", (clock() - start) / (float)CLOCKS_PER_SEC);
	printf("\n");

	copy_array_values(arr, arr1);
}

void call_sort(void (*funcion_pointer) (int arr1[], unsigned long long* c_c, unsigned long long* c_s, unsigned long long* deep))
{
	unsigned long long c_c = 0, c_s = 0, deep = 0;
	clock_t start = clock();
	int i;

	funcion_pointer(arr1, &c_c, &c_s, &deep);

	if (output_flag) {
		printf("Old array: ");
		for (i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		printf("Sorted array: ");
		for (i = 0; i < n; i++) {
			printf("%d ", arr1[i]);
		}
		printf("\n");
	}
	printf("Comparisons: %lli\nSwaps: %lli\n", c_c, c_s);
	printf("Deep recursion: %lli\n", deep);
	printf("Time: %lf seconds\n", (clock() - start) / (float)CLOCKS_PER_SEC);
	printf("\n");

	copy_array_values(arr, arr1);
}

void call_sort(void (*funcion_pointer) (int arr1[], unsigned long long* c_i))
{
	unsigned long long c_i = 0;
	clock_t start = clock();
	int i;

	funcion_pointer(arr1, &c_i);

	if (output_flag) {
		printf("Old array: ");
		for (i = 0; i < n; i++) {
			printf("%d ", arr[i]);
		}
		printf("\n");

		printf("Sorted array: ");
		for (i = 0; i < n; i++) {
			printf("%d ", arr1[i]);
		}
		printf("\n");
	}
	printf("Iterations: %lli\n", c_i);
	printf("Time: %lf seconds\n", (clock() - start) / (float)CLOCKS_PER_SEC);
	printf("\n");

	copy_array_values(arr, arr1);
}

void merge_arrays(int arr[], int left, int mid, int right, unsigned long long* counter_comparisons, unsigned long long* counter_swaps) {
	int i = left, j = mid + 1, k = 0;
	unsigned long long c_c = 0, c_s = 0;
	int* tmp = (int*)malloc(sizeof(int) * (unsigned long long)(right - left + 1));
	if (tmp != NULL) {
		while ((i <= mid) && (j <= right)) {
			if (arr[i] < arr[j])
				tmp[k] = arr[i++];
			else
				tmp[k] = arr[j++];
			k++;
			c_c++;
			c_s++;
		}

		while (j <= right) {
			tmp[k] = arr[j++];
			k++;
			c_s++;
		}

		while (i <= mid) {
			tmp[k] = arr[i++];
			k++;
			c_s++;
		}

		for (i = left; i <= right; i++) {
			arr[i] = tmp[i - left];
			c_s++;
		}
	}
	*counter_comparisons += c_c;
	*counter_swaps += c_s;
	free(tmp);
}

void merge_sort(int arr[], int left, int right, unsigned long long* counter_comparisons, unsigned long long* counter_swaps,
	unsigned long long* deep_recursion, unsigned long long deep) {
	if (deep > *deep_recursion)
		*deep_recursion = deep;
	if (left == right)
		return;

	int mid = (left + right) / 2;
	merge_sort(arr, left, mid, counter_comparisons, counter_swaps, deep_recursion, deep + 1);
	merge_sort(arr, mid + 1, right, counter_comparisons, counter_swaps, deep_recursion, deep + 1);
	merge_arrays(arr, left, mid, right, counter_comparisons, counter_swaps);

}

void m_sort(int arr[], unsigned long long* counter_comparisons, unsigned long long* counter_swaps, unsigned long long* deep_recursion)
{
	merge_sort(arr, 0, n-1, counter_comparisons, counter_swaps, deep_recursion);
}
