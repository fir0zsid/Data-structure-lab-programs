#include<stdio.h>
#include<ctype.h>
#include<math.h>

char postfix[100];
int stack[100];
int i,top=-1;
void  push(int opd)
{

	if(top==100) 
		printf("\nStack is full");
	else
	{
		top++;
		stack[top] = opd;
	}
}
int pop()
{
	int del;	
	del = stack[top];
	top--;
	return del;
}

int main()
{
	int result,opd2,opd1;
	char choice;

	printf("\nEnter the postfix expression to evaluate:");
	scanf("%s",postfix);

	for(i=0; postfix[i]!='\0'; i++)
	{
		if(isdigit(postfix[i]))
		{
			push(postfix[i] - '0');
		}
		else
		{
			opd2 = pop();
			opd1=pop();
			choice = postfix[i];

			switch(choice)
			{
				case '+': result=opd1+opd2;
					  break;
				case '-': result=opd1-opd2;
					  break;
				case '*': result=opd1*opd2;
					  break;
				case '/': result=opd1/opd2;
					  break;
				case '%': result=fmod(opd1,opd2);
					  break;
				case '^': result=pow(opd1,opd2);
					  break;
				default: printf("\nInvalid Operator");
			}
			push(result);
		}
	}
printf("\nThe result is %d\n",result);

}
