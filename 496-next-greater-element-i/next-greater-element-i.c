/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* nextGreaterElement(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize) {
    int* ans = malloc(nums1Size * sizeof(int));
    int* stack = malloc(nums2Size * sizeof(int));

    int top = -1;

    // nextGreater[value] = phần tử lớn hơn tiếp theo
    int nextGreater[10001];

    for (int i = 0; i < 10001; i++) {
        nextGreater[i] = -1;
    }

    // Duyệt nums2
    for (int i = 0; i < nums2Size; i++) {

        // nums2[i] lớn hơn các phần tử đang nằm trên stack
        while (top >= 0 && nums2[i] > stack[top]) {
            nextGreater[stack[top]] = nums2[i];
            top--;
        }

        stack[++top] = nums2[i];
    }

    // Tìm đáp án cho nums1
    for (int i = 0; i < nums1Size; i++) {
        ans[i] = nextGreater[nums1[i]];
    }

    free(stack);

    *returnSize = nums1Size;

    return ans;
}