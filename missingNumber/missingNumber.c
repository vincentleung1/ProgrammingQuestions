/**
* https://leetcode.com/problems/missing-number/#/description
*
* Runs in O(n) time and O(1) space
*/


int missingNumber(int* nums, int numsSize) {
    int i;
    for ( i = 0; i < numsSize; i++) {
        while (*nums >= 0 && *(nums+i) < numsSize && *(nums+i) != *(nums+*(nums+i))){
            int temp = *(nums+i);
            *(nums+i) = *(nums+temp);
            *(nums+temp) = temp;
        }
    }

    // Do a run through to check
    int current = 0;
    for ( i = 0; i < numsSize; i++) {
        if ( *nums != current) {
            return current;
        }
        current++;
        nums++;
    }
    return numsSize;
}
