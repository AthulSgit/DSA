#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define TABLE_SIZE 200003

typedef struct Node {
    int key;
    struct Node* next;
} Node;

Node* hashTable[TABLE_SIZE];

int hash(int key) {
    long long k = key;
    if (k < 0) k = -k;
    return k % TABLE_SIZE;
}

bool containsDuplicate(int* nums, int numsSize) {
    for (int i = 0; i < TABLE_SIZE; i++)
        hashTable[i] = NULL;

    for (int i = 0; i < numsSize; i++) {
        int index = hash(nums[i]);
        Node* curr = hashTable[index];

        while (curr != NULL) {
            if (curr->key == nums[i]) {
                return true;
            }
            curr = curr->next;
        }

        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->key = nums[i];
        newNode->next = hashTable[index];
        hashTable[index] = newNode;
    }

    return false;
}
