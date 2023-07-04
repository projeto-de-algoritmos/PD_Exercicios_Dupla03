#include <stdlib.h>

int lengthOfLIS(int* nums, int numsSize){
    int* L = malloc(numsSize * sizeof(int));
    int max = 0;
    for(int j = 0; j < numsSize; j++) {
        L[j] = 1;
        for(int i = 0; i < j; i++) {
            if(nums[i] < nums[j] && 1 + L[i] > L[j]){
                L[j] = 1 + L[i];
            }
        }
        if(max < L[j]) max = L[j];
    }
    
    free(L);
    return max;
}

