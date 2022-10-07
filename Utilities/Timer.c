#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>

void delay(int ms);
int timer(int seconds);
int selection();
int printdata();
//---------------------------------------
int minute = 0; // global variables
int second = 0;
int currentmin;
int currentsec;
int flag = 0; // flag = 0 (continue running) = 1 (interrupt)

void delay(int ms) // delay function == systick timer
{
    clock_t timeDelay = ms + clock();
    while (timeDelay > clock())
        ;
}

int timer(int seconds)
{
    while (1)
    {
        minute = (int)seconds / 60;
        second = seconds - minute * 60;

        while (1)
        {
            while (!kbhit() && flag == 0) // khbit == getchar to check whether a user pressed a key
            {
                if (minute == 0 && second < 1)
                {
                    minute = second = 0;
                    flag = 1;
                    printdata();
                    break;
                }
                if (minute < 0)
                {
                    minute = 0;
                }
                if (second < 0)
                {
                    second = 59;
                    --minute;
                }
                printdata();
                delay(1000); // delay 1 second
                --second;
            }

            selection();

            if (flag == 2)
            {
                flag = 0;
                break;
            }
            if (flag == 3)
            {
                return 0;
            }
        }
    }
}

int selection() // timer functions
{
    switch (getch())
    {

    case 49: // 49 is the code for key '1' in keyboard  1 = start
        minute = currentmin;
        second = currentsec;
        flag = 0;

        break;

    case 50: // 50 is the code for key '2' in keyboard  2 = stop
        currentmin = minute;
        currentsec = second;
        flag = 1;
        break;

    case 51: // 51 is the code for key '3' in keyboard  3 = clear
        minute = second = 0;
        flag = 1;
        printdata();
        break;

    case 52: // 52 is the code for key '4' in keyboard 4 = reset
        flag = 2;
        break;

    case 53: // 53 is the code for key '5' in keyboard 5 = end the program
        exit(0);
        break;

    case 54:
        flag = 3;
        break;
    }
}

int printdata()
{
    system("cls"); // clear old data printed on screen == LCDcommand(Clear);
    printf("1.Start 2.Pause 3.Clear 4.Reset 5. End\n");
    char buffer[10];
    sprintf(buffer, "%02d:%02d", minute, second);
    printf("%s", buffer); // print time on screen
}

//-------------------------------

int main()
{

    timer(120);
    system("cls");
    printf("hello world");
    getch();

    return 0;
}