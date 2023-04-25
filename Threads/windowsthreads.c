#include <windows.h>
#include <stdio.h>

unsigned long Sum; /* data is shared by the thread(s) */
/* The thread will execute in this function */
unsigned long WINAPI Summation(LPVOID Param)
{
    unsigned long Upper = *(unsigned long *)Param;
    for (unsigned long i = 1; i <= Upper; i++)
        Sum += i;
    return 0;
}

int main()
{
    unsigned long ThreadId;
    HANDLE ThreadHandle;
    int Param;
    Param = 5;
    /* create the thread */
    ThreadHandle = CreateThread(
        NULL,       /* default security attributes */
        0,          /* default stack size */
        Summation,  /* thread function */
        &Param,     /* parameter to thread function */
        0,          /* default creation flags */
        &ThreadId); /* returns the thread identifier */
    /* now wait for the thread to finish */
    WaitForSingleObject(ThreadHandle, INFINITE);
    /* close the thread handle */
    CloseHandle(ThreadHandle);
    printf("sum = %lu\n", Sum);
    system("pause");
}