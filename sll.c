#include <stdio.h>
#include <stdlib.h>

struct node
{
	char usn[20];
	char name[20];
	char branch[20];
	char sem[5];
	char phno[12];
	struct node * next;
};
typedef struct node * NODE;
NODE first=NULL;

NODE create()
{
	NODE new;
	new = (NODE)malloc(sizeof(struct node));
	if(new==NULL) printf("\n Sorry Memory couldn't be allocated");
	else
	{
		printf("\nEnter the usn:");
		scanf("%s",new->usn);
		printf("\nEnter the name:");
		scanf("%s",new->name);
		printf("\nEnter the branch:");
		scanf("%s",new->branch);
		printf("\nEnter the semester:");
		scanf("%s",new->sem);
		printf("\nEnter the phone number:");
		scanf("%s",new->phno);
		new->next=NULL;
		return(new);
	}
}

void insertbegin()
{
	NODE new;
	new = create();
	if(first==NULL)
	{
		first =new;
	}
	else
	{	new->next=first;
		first=new;
	}
		
}

void insertend()
{
	NODE new,temp;
	new = create();
	if(new==NULL)
	{
		first=new;
	}
	else
	{
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=new;
		free(temp);
	}
}

void deletebegin()
{
	NODE temp;
	if(first==NULL) printf("\nThe list is empty!!!");
	else
	{
		temp=first;
		temp=temp->next;
		first=temp;
		free(temp);
	}
}

void deleteend()
{
	NODE temp;
	if(first==NULL) printf("\nThe list is empty!!!");
	else if(first->next==NULL)
	{
		first=NULL;
	}
	else
	{
		temp=first;
		while(temp->next!=NULL)
		{
			temp=temp->next;
		}
		temp->next=NULL;
		free(temp);
	}
}	

void display()
{
	NODE temp;
	if(first==NULL) printf("\nThe list is empty!!!\n");
	else
	{
		temp=first;
		while(temp!=NULL)
		{
			printf("\n%s\n%s\n%s\n%s\n%s\n",temp->usn,temp->name,temp->branch,temp->sem,temp->phno);
			temp=temp->next;
		}
		free(temp);
	}
}
int main()
{
	int choice;
	while(1)
	{
		
	printf("\nSLL OPERATIONS\n----------------------------------\n");
	printf("\n1.Insert beginning\n2.Delete beginnig\n3.Insert at the end\n4.Delete from the end\n5.Diplay\n6.Exit");
	printf("\nEnter your choice:");
	scanf("\n%d",&choice);
	switch(choice)
	{
		case 1: insertbegin();
			break;
		case 2: deletebegin();
			break;
		case 3: insertend();
			break;
		case 4: deleteend();
			break;
		case 5: display();
			break;
		case 6: return 0;
		default: printf("\nWrong choice!!!");
	}
	}

return 0;
}
