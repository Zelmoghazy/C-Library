#include <stdio.h>
#include <stdlib.h>

int minimumAbsoluteDifference(vector<int> arr)
{
    int min = INT_MAX;
    sort(arr.begin(), arr.end());
    for (int i = 0; i < arr.size() - 1; i++)
    {
        if (abs(arr[i] - arr[i + 1]) < min)
        {
            min = abs(arr[i] - arr[i + 1]);
        }
    }
    return (min);
}

int main()
{

    system("pause");
    return 0;
}