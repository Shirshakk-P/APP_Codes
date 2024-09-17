#include<stdio.h>
#include<string.h>

void printFrequency(int arr[26])
{
	for(int i=0; i<26; i++)
	{
		if(arr[i]!=0)
			printf("%c %d\n",(char)(i+'a'), arr[i]);
	}
}

void uniqueFrequency(int n, char str[n], int arr[n])
{
	for(int i=1; i<n; i++)
	{
		if(str[i] == str[i-1])
		{
			arr[str[i]-'a']--;
		}
	}
}

void storeFrequency(int n, char str[n], int arr[n])
{
	for(int i=0; i<n; i++)
	{
		arr[str[i] - 'a']++;
	}
}

int main()
{
	char str[1000];
	scanf("%s", str);

	int arr[26] = {0};
	int len = strlen(str);

	storeFrequency(len, str, arr);
	uniqueFrequency(len, str, arr);
	printFrequency(arr);

	return 0;
}