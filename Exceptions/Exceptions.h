#ifndef EXCEPTION_LIB
#define EXCEPTION_LIB
#include <setjmp.h>

/**
 * Exceptions must be global or static variables so that their addresses identify them uniquely.
 * It is an unchecked runtime error to declare an exception as a local variable or as a parameter. 
 * An exception e is raised by the RAISE macro or by the function Except_raise
 */
typedef struct Exception{
    const char *message; // Error message
}Exception;


typedef struct ExceptionFrame{
    struct ExceptionFrame *prev;
    jmp_buf env;
    const char *file;
    int line;
    const Exception *exception;
}ExceptionFrame;

extern ExceptionFrame *Except_stack;

enum {Except_entered = 0,
      Except_raised,
      Except_handled,
      Except_finalized};

void except_raise(const Exception *e, const char *file, int line);

/**
 * __FILE__ and __LINE__ are predefined macros that expand to
 *  the current file name and line number respectively. 
 */
#define RAISE(e) except_raise(&(e), __FILE__, __LINE__)

#define RERAISE except_raise(Except_frame.exception, Except_frame.file, Except_frame.line)

#define RETURN switch (Except_stack = Except_stack->prev,0) default: return

#define TRY do { \
    volatile int Except_flag; \
    ExceptionFrame Except_frame; \
    Except_frame.prev = Except_stack;\
    Except_stack = &Except_frame; \
    Except_flag = setjmp(Except_frame.env); \
    if (Except_flag == Except_entered) {

#define CATCH(e) \
        if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
    } else if (Except_frame.exception == &(e)) { \
        Except_flag = Except_handled; \

#define ELSE \
        if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
    else { \
        Except_flag = Except_handled; \

#define FINALLY \
        if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
    }{ \
        if (Except_flag == Except_entered) \
            Except_flag = Except_finalized; \

#define END_TRY \
        if (Except_flag == Except_entered) Except_stack = Except_stack->prev; \
        } if (Except_flag == Except_raised) RERAISE; \
    } while (0)


/**
 * Except_stack points to the top exception frame on the exception stack,
and the prev field of each frame points to its predecessor. As suggested
by the definition of RERAISE in the previous section, raising an exception
stores the address of the exception in the exception field, and stores
the exception coordinates — the file and line number where the excep-
tion was raised — in the file and line fields.
The TRY clause pushes a new Except_Frame onto the exception stack
and calls setjmp. Except_raise, which is called by RAISE and RERAISE,
fills in the exception, file, and line fields in the top frame, pops the
Except_Frame off the exception stack, and calls longjmp. CATCH
clauses test the exception field of this frame to determine which han-
dler applies. The FINALLY clause executes its clean-up code and reraises
the exception stored in the popped frame.
If an exception occurs and control reaches an END_TRY clause without
handling it, the exception is reraised. 
 */

#endif // EXCEPTION_LIB