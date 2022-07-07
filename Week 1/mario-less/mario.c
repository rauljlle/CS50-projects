#include <cs50.h>
#include <stdio.h>

int askForHeight(void);
void printBricks(int n);

int main(void)
{
    int height = askForHeight();
    printBricks(height);
}


void printBricks(int n)
{
    //For i in n
    for
    (int i = 0; i < n; i++)
    {
        //print (n - i) spaces,
        for
        (int j = n - i; j > 0; j--)
        {
            printf(" ");
        }
        //print i times '#',
        for
        (int k = i; k > 0; k--)
        {
            printf("#");
        }
        //and break the line
        printf("\n");
    }
}


int askForHeight(void)
{
    int n;
    // While height is not valid, keep
    // asking for a valid height
    do
    {
        n = get_int("Height: ");
    }
    while (n <= 0 || n > 8);

    return n;
}