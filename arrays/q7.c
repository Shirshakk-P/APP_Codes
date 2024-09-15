#include<stdio.h>
#include<string.h>
#include<stdbool.h>

int printResult(bool i);

int isPalindrome(char str[])
{
	int len=strlen(str);
	int head=0;
	int tail=len-1;

	while(head<tail)
	{
		if(str[head]!=str[tail])
		{
			return 0;
		}
		head++;
		tail--;
	}
	return 1;
}

int printResult(bool i)
{
	if(i==1)
	{
		printf("yes\n");
	}
	else 
	{
		printf("no\n");
	}
}

int main()
{
	int n;
	scanf("%d\n",&n);

	char str[20];
	bool results[n];
	
	for(int i=0; i<n; i++)
	{
		scanf("%s", str);
		results[i]=isPalindrome(str);
	}

	for(int i=0; i<n; i++)
	{
		printResult(results[i]);
	}
	return 0;
}
