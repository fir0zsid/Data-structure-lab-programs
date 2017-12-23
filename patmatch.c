#include<stdio.h>
#include<string.h>

int main()
{
	char str[100],pat[100],rep[100];
	int i,j=0,found=0;

	printf("\nEnter the Main string:");
	scanf("%s",str);
	printf("\nEnter the pattern string:");
	scanf("%s",pat);
	printf("\nEnter the replace string:");
	scanf("%s",rep);

	for(i = 0; str[i] != '\0'; i++)
	{
		j = 0;
		while(str[i+j] == pat[j] && j < strlen(pat))
			j++;

		if(j == strlen(pat))
		{
			found=1;
			for(int k=0 ;k < strlen(rep); k++)
				str[i+k] = rep[k];
			i = i + strlen(pat)-1;
		}
	}

	if(found==0) 
		printf("\nPattern not found!!!");
	else
	{
		printf("The new string is: %s\n",str);
	}
	return 0;
}

