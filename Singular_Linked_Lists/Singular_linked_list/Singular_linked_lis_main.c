#include <stdio.h>
#include <stdlib.h>

struct node *createList(struct node *start);
void displayList(struct node *start);
void countNodes(struct node *start);
void search(struct node *start,int x);
struct node *insertInBeginning(struct node *start,int data);
struct node *insertAtEnd(struct node *start,int data);
struct node* insertAtEnd_modified(struct node *end, int data);
int insertAfter(struct node *start,int data,int x);
struct node *insertBefore(struct node *start,int data,int x );
struct node *insertAtPosition(struct node *start,int data,int k);
struct node *deleteNode(struct node *start,int data);
struct node *reverseList(struct node *start);

struct node
{
    int data;
    struct node *link;
}node;

struct node *end;
struct node* create_new_node(int data)
{
    struct node* new_node = (struct node*)malloc(sizeof(struct node));

   if(new_node == NULL)
   {
       printf("\nCouldn't allocate memory\n");
       return NULL;
   }
   new_node->data = data;
   return new_node;
};

struct node* createList(struct node *start)
{
    int num_of_elements = 0,data = 0;
   printf("\nEnter no of elements to be entered \n");
   scanf("%d",&num_of_elements);
   if(num_of_elements == 0)
   {
       printf("\nInvalid input");
       return NULL;
   }
   printf("\n enter the first element");
   scanf("%d", &data);
   start = insertInBeginning(start, data);
   end = start;
   for(int loop_var=1;loop_var<num_of_elements;loop_var++)
   {
       printf("\n enter the rest of the elemets");
       scanf("%d", &data);
       end = insertAtEnd_modified(end,data);
   }


   return start;
}

struct node* insertInBeginning(struct node *start, int data)
{
    struct node* temp = create_new_node(data);

    if(temp == NULL)
    {
        return NULL;
    }
    temp->link = start;
    start = temp;

return start;


}

struct node* insertAtEnd(struct node *start, int data)
{
    struct node* node_ptr = start;

    while(node_ptr->link != NULL)
    {
        node_ptr = node_ptr->link;
    }
    struct node* new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL)
    {
        printf("\ncouldn't allocate memory\n");
        return NULL;
    }
    new_node->data = data;
     node_ptr->link = new_node;
     new_node->link = NULL;

     return new_node;

}

struct node* insertAtEnd_modified(struct node *end, int data)
{

    struct node* new_end_node = (struct node*)malloc(sizeof(struct node));
    if(new_end_node == NULL)
    {
        printf("\ncouldn't allocate memory\n");
        return NULL;
    }
    new_end_node->data = data;
     end->link = new_end_node;
     new_end_node->link = NULL;

     return new_end_node;

}
int insertAfter(struct node *start,int data,int data_to_inserted)
{
    struct node *new_node = create_new_node(data_to_inserted);
    if(new_node == NULL)
    {
        return NULL;
    }
    struct node *node_ptr= start;
    while(node_ptr!=NULL)
    {

        if(node_ptr->data == data)
            break;
        node_ptr = node_ptr->link;
    }
    if(node_ptr==NULL)
    {
        printf("\nelement not found\n");

    }

    else
    {
        new_node->link = node_ptr->link;
        node_ptr->link = new_node;
        if(new_node->link == NULL)
            end= new_node;
    }
}

struct node * insertBefore(struct node *start,int data,int data_to_inserted)
{
    struct node *new_node = create_new_node(data_to_inserted);
    if(new_node == NULL)
    {
        return NULL;
    }
    struct node *node_ptr= start;

    if(node_ptr == NULL)
    {

        printf("\nList is empty\n");
    }
    else if(data == node_ptr->data)
    {
        new_node->link = node_ptr;
        start = new_node;
        return start;

    }
    while(node_ptr->link!=NULL)
    {
        if(node_ptr->link->data == data)
            break;
        node_ptr = node_ptr->link;
    }
    if(node_ptr->link ==NULL)
    {
        printf("\nelement not found\n");

    }

    else
    {
        new_node->link = node_ptr->link;
        node_ptr->link = new_node;

    }
    return start;
}

