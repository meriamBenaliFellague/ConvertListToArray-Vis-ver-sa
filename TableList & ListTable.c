#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int data;
	struct node *next;
}node;

int ReadInput();
void AddNode(node**,int);
int* ListTable(node*,int);
void displayList(node*);
node* TableList(int*,int);

int main(){
	int n;
	printf("1.Convert a list to an array.\n");
	printf("2.Convert array to a list.\n");
	printf("enter 1 or 2: ");
	scanf("%d",&n);
	if(n==1){
		node *head=NULL;
		printf("enter the nodes number ");
		int N=ReadInput(); int j;
		for( j=0;j<N;j++){
	            int input=ReadInput();
	            AddNode(&head,input);
	        }
	        int*a=ListTable(head,N);int i;
	        for( i=0;i<N;i++){
		    printf("%d",a[i]);
	        }
	}else{
		printf("enter the number of elements ");
		int N=ReadInput();
		int k[N],i;
		for( i=0;i<N;i++){
		     k[i]=ReadInput();
		}
	  node *head=TableList(k,N);
		displayList(head);
	}
}

int ReadInput()
{int x;
  printf("enter number: ");
  scanf("%d",&x);
  return x;
}

void AddNode(node **head,int y)
{
  node *p=(node*)malloc(sizeof(node));
  p->data=y;
  if(*head==NULL)
  {
    p->next=NULL;
    *head=p;
  }else{
		node *q=*head;
    while(q->next!=NULL){
    	q=q->next;
    }
    q->next=p;
    p->next=NULL;
  }
}

int* ListTable(node *head,int num){
	node *p=head;int i=0;
  int *t=(int*)malloc(sizeof(int)*num);
	while(p!=NULL){
		t[i]=p->data;
		p=p->next;
		i++;
	}
	return(t);
}

node* TableList(int *s,int num){
    node *head=NULL; int i;
	for(i=0;i<num;i++){
		AddNode(&head,s[i]);
	}
	return head;
}
void displayList(node *head){
	node *p=head;
	while(p!=NULL){
		printf("%d",p->data);
		p=p->next;
	}
}
