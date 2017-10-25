#include <stdio.h>
#include <time.h>

void time_diff(struct tm t1, struct tm t2, struct tm *diff);

struct tm start(time_t raw_tm);
struct tm stop(time_t raw_tm);

//TODO: write a stopwatch program. If you hit enter start the stopwatch, if you hit enter again stop the watch. If you hit escape, the program should exit.
//use the time.h header: https://www.tutorialspoint.com/c_standard_library/c_function_localtime.htm
//it's enough if you can measure the elapsed seconds, and minutes

int main()
{
	time_t raw_time1;
	time_t raw_time2;
	int flip = 0;

    char c = '\0';

    do {
           c = getch();
            if (c == 'c')
                clear();
            if (c == 13 && !flip) {
                time(&raw_time1);
                flip = 1;
                printf("round start\n");
                c = '\0';
            }
            if (c == 13 && flip) {
                time(&raw_time2);
                flip = 0;

                printf("time elapsed: %d min, %d s\n", (raw_time2 - raw_time1) / 60, (raw_time2 - raw_time1) % 60);
            }


	} while(c != 27);

    return 0;
}

void clear()
{
    system("cls");
}
