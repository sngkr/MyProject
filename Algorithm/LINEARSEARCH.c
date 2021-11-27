#include <stdio.h>
int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
int main() {
  int low = 1, high = 8;
  int find = 2;
  int j = 0;
  while (low <= high && j == 0) {
    int mid = (low + high) / 2;
    if (find < a[mid]) {
      high = mid - 1;
    }else if(find > a[mid]){
        low = mid+1;
    }else{
        j = mid;
    }
  }
  printf("%d\n",a[j]);
}