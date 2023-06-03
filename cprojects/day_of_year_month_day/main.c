#include <stdio.h>
#include <stdlib.h>


static int daytab[2][13] = {
        {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31},
        {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31}
    };

int month_day(int year, int yearday,int *pmonth, int *pday){
    int i, leap;
    if (yearday < 1){
        return -1;
    }
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if ((leap && (yearday > 366)) || (!leap && (yearday > 365))){
        return -1;
    }
    for (i = 1; yearday > *(*(daytab + leap) + i); i++){
        yearday -= *(*(daytab + leap) + i);
    }
    *pmonth = i;
    *pday = yearday;
    printf("%d/%d\n", *pmonth, *pday);
    return 0;

}

int day_of_year (int year, int month, int day){
    int i, leap;

    if ((month < 1) || (month > 12) || (day < 1)){
        return -1;
    }
    leap = ((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0);
    if (day > (*(*(daytab + leap) + month))){
        return -1;
    }

    for (i = 1; i < month; i++){
        day += *(*(daytab + leap) + i);
    }
    printf("%d\n", day);
    return 0;
}

int main()
{
    //printf("%d\n", daytab[0][2]);
    //printf("%d\n", *(*(daytab + 1) + 2));
    int pmonth = 0;
    int pday = 0;
    if ((month_day(2020, 366, &pmonth, &pday)) == -1){
        printf("month_day failed\n");
    }
    if ((day_of_year (2020, 1, 4)) == -1){
        printf("day_of_year failed\n");
    }

    getchar();
    return 0;
}
