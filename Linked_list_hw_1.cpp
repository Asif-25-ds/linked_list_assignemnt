#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node *next;	
};
struct node *ttemp,*temp,*first,*p;
void create_first(int x){
	first=(struct node *)malloc(sizeof(struct node));
	first->data=x;
	first->next=NULL;
}
void add_nodes(int x){
	temp=first;
	while(temp->next!=NULL){
		temp=temp->next;
	}
	ttemp=(struct node *)malloc(sizeof(struct node));
	ttemp->data=x;
	ttemp->next=NULL;
	temp->next=ttemp;
}
void display(){
	temp=first;
	while(temp!=NULL){
		printf("%d ",temp->data);
		temp=temp->next;
	}
}
//function of sum of data of linked list
void list_sum(){
	temp=first;
	int sum=0;
	while(temp!=NULL){
		sum=sum+temp->data;
		temp=temp->next;
	}
	printf("\nThe sum of your inserted data is %d\n",sum);
}

//function of add node after the given data
void addnode_after(int x,int y){
	temp=first;
	while(temp->data!=x){
		temp=temp->next;
	}
	ttemp=temp->next;
	p=(struct node *)malloc(sizeof(struct node));
	p->data=y;
	p->next=ttemp;
	temp->next=p;
}

//function of node inserting before given node

void addnode_before(int x,int y){
	temp=first;
	while(temp->data!=x){
		ttemp=temp;
		temp=temp->next;
	}
	p=(struct node *)malloc(sizeof(struct node));
	p->data=y;
	p->next=temp;
	ttemp->next=p;
	
}

//function of deletion of node after given node
void del_node_after(int x){
	temp=first;
	while(temp->data!=x){
		temp=temp->next;
	}
	p=temp->next->next;
	ttemp=temp->next;
	temp->next=p;
	ttemp->next=NULL;
	free(ttemp);
}

//function of deletion of node after given node
void del_node_before(int x){
	temp=first;
	while(temp->next->data!=x){
		ttemp=temp;
		temp=temp->next;
	}
	p=temp->next;
	ttemp->next=p;
	temp->next=NULL;
	free(temp);
	
}

int main(){
	int x;
	char y='y';
	printf("Enter first data for linked_list:-");
	scanf("%d",&x);
	create_first(x);
	while(y!='n'){
	printf("Enter y for continuing entry of data or n for Exit:-");
	scanf(" %c",&y);
	if(y=='y'){
		printf("Enter data for new node:-");
		int z;
		scanf("%d",&z);
		add_nodes(z);
	}
	else if(y=='n'){
		break;
	}
	}
	printf("Do you want to print list?\n");
		printf("Enter d for Display and e for exit:-");
		scanf(" %c",&y);
		if(y=='d'){
			display();
		}
		else if(y=='e'){
			printf("\nYOU EXIT\n");
		}
	list_sum();
	
	printf("Enter data for adding node after your entered data :-");
	int num1,num2;
	scanf("%d",&num1);
	printf("Enter data which you want to insert:-");
	scanf("%d",&num2);
	addnode_after(num1,num2);
	printf("Your List is:-");
	display();
	printf("\n");
	
	printf("Enter data for adding node before your entered data :-");
	scanf("%d",&num1);
	printf("Enter data which you want to insert:-");
	scanf("%d",&num2);
	addnode_before(num1,num2);
	printf("Your List is:-");
	display();
	printf("\n");
	
	printf("Enter data for deletion of node(node after your data entered was deleted):-");
	scanf("%d",&num1);
	del_node_after(num1);
	printf("Your List is:-");
	display();
	printf("\n");
	
	printf("Enter data for deletion of node(node before your data entered was deleted):-");
	scanf("%d",&num1);
	del_node_before(num1);
	printf("Your List is:-");
	display();
	printf("\n");
	
	return 0;
}