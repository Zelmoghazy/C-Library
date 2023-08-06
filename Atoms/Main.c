#include <stdio.h>
#include <stdlib.h>
#include "Atoms.h"
#include <string.h>

int main()
{
    const char *Test = atom_string("Zeyad");
    printf("%s\n",Test);
    printf("%d\n",atom_length(Test));
    atom_reset();
    system("pause");
    return 0;
}