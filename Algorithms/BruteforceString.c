#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int bruteForce(char *text, char *pattern){
    int n = strlen(text);
    int m = strlen(pattern);
    for (int i = 0; i <= n - m; i++){
        int j = 0;
        while ((j < m) && (text[i + j] == pattern[j]))
        {
            j++;
        }
        if (j == m){
            return i;
        }
    }
    return -1;
}

int main()
{
    char text[] = "hello world";
    char pattern[] = "orl";
    int result = bruteForce(text, pattern);
    if (result == -1){
        printf("Pattern is Not found\n");
    }else{
        printf("Pattern found at index: %d\n", result);
    }
    system("pause");
    return 0;
}