
Stack *InitStack(int initialSize)
{
    Stack *S = malloc(sizeof(Stack));
    S->MAX = initialSize;
    S->top = 0;
    S->A = calloc(S->MAX, sizeof(char));
    if (S->A == NULL)
    {
        printf("Allocation failed");
        exit(0);
    }
    return S;
}

void FreeStack(Stack *S)
{
    free(S->A);
    S->A = NULL;
    free(S);
}

void Push(Stack *S, char value)
{
    if (S->top < S->MAX)
    {
        S->A[S->top] = value;
        S->top++;
    }
    else
    {
        printf("Stack overflow");
    }
}

void Pop(Stack *S)
{
    if (S->top == 0)
    {
        printf("Empty Stack");
    }
    else
    {
        S->top--;
        S->A[S->top] = 0;
    }
}

bool IsStackEmpty(Stack *S)
{
    if (S->top == 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

char stackTop(Stack *S)
{
    if (S->top > 0)
    {
        return S->A[S->top - 1];
    }
    else
    {
        printf("Empty Stack");
        return -1;
    }
}