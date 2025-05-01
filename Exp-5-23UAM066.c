#include <stdio.h>
struct Interval{
    int start;
    int end;
};
void sortByEndTime(struct Interval arr[], int n){
    int i, j;
    struct Interval temp;
    for(i=0; i<n-1; i++) {
        for(j=i+1; j<n; j++) {
            if(arr[i].end > arr[j].end) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main() {
    struct Interval intervals[50];
    int n, i;
	int count = 0, lastEnd = 0;

    printf("Enter number of intervals: ");
    scanf("%d",&n);

    printf("Enter start and end time of each interval:\n");
    for(i =0; i<n; i++){
        printf("Interval %d:\n", i + 1);
        printf("Start: ");
        scanf("%d", &intervals[i].start);
        printf("End: ");
        scanf("%d", &intervals[i].end);
    }

    sortByEndTime(intervals, n);

    printf("\nSelected intervals:\n");
    for(i =0; i<n; i++){
        if(intervals[i].start >= lastEnd){
            printf("(%d, %d)\n", intervals[i].start, intervals[i].end);
            lastEnd = intervals[i].end;
            count++;
        }
    }
    printf("Total non-overlapping intervals selected: %d\n", count);

    return 0;
}

