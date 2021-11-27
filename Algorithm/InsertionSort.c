void InsertionSort(int a[], int len) {
  for (int i = 1; i < len; i++) {
    int j = i - 1;
    int key = a[i];
    while (j >= 0 && a[j] > key) {
        a[j+1] = a[j];
        j--;
    }
    a[j+1] = key;
  }
}