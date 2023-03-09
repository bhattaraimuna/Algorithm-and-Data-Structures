//Muna Bhattarai
//CSE-3318-Lab-1
//UTA-Spring-2023
//Proffessor-Bob Weems

#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct arraypair {
    int value;
    int position;
};
 
// Function to compare two pairs
int compare(const void *a, const void *b)
{
    struct arraypair *p1 = (struct arraypair *)a;
    struct arraypair *p2 = (struct arraypair *)b;
    return (p1->value - p2->value);
}

int compare1(const void *c, const void *d)
{
    struct arraypair *p3 = (struct arraypair *)c;
    struct arraypair *p4 = (struct arraypair *)d;
    return (p3->position - p4->position);
}
 

void sortData(struct arraypair arr[], int n)
{
    qsort(arr, n, sizeof(arr[0]), compare);
   
}

int removeDuplicates(struct arraypair arr[], int n)
{
    if (n == 0 || n == 1)
    {
         return n;
    }
 
    int z = 0;
	int i;
    for (i=0; i < n-1; i++)
    {
        if (arr[i].value != arr[i-1].value)
            arr[z++] = arr[i];
    }
    arr[z++] = arr[n-1];
    return z;
}
 

void sortByPosition(struct arraypair arr[], int n)
{
    qsort(arr, n, sizeof(arr[0]), compare1);
        
}
 

int main()
{
    int n;
	int z;
    scanf("%d", &n);
    struct arraypair arr[n];
	int i;
    for (i=0; i<n; i++)
    {
        scanf("%d", &arr[i].value);
        arr[i].position = i;
    }

    sortData(arr, n);
    z = removeDuplicates(arr, n);
    sortByPosition(arr, z);
    printf("%d\n", z-1);
    for (i=0; i<z; i++)
    {
        printf("%d\n", arr[i].value);
    }
 
    return 0;
//Compilation command used on omega

}


