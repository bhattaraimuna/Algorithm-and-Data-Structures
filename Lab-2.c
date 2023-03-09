//Muna Bhattarai
//CSE-3318-Lab-2
//UTA-Spring-2023
//Proffessor-Bob Weems

#include <stdio.h>
#include <stdlib.h>

#define MAXN 1000000

int seq[MAXN];
int link[MAXN];

int mergeSort(int start, int count);

int main() {
    int n, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    int start = mergeSort(0, n);

printf("First element is at subscript %d\n", start);
int j;
for(j = 0; j < n; j++){
printf("%d %d %d\n", j, seq[j], link[j]);
}

    return 0;
}

int mergeSort(int start, int count) {
    if (count == 1) {
        link[start] = -1;
        return start;
    }

    int mid = start + (count / 2);
    int leftStart = mergeSort(start, mid - start);
    int rightStart = mergeSort(mid, count - (mid - start));

    int i, j, k;
    int* merged = (int*) malloc(count * sizeof(int));
    i = leftStart;
    j = rightStart;
    k = 0;
    while (i != -1 && j != -1) {
        if (seq[i] <= seq[j]) {
            merged[k++] = i;
            i = link[i];
        } else {
            merged[k++] = j;
            j = link[j];
        }
    }
    while (i != -1) {
        merged[k++] = i;
        i = link[i];
    }
    while (j != -1) {
        merged[k++] = j;
        j = link[j];
    }

    int startIdx = merged[0];
    for (k = 0; k < count-1; k++) {
        link[merged[k]] = merged[k+1];
    }
    link[merged[count-1]] = -1;

    free(merged);

    return startIdx;
}
//compiled with Omega

