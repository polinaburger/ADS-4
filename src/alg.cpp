// Copyright 2021 NNTU-CS
int countPairs1(int *arr, int len, int value) {
  int count = 0;
  for (int i = 0; i < len-1; i++) {
    for (int j = i + 1; j < len; j++) {
      if (arr[i] + arr[j] == value) {
        count++;
      }
    }
  }
  return count;
}
int countPairs2(int *arr, int len, int value) {
  int count = 0;
  int left = -1;
  int right = len-1;
  while (left < right-1) {
    int middle = (right + left)/2;
    if (arr[middle] <= value)
      left = middle;
    else
      right = middle;
  }
  len = right- 1;
  for (int i = len; i >= 0; i--) {
    for (j = 0; j < i; j++) {
      if (arr[j]+arr[i] == value)
        count++;
      if (arr[j] + arr[i] > value)
        break;
    }
  }
  return count;
}

int countPairs3(int *arr, int len, int value) {
  int count = 0;
  int left = 0;
  int right = len - 1;
  while (left < right - 1) {
    int middle = (right + left)/2;
    if (arr[middle] <= value)
      left = middle;
    else
      right = middle;
  }
  len = right - 1;
  for (int i = 0; i < len; i++) {
    right = len - 1;
    left = i + 1;
    int coount = 0;
    while (left < right) {
      int middle = (right + left)/2;
      if (arr[middle] < (value-arr[i]))
        left = middle + 1;
      else
        right = middle;
    }
    while (arr[left] == (value-arr[i])) {
        coount++;
        left++;
    }
    count = coount + count;
  }
  return count;
}
