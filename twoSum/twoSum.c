#include <stdio.h>
#include <stdlib.h>

typedef struct Answer {
    int index1;
    int index2;
}Answer;

Answer* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    Answer* answer = (Answer*)malloc(sizeof(Answer));
    if (answer==NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    *returnSize=0;
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                answer->index1 = i;
                answer->index2 = j;
                *returnSize = 2;
                return answer;
            }
        }
    }
    free(answer);
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;
    Answer *answer=twoSum(nums,numsSize,13, &returnSize); 
    if (answer != NULL && returnSize == 2) {
        printf("[%d, %d]\n", answer->index1, answer->index2);
        free(answer);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}