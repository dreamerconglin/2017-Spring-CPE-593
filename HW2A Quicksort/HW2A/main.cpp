#include <iostream>
using namespace std;

template<typename T>
void quick_sort_recursive(T arr[], int start, int end){
    if (start >= end) return;
    T mid = arr[end];
    int left = start, right = end - 1;
    while (left < right) {
        while (arr[left] < mid && left < right) left++;
        while (arr[right] >= mid && left < right) right--;
        std::swap(arr[left], arr[right]);
    }
    if (arr[left] >= arr[end])
        std::swap(arr[left], arr[end]);
    else
        left++;
    quick_sort_recursive(arr, start, left - 1);
    quick_sort_recursive(arr, left + 1, end);
}

template<typename T>
void quick_sort(T arr[], int len){
    quick_sort_recursive(arr, 0, len - 1);
}

template<typename T>
void print_arr(T arr[], int len){
    for(T i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    quick_sort(arr, len);
    for(T j = 0; j < len; j++)
        cout << arr[j] << " ";
    cout << endl;
}

int main(){
    int arr1[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int arr2[10] = {10, 9, 8, 7, 6, 5, 4, 3, 2, 1};
    int arr3[5] = {62, 50, 50, 50, 62};
    print_arr(arr1,10);
    print_arr(arr2,10);
    print_arr(arr3,5);
    return 0;
}
