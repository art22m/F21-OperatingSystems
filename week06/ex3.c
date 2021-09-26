#include <stdio.h>

typedef struct {
    int arrival_time;
    int burst_time;
} Process;

typedef struct {
    int completion_time;
    int turn_around_time;
    int waiting_time;
} Result;

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

    int quantum;
    printf("Enter the size of quantum: ");
    scanf("%d", &quantum);

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

    // Bubble sort:
    for (int i = 0; i < processes_number; ++i) {
        for (int j = 0; j < processes_number - i - 1; ++j) {
            if (processes_list[j].arrival_time > processes_list[j + 1].arrival_time) {
                swap(&(processes_list[j]), &(processes_list[j + 1]));
            }
        }
    }


    int rem_bt[processes_number];
    for (int i = 0; i < processes_number; ++i)
        rem_bt[i] = processes_list[i].burst_time;

    int t = 0;
    int is_done = 0;
    while(!is_done) {
        is_done = 1;
        for (int i = 0; i < processes_number; ++i) {
            if (rem_bt[i] > 0) {
                is_done = 0;

                if (rem_bt[i] > quantum) {
                    t += quantum;
                    rem_bt[i] -= quantum;
                } else {
                    t += rem_bt[i];
                    results_list[i].waiting_time = max(t - processes_list[i].burst_time - processes_list[i].arrival_time, 0);
                    results_list[i].completion_time = t;
                    rem_bt[i] = 0;
                }
            }
        }
    }

    for (int i = 0; i < processes_number ; i++)
        results_list[i].turn_around_time = processes_list[i].burst_time + results_list[i].waiting_time;

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


/*
 *  1) For Round robin with processes P1(0, 4), P2(2, 1), P3(2, 3) and quantum
 *  equal to 1, we have Average turn around time = 4.(6)
 *  But for the same processes using "Shortest job next" we have Average
 *  turn around time = 4.(3) and for "Fist come, first served" - 4.(3)
 *
 *  2) For Round robin with processes P1(0,1), P2(0,2), P3(0,4), P4(0,6), P5(0,8),
 *  P(11,8), P(11,6), P(11,4), P(11,2), P(11,1) and quantum
 *  equal to 3, we have Average turn around time = 20.6
 *  But for the same processes using "Shortest job next" we have Average
 *  turn around time = 12.1 and for "Fist come, first served" - 17.6.
 *
 *  From 1) and 2) we can conclude, that Round robin may be faster and slower than
 *  "Shortest job next" and "Fist come, first served" algorithms.
 */