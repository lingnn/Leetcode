int cmp(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}
bool checkIfExist(int* arr, int arrSize) {
    qsort(arr, arrSize, sizeof(int), cmp);
    for (int i = 0; i < arrSize; i++) {
        int target = arr[i] * 2;
        int left = 0;
        int right = arrSize - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (arr[mid] == target) {
                if (mid != i)
                    return true;
                break;
            }
            if (arr[mid] < target)
                left = mid + 1;
            else
                right = mid - 1;
        }
    }
    return false;
}