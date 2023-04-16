#include<stdio.h>
#include<stdlib.h>
int ReadInput();
void AddNode(int);
int *ListTable();
void displayList();

struct node{
	int data;
	struct node *next;
};struct node *head=NULL,*p;int t[5];
void TableList(int *s,node*head);

int main(){
	int n;
	printf("1.Convert a list to an array.\n");
	printf("2.Convert array to a list.\n");
	printf("enter 1 or 2: ");
	scanf("%d",&n);
	if(n==1){
		for(int j=0;j<5;j++){
	  int input=ReadInput();
	  AddNode(input);
	}
	int *a=ListTable();
	for(int i=0;i<5;i++){
		printf("%d",a[i]);
	}
	}else{
		int k[5];
		for(int i=0;i<5;i++){
			k[i]=ReadInput();
		}
	   TableList(k,head);
	   displayList();
	}
	
}

int ReadInput()
{int x;
  printf("enter number: ");
  scanf("%d",&x);
  return x;
}

void AddNode(int y)
{struct node *q=head;
  p=(struct node*)malloc(sizeof(struct node));
  p->data=y;
  if(head==NULL)
  {
    p->next=NULL;
    head=p;
  }else
  {
    while(q->next!=NULL){
    	q=q->next;
	}
	q->next=p;
	p->next=NULL;
  }
}

int *ListTable(){
	p=head;int i=0;
	while(p!=NULL){
		t[i]=p->data;
		p=p->next;
		i++;
	}
	return(t);
}

void TableList(int *s,node *head){
	for(int i=0;i<5;i++){
		AddNode(s[i]);
	}
}
void displayList(){
	p=head;
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}
}
