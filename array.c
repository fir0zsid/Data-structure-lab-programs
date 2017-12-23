#include <stdio.h>
#define size 10
int a[size],i,pos,elem,n;


void create()
{
	printf("\nHow many Elements?\n");
	scanf("%d",&n);
	for(i=0;i<n;i++)
	{
		printf("\nEnter the element%d:",i+1);
		scanf("%d",&a[i]);
	}
}

void display()
{
	for(i=0;i<n;i++)
	{
		printf("\n%d",a[i]);
	}
}

void insert()
{
	if(n<size-1) 
	{
		printf("\nArray is full!!!\n");
		return;
	}
	printf("\nWhich number?:");
	scanf("%d",&elem);
	printf("\nEnter the position:");	
	scanf("%d",&pos);
	n++;
	for(i=n-1;i>=pos-1;i--)
	{
		a[i+1]=a[i];
	}

	a[pos-1]=elem;
	printf("The number %d has been entered at %d postion:",elem,pos);
}

void delete()
{
	if(n<0) 
	{
		printf("\n Array is empty!!!");
		return;
	}
	printf("Enter the position's element to be deleted:");
	scanf("%d",&pos);
	for(i=pos-1;i<n;i++)
	{
		a[i]=a[i+1];
	}
	n--;
	printf("The number %d position's element has been deleted!!!",pos);
}

int main()
{
	int choice;
	while(1)
	{

		printf("\n\n1.Create an array\n2.Diplay the elements\n3.Insert an element\n4.delete an element\n5.Exit\n");
		printf("\nChoose an option from above menu:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: create();
				break;
			case 2: display();
				break;
			case 3: insert();
				break;
			case 4: delete();
				break;
			case 5: return(0);
			default : printf ("\nWrong Choice!!!");
		}

	}

}
