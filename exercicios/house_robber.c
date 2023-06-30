#include <stdlib.h>
#include <limits.h>

int OPT(int* nums, int* MEMO, int numsSize, int pos) {
    // base case
    if(pos < 0 || pos > numsSize) return 0;

    // already checked
    if(MEMO[pos] != INT_MIN) return MEMO[pos];

    int get = nums[pos] + OPT(nums, MEMO, numsSize, pos - 2);
    int not_get = OPT(nums, MEMO, numsSize, pos - 1);

    MEMO[pos] = get > not_get ? get : not_get;
    return MEMO[pos];
}

int rob(int* nums, int numsSize){
    int* MEMO = malloc(numsSize * sizeof(int));
    for(int i = 0; i < numsSize; i++)
        MEMO[i] = INT_MIN;

    OPT(nums, MEMO, numsSize, numsSize - 1);

    int biggest_amount = MEMO[numsSize - 1];
    free(MEMO);

    return biggest_amount;
}
