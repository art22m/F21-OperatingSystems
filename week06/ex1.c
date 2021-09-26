#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int arrival_time;
    int burst_time;
} Process;

typedef struct {
    int completion_time;
    int turn_around_time;
    int waiting_time;
} Result;

/* Comparator for not working qsort
int compareProcesses(Process a, Process b) {
    if (a.arrival_time < b.arrival_time) {
        return -1;
    } else if (a.arrival_time == b.arrival_time) {
        if (a.burst_time < b.burst_time)
            return -1;
        else
            return 1;
    } else {
        return 1;
    }
}
*/

void swap(Process* first, Process* second){
    Process temp;

    temp = *first;
    *first = *second;
    *second = temp;
}

int max(int a, int b) {
    return a > b ? a : b;
}

int main() {
    int processes_number;
    printf("Enter the number of processes: ");
    scanf("%d", &processes_number);

    Process processes_list[processes_number];
    Result results_list[processes_number];

    int num;
    printf("Enter Arrival time and Burst time for each processes:\n");
    for (int i = 0; i < processes_number; ++i) {
        printf("Enter Arrival time for process [%d]: ", i + 1);
        scanf("%d", &num);
        processes_list[i].arrival_time = num;
        printf("Enter Burst time for process [%d]: ", i + 1);
        scanf("%d", &num);
        processes_list[i].burst_time = num;

        results_list[i].completion_time = 0;
        results_list[i].turn_around_time = 0;
        results_list[i].waiting_time = 0;
    }

    // qsort(processes_list, processes_number, sizeof(Process), compareProcesses); Not working =(
    // Bubble sort:
    for (int i = 0; i < processes_number; ++i) {
        for (int j = 0; j < processes_number - i - 1; ++j) {
            if (processes_list[j].arrival_time > processes_list[j + 1].arrival_time) {
                swap(&(processes_list[j]), &(processes_list[j + 1]));
            }
        }
    }

    results_list[0].waiting_time = 0;
    results_list[0].completion_time = processes_list[0].burst_time + processes_list[0].arrival_time;
    results_list[0].turn_around_time = processes_list[0].burst_time + results_list[0].waiting_time;
//    printf("%d %d %d\processes_number", results_list[0].waiting_time, results_list[0].turn_around_time, results_list[0].completion_time);

    for (int i = 1; i < processes_number; ++i) {
        int completion_time = max(results_list[i - 1].completion_time, processes_list[i].arrival_time) + processes_list[i].burst_time;
        int turn_around_time = completion_time - processes_list[i].arrival_time;
        int waiting_time = max(turn_around_time - processes_list[i].burst_time, 0);

        results_list[i].waiting_time =  waiting_time;
        results_list[i].turn_around_time =  turn_around_time;
        results_list[i].completion_time = completion_time;

//        printf("%d %d %d\processes_number", waiting_time, turn_around_time, completion_time);
    }

    printf("P#  AT  BT  CT  TAT  WT\n\n");
    double average_turn_around_time = 0.0;
    double average_waiting_time = 0.0;
    for (int i = 0; i < processes_number; ++i) {
        printf("P%d  %d   %d   %d   %d    %d\n", i,
               processes_list[i].arrival_time,
               processes_list[i].burst_time,
               results_list[i].completion_time,
               results_list[i].turn_around_time,
               results_list[i].waiting_time);
        average_turn_around_time += results_list[i].turn_around_time;
        average_waiting_time += results_list[i].waiting_time;
    }

    average_turn_around_time = average_turn_around_time / processes_number;
    average_waiting_time = average_waiting_time / processes_number;

    printf("\nAverage Turn Around time = %f\nAverage Waiting time = %f", average_turn_around_time, average_waiting_time);
    return 0;
}