struct node *insertAtPosition(struct node *start,int data_to_inserted,int k)
{
    struct node *new_node = create_new_node(data_to_inserted);
    if(new_node == NULL)
    {
        return NULL;
    }
    struct node *node_ptr= start;
    for(int i=1; i<k-1 && node_ptr!= NULL;i++)
    {
        node_ptr = node_ptr->link;
    }
    if(node_ptr==NULL)
    {
        printf("\nelement not found\n");

    }

    else
    {
        new_node->link = node_ptr->link;
        node_ptr->link = new_node;
        if(new_node->link == NULL)
            end= new_node;
        else if(k == 1)
        {
            start = new_node;
        }
        else{

        }

    }
    return start;
}

struct node *deleteNode(struct node *start, int data)
{
    struct node *loop_node_ptr = start;
    struct node *temp ;
     if(start->data == data)
    {
        temp = start;
        start = start->link;
         //temp->link = NULL;

         free(temp);
        return start;
    }
    while(loop_node_ptr->link != NULL)
    {
        printf("%d loop_node->data",loop_node_ptr->link->data);
        if(loop_node_ptr->link->data == data)
            break;
        loop_node_ptr = loop_node_ptr->link;

    }

    if(loop_node_ptr->link == NULL)
    {
        printf("\nelement not found\n");
        return start;
    }
    else{
        temp= loop_node_ptr->link;
     loop_node_ptr->link = temp->link;
    }

     temp->link = NULL;
     free(temp);
return start;
}

struct node *reverseList(struct node *start)
{
    struct node *prev, *ptr, *next;
    prev = NULL;
    ptr = start;
    while(ptr!= NULL)
    {
        next = ptr->link;
        ptr->link = prev;
        prev=ptr;
        ptr= next;

    }
    return prev;

}
void displayList(struct node *start)
{
    struct node *node_ptr = start;
    while(node_ptr != NULL)
    {
        printf("%d ",node_ptr->data);
        node_ptr = node_ptr->link;
    }
}

void countNodes(struct node *start)
{
    int count =0;
    struct node *node_ptr = start;
    while(node_ptr != NULL)
    {
        count++;
        node_ptr = node_ptr->link;
    }
    printf("no of nodes %d",count);
}

void search(struct node *start, int data)
{
    int count =1;
    struct node *node_ptr = start;
    while(node_ptr != NULL)
    {
        if(node_ptr->data == data)
        {
            break;
        }
        count++;
        node_ptr = node_ptr->link;
    }
    if(node_ptr != NULL)
    {
        printf("element found at %d",count);
    }
    else{
        printf("\nelement not found\n");
    }

}

void main()
{
	struct node *start=NULL;
	int choice,data,x,k;

	start = createList(start);

	while(1)
	{
		printf("\n");
		printf("1.Display list\n");
		printf("2.Count the number of nodes\n");
		printf("3.Search for an element\n");
		printf("4.Insert in empty list / Insert in beginning of the list\n");
		printf("5.Insert a node at the end of the list\n");
		printf("6.Insert a node after a specified node\n");
		printf("7.Insert a node before a specified node\n");
		printf("8.Insert a node at a given position\n");
		printf("9.Delete a node\n");
		printf("10.Reverse the list\n");
		printf("11.Quit\n\n");

		printf("Enter your choice : ");
		scanf("%d",&choice);

		if(choice==11)
			break;

		switch(choice)
		{
		 case 1:
			displayList(start);
			break;
		 case 2:
			countNodes(start);
			break;
		 case 3:
			printf("Enter the element to be searched : ");
			scanf("%d",&data);
			search(start,data);
			break;
		 case 4:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			start=insertInBeginning(start,data);
			break;
		 case 5:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			end = insertAtEnd_modified(end,data);
			break;
		 case 6:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element after which to insert : ");
			scanf("%d",&x);
			insertAfter(start,x,data);
			break;
		 case 7:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the element before which to insert : ");
			scanf("%d",&x);
			start=insertBefore(start,x,data);
			break;
		 case 8:
			printf("Enter the element to be inserted : ");
			scanf("%d",&data);
			printf("Enter the position at which to insert : ");
			scanf("%d",&k);
			start=insertAtPosition(start,data,k);
			break;
		 case 9:
			printf("Enter the element to be deleted : ");
			scanf("%d",&data);
			start=deleteNode(start, data);
			break;
		 case 10:
			start=reverseList(start);
			break;
		 default:
			 printf("Wrong choice\n");
		}
	}
}/*End of main()*/
