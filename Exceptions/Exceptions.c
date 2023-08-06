#include <stdio.h>
#include <stdlib.h>
#include <setjmp.h>
#include <assert.h>
#include "Exceptions.h"

ExceptionFrame *Except_stack = NULL;

void except_raise (const Exception *e, const char *file, int line){
    ExceptionFrame *p = Except_stack;
    assert(e);
    if(p == NULL){
        fprintf(stderr,"Uncaught Exception!!");
        if(e->message){
            fprintf(stderr," %s",e->message);
        }else{
            fprintf(stderr, " at 0x%p", (void*)e);
        }
        if(file && line >0){
            fprintf(stderr, " raised at %s:%d\n",file, line);
        }
        fprintf(stderr,"Aborting..\n");
        fflush(stderr);
        abort();
    }
    p->exception = e;
    p->file = file;
    p->line = line;
    Except_stack = Except_stack->prev;
    longjmp(p->env,Except_raised);
}
/**
 * User errors : occur as the result of erroneous user input.
 * Runtime errors :
 * -> Checked : They are not user errors. They are never expected and always indicate program bugs.
 *              there is no way to recover from these kinds of errors; the application must be terminated (assertions)
 * 
 * Exceptions : middle ground between user errors and program bugs.
 * An exception is an error that may be rare and perhaps unexpected, but from which recovery may be possible.
 * Applications raise exceptions, which are handled by recovery code, if recovery is possible.
 * 
 * In C, the standard library functions setjmp and longjmp form the basis for building a structured exception facility.
 * setjmp instantiates a handler and longjmp raises an exception.
 */

Exception Allocate_Failed = {"Allocation Failed"};
Exception Zero_Division = {"Divided by Zero"};

void *allocate (unsigned n)
{
    void *new = malloc(n);
    if(new)
        return new;
    RAISE(Allocate_Failed);    
    assert(0); // Allocation failed and no handler
}

int divide(int a, int b){
    if(b==0){
        printf("Dont divide by zero\n");
        RAISE(Zero_Division);
    }else{
        return a/b;
    }
    return 0;
}

int main()
{

    /** (Handler)
     * The call to setjmp returns zero.
     * The call to longjmp in allocate causes the second return of the value given by longjmp’s second argument 
     */

    /**
     * When setjmp returns zero, execution continues with the call to allocate.
     * If the allocation fails, the longjmp in allocate causes setjmp to return again,
     * this time with the value one, so execution continues with the calls to fprintf and exit. 
     */
    TRY{
        printf("%d\n",divide(6,5));
        divide(5,0);
    }CATCH(Zero_Division){
        printf("Caught exception\n");
    }END_TRY;

    printf("Continue execution Normally\n");             
    system("pause");
    return 0;
}



