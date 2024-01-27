#include <stdio.h>

int minjumps_f(int *arr, int start, int end) {
    // If start is already at or beyond end, no jump needed
    if (start >= end)
        return 0;

    // If start element is 0, can't make progress
    if (arr[start] == 0)
        return -1; // Indicate impossibility

    int minJumps = -1; // Initialize to indicate impossibility

    // Try all possible jumps from current position
    for (int i = 1; i <= arr[start]; i++) {
        int jumps = minjumps_f(arr, start + i, end); // Find jumps from new position
        if (jumps != -1) { // If reachable
            jumps++; // Increment jumps as we're taking a step now
            if (minJumps == -1 || jumps < minJumps)
                minJumps = jumps; // Update minJumps if new min found
        }
    }

    return minJumps; // Return the minimum jumps required
}

int main() {
    int n;
    scanf("%d", &n);
    if (n <= 0)
        return 0;
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    int start = 0, end = n - 1;
    int value = minjumps_f(arr, start, end);

    if (value == -1)
        printf("Not Possible");
    else
        printf("%d", value);
    
    return 0;
}
