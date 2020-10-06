#include <bits/stdc++.h>
using namespace std;

void sort(int *arr, int l, int r) {
    int pivot = l;
    int left = l + 1;
    int right = r;

    while (left <= right) {
        while (left <= r && arr[left] <= arr[pivot]) left++;
        while (right > l && arr[right] >= arr[pivot]) right--;

        if (left > right) {
            swap(arr[pivot], arr[right]);
            sort(arr, l, right - 1);
            sort(arr, right + 1, r);

        } else
            swap(arr[left++], arr[right--]);
    }
}

int main() {
    int arr[] = {5, 4, 3, 2, 1, 3, 2, 1, 5, 4};
    sort(arr, 0, 9);
    for (int i : arr) cout << i << " ";
}