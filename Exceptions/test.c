#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>

jmp_buf save_buff;


int divide(int a, int b){
    if(b==0){
        printf("Dont divide by zero\n");
        longjmp(save_buff,1);
    }else{
        return a/b;
    }
    return 0;
}

int main()
{
    if(setjmp(save_buff) == 0){
        printf("%d\n",divide(5,0));
    }else{
        printf("Error ! caugh the error\n");
    }

    system("pause");
    return 0;
}