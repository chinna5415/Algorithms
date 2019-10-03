//merge sort

using namespace std;
#include <iostream>

mergesort(int , int , int arr[]);
sort(int , int , int , int arr[]);

int main() {
    int n , arr[20];
    cout << "enter the range : ";
    cin >> n;

    for (int i = 0 ; i < n ; i++) {
        cout << "enter the new element : ";
        cin >> arr[i];
    }

    mergesort(0,n,arr);
    for (int i = 0 ; i < n ; i++) 
        cout << " " << arr[i];
    return 0;
}

void mergesort(int low , int high , int arr[]) {
     int mid ;
     if (low < high) {
        mid = (low+high)/2;
        mergesort(low,mid,arr);
        mergesort(mid+1 , high , arr);
        sort(low,mid,high,arr);
     }
}

void sort(int beg , int mid , int end , int arr[]) {
     int i = beg , j = mid+1 , k = beg , temp[100];
     while (i <= mid && j <= end) {
           if (arr[i] < arr[j]) {
              temp[k] = arr[i];
              i++;
           } else {
                    temp[k] = arr[j];
                    j++;
           }
             k++;
     }

     while (i <= mid) {
           temp[k] = arr[i];
           i++;
           k++;
     }

     while (j <= end) {
           temp[k] = arr[i];
           j++;
           k++;
     }

     for (int l = 0 ; l < end ; l++)
         arr[l] = temp[l];
}