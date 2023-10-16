#include <stdio.h>

float sales[12];
char* months[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

void read_sales() {
    FILE *in_file = fopen("sales.txt", "r");
    for(int i=0; i<12; i++)
        fscanf(in_file, "%f", &sales[i]);
    fclose(in_file);
}

void print_sales() {
    printf("\nMonthly sales report for 2022:\n");
    printf("%-11s %s\n", "Month", "Sales");
    for(int i=0; i<12; i++)
        printf("%-11s $%.2f\n", months[i], sales[i]);
}

void calc_min_max_avg() {
    float min = sales[0], max = sales[0], sum = 0;
    int min_month = 0, max_month = 0;

    for(int i=1; i<12; i++) {
        if (sales[i] < min) {
            min = sales[i];
            min_month = i;
        }
        if (sales[i] > max) {
            max = sales[i];
            max_month = i;
        }
        sum += sales[i];
    }
    printf("\nSales summary:\n");
    printf("Minimum sales: $%.2f (%s)\n", min, months[min_month]);
    printf("Maximum sales: $%.2f (%s)\n", max, months[max_month]);
    printf("Average sales: $%.2f\n", sum/12);
}

void moving_averages() {
    float sum;
    printf("\nSix-Month Moving Average Report:\n");
    for (int i = 5; i < 12; i++) {
        sum = 0;
        for (int j = i - 5; j <= i; j++)
            sum += sales[j];
        printf("%-9s - %-9s: $%.2f\n", months[i - 5], months[i], sum / 6);
    }
}

void sorted_sales() {
    float sorted[12], temp;
    int j;
    sorted[0] = sales[0];

    for(int i=1; i<12; i++) {
        j = i-1;
        temp = sales[i];
        while (temp>sorted[j] && j>=0) {
            sorted[j+1] = sorted[j];
            j--;
        }
        sorted[j+1] = temp;
    }
    printf("\nSales Report (Highest to Lowest):\n");
    printf("%-9s  %s\n", "Month", "Sales");
    for(int i=0; i<12; i++) {
        for(int j=0; j<12; j++)
            if(sorted[i] == sales[j])
                printf("%-9s  $%.2f\n", months[j], sorted[i]);
    }
}

void main() {
    read_sales();
    print_sales();
    calc_min_max_avg();
    moving_averages();
    sorted_sales();
}

