#include <stdio.h>
#include <stdlib.h>

int removeDuplicates(int* nums, int numsSize) {
    int i=0;
    for(int j = i + 1; j < numsSize;j++) {
        if(nums[j] != nums[i]) { 
            i++;
            nums[i]=nums[j];
        }

    }
    return i+1;
}

int main() {
    int nums[] = {0,0,1,1,1,2,2,3,3,4};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int k = removeDuplicates(nums, numsSize);

    printf("k = %d\n", k);
    printf("Unique elements: ");
    for (int i = 0; i < k; i++) {
        printf("%d ", nums[i]);
    }
    printf("\n");

    return 0;
}