using namespace std;
#include <iostream>

void sort(int arr[] , int , int);
int pratition(int arr[] , int , int);

int main()
{
  int n , arr[n];
  cout << "enter the range : ";
  cin >> n;
  for (int i = 0 ; i < n ; i++) {
      cout << "enter the element : ";
      cin >> arr[i];
  }

  sort(arr,0,n);

  for (int i = 0 ; i < n ; i++)
      cout << " " << arr[i];
  return 0;
}

void sort(int arr[] , int beg , int end) {
     int sp;
     if (beg < end) {
         sp = pratition(arr,beg,end);

         sort(arr,beg,sp-1);
         sort(arr,sp+1,end);
     }
}

int pratition(int arr[] , int beg , int end) {
    int pivot , left , right , temp , flag=0;
    pivot = left = beg;
    right = end;

    while (flag != 1) {
          while (arr[pivot] <= arr[right] && pivot != right)
                right--;
          if (pivot == right)
              flag = 1;
           else if (arr[pivot] > arr[right]) {
                   temp = arr[pivot];
                   arr[pivot] = arr[right];
                   arr[right] = temp;
                   pivot = right;
           }

          if (flag != 1) {
              while (arr[pivot] >= arr[left] && pivot != left)
                     left++;
              if (pivot == left)
                 flag = 1;
              else if (arr[left] > arr[pivot]) {
                      temp = arr[pivot];
                      arr[pivot] = arr[left];
                      arr[left] = temp;
                      pivot = left;
              }  
          }
    }  

    return pivot;
}
