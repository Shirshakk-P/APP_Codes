#include<stdio.h>
#include<math.h>
#include<stdbool.h>

bool isPrime(int n)
{
    for(int i=2; i*i<n; i++)
    {
        if(i%2 == 0)
            return 0;
    }
    return 1;
}

int removeFirst(int num)
{
    int divisor = 1;
    int temp = num;

    while(temp>=10)
    {
        temp /= 10;
        divisor *= 10;
    }
    int removed = ((num)%(divisor));

    return removed;
}

int removeLast(int num)
{
    int removed = (num/10);
    return removed;
}

bool isCurious(int num)
{
    int first = removeFirst(num);
    int last = removeLast(num);

    if(isPrime(num) && (isPrime(first) && isPrime(last)))
    {
        return 1;
    }
    return 0;
}

void output(bool val)
{
    if (val == 1)
    {
        printf("yes\n");
    }
    else printf("no\n");
}

int main()
{
    int num;
    scanf("%d", &num);

    bool val = isCurious(num);
    output(val);
    
    return 0;
}