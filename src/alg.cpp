// Copyright 2021 NNTU-CS
int countPairs1(int* arr, int size, int value) {
    int count = 0;
    for (int i = 0; i < size - 1; i++)
        for (int j = i + 1; j < size; j++)
            if ((arr[i] + arr[j]) == value)
                count += 1;
    return count;
}
int countPairs2(int* arr, int len, int value) {
    int left = 0;
    int right = len - 1;
    int count = 0;
    while (arr[right] > value) {
        right = right - 1;
    }
    for (int i = 0; i < right; i++) {
        for (int j = right; j > i; j--) {
            int sum = arr[i] + arr[j];
            if (sum == value) {
                count++;
            }
        }
    }
    return count;
}
int cbinsearch(int* arr, int size, int value) {
    int left = 0;
    int right = size - 1;
    int count = 0;
    while (left <= right) {
        int middle = left + (right - left) / 2;
        if (arr[middle] == value) {
            int left = middle - 1;
            int right = middle + 1;
            count++;
            while (left >= 0 && arr[left] == value) {
                left--;
                count++;
            }
            while (right < size && arr[right] == value) {
                right++;
                count++;
            }
            return count;
        }
        if (arr[middle] < value) {
            left = middle + 1;
        }
        else {
            right = middle - 1;
        }
    }
    return count;
}
int countPairs3(int* arr, int len, int value) {
    int count = 0;
    for (int i = 0; i < len; i++) {
        int secondArr = value - arr[i];
        count = count + cbinsearch(&arr[i + 1], len - i - 1, secondArr);
    }
    return count;
}
