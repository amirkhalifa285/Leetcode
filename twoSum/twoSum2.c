//This solution is in O(n)
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define HASH_SIZE 10000

typedef struct HashNode {
    int key;                // this is the number from the array
    int value;              // this is the index of the number
    struct HashNode* next;  // Pointer to handle collisions
} HashNode;

HashNode* hashTable[HASH_SIZE];

int hash(int key) {
    return abs(key) % HASH_SIZE;
}

void insert(int key, int value) {
    int idx=hash(key);
    HashNode* newNode=(HashNode*)malloc(sizeof(HashNode));
    newNode->key=key;
    newNode->value=value;
    newNode->next=hashTable[idx]; //insert at the beginning (chaining)
    hashTable[idx]= newNode;
}

int find(int key) {
    int idx=hash(key);
    HashNode* node=hashTable[idx];
    while (node != NULL) {
        if(node->key == key) {
            return node->value;
        }
        node=node->next;
    }
    return -1;
}

void freeHashTable() {
    for (int i = 0; i < HASH_SIZE; i++)
    {
        HashNode* node= hashTable[i];
        while (node != NULL)
        {
            HashNode* temp=node;
            node=node->next;
            free(temp);
        }
        hashTable[i]=NULL;
    }
}

int* twoSum(int* nums, int numSize, int target, int* returnSize) {
    memset(hashTable, 0,sizeof(hashTable));
    *returnSize=2;
    int* res = (int*)malloc(sizeof(int) * 2);

    for(int i=0;i<numSize;i++) {
        int complement=target - nums[i];
        int index=find(complement);
        if (index != -1) {
            res[0]=index;
            res[1]=i;
            freeHashTable();
            return res;
        }
        insert(nums[i],i);
    }

    *returnSize=0;
    free(res);
    freeHashTable();
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int returnSize;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL && returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);  
    } else {
        printf("No solution found.\n");
    }

    return 0;
}
