#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
            i++;
            j--;
        }
    }

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int getFirstElement(std::vector<int> arr) {
    return arr[0];
}

int main() {
    std::vector<int> arr = {9, 7, 5, 11, 12, 2, 14, 3, 10, 6};
    quickSort(arr, 0, arr.size() - 1);
    int first = getFirstElement(arr);
    std::cout << "The first element in the sorted array is: " << first << std::endl;
    return 0;
}
