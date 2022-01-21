#include <stdio.h>
#include <stdlib.h>

int swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

void heapify(int array[], int n, int i) {
    int parentNode = i;
    int leftChildNode = i * 2 + 1;
    int rightChildNode = i * 2 + 2;
    if (leftChildNode < n && array[parentNode] < array[leftChildNode]) {
        parentNode = leftChildNode;
    }
    if (rightChildNode < n && array[parentNode] < array[rightChildNode]) {
        parentNode = rightChildNode;
    }
    if (i != parentNode) {
        swap(&array[parentNode], &array[i]);
        heapify(array, n, parentNode);
    }
}

void heapSort(int array[], int n) {
    for (int i = (n / 2) - 1; i >= 0; i--) {
        heapify(array, n, i);
    }
    for (int i = n - 1; i > 0; i--) {
        swap(&array[0], &array[i]);
        heapify(array, i, 0);
    }
}


int main() {
  int n;
  scanf("%d",&n);
  int arr[n];
  int sum = 0;
  for(int i=0; i<n; i++) {
    scanf("%d",&arr[i]);
    sum = sum + arr[i];
  }
  float average = sum / n;
  int averageForInt = 0;

  if(average - (int)average > 0.5) {
    averageForInt = (int)average + 1;
  } else {
    averageForInt = (int)average;
  }
  heapSort(arr,n);
  float littlediff;
  float bigdiff;
  
  littlediff = (average - (float)arr[0]) / (n / 2);
  bigdiff = ((float)arr[n-1] - average) / (n / 2);

  int bigdiffForInt = 0;
  int littlediffForInt = 0;

  if((littlediff - (int)littlediff) > 0.5) {
    littlediffForInt = (int)littlediff + 1;
  } else {
    littlediffForInt = (int)littlediff;
  } 
  
  if((bigdiff - (int)bigdiff) > 0.5) {
    bigdiffForInt = (int)bigdiff + 1;
  } else {
    bigdiffForInt = (int)bigdiff;
  } 
  int result = 0;
  if(n % 2 == 0) {
    for(int i = 0; i < (n / 2); i++) {
      int temp = 0;
      temp = abs(arr[i] - (littlediffForInt * ((n / 2) - i)));
      result = result + temp;
    }
    for(int j = (n / 2); j < n; j++) {
      int temp1 = 0;
      temp1 = abs(arr[j] - (bigdiffForInt * (j+1 - (n / 2))));
      result = result + temp1;
    }
  } // else {
    // return;
  // }
  printf("%d", result);
  
  
}