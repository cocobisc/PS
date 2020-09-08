#include <bits/stdc++.h>
using namespace std;

int arr[10] = {5, 4, 3, 2, 1, 3, 1, 4, 1, 5};
int temp[10];

int merge(int l, int r) {
    int mid = l + r >> 1;
    int a = l;
    int b = mid + 1;
    int k = l;
    while (a <= mid && b <= r) {
        if (arr[a] < arr[b])
            temp[k++] = arr[a++];
        else
            temp[k++] = arr[b++];
    }
    while (a <= mid) temp[k++] = arr[a++];
    while (b <= r) temp[k++] = arr[b++];

    for (int i = l; i <= r; i++) arr[i] = temp[i];
}

void divide(int l, int r) {
    if (l < r) {
        int mid = l + r >> 1;
        divide(l, mid);
        divide(mid + 1, r);
        merge(l, r);
    }
}

int main() {
    divide(0, 9);
    for (int i = 0; i < 10; i++) cout << arr[i] << " ";
}