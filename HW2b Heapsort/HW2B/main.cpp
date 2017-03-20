#include <iostream>
using namespace std;

template<typename T>
void max_heapify(T arr[], int start, int end) {
    int dad = start;
    int son = dad * 2 + 1;
    while (son <= end) {
        if (son + 1 <= end && arr[son] < arr[son + 1])
            son++;
        if (arr[dad] > arr[son])
            return;
        else {
            swap(arr[dad], arr[son]);
            dad = son;
            son = dad * 2 + 1;
        }
    }
}

template<typename T>
void heap_sort(T arr[], int len) {
    for (int i = len / 2 - 1; i >= 0; i--)
        max_heapify(arr, i, len - 1);
    for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        max_heapify(arr, 0, i - 1);
    }
}

template<typename T>
void print_arr(T arr[], int len){
    for(T i = 0; i < len; i++)
        cout << arr[i] << " ";
    cout << endl;
    heap_sort(arr, len);
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
