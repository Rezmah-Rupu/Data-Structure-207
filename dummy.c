#include<stdio.h>
#include<stdlib.h>
#define NULL_VALUE -99999
#define SUCCESS_VALUE 99999
struct node
{
    int item ; //stores value
    struct node *next ; //will keep memory address of next node
    struct node *prev ; //will keep memory address of previous node
};

struct node * head ;
struct node * tail ;

void initialize_list()
{
    head = 0 ; //set to NULL
    tail = 0 ; //set to NULL
}

int insert_first(int item)
{
    //step-1: create a new node
    struct node *new_node ;
    new_node = (struct node*) malloc (sizeof(struct node)) ;
    new_node->item = item ;
    new_node->prev = 0;
    new_node->next = 0;

    //step-2: update the prev and next pointers of the new node
    new_node->prev = 0 ; //no previous node as this is the first item
    new_node->next = head ;

    // step-3: update linked list pointer variables: list and tail
    head = new_node ;

    // step-4: update the pointer variables of the nodes that
    //might be affected due to the insertion
    if ( new_node->next != 0 )
        new_node->next->prev = new_node ;
    else
        tail = new_node ; //this is the first node in the list

    return SUCCESS_VALUE ;
}

int insert_last(int item)
{
    //step-1: create a new node
    struct node *new_node ;
    new_node = (struct node*) malloc (sizeof(struct node)) ;
    new_node->item = item ;
    new_node->prev = 0;
    new_node->next = 0;

    //step-2: update the prev and next pointers of the new node
    new_node->prev = tail ;
    new_node->next = 0 ; //no next node as this is the last node

    // step-3: update linked list pointer variables: list and tail
    tail = new_node ;

    // step-4: update the pointer variables of the nodes that
    //might be affected due to the insertion
    if ( new_node->prev != 0 )
        new_node->prev->next = new_node ;
    else
        head = new_node ; //this is the first node in the list

    return SUCCESS_VALUE ;
}

int insert_after(int old_item, int new_item)
{
    /*
    This function inserts the new_item after the first occurrence of the
    old item and returns success_value. However, if the old_item is not
    present in the linked list it returns null_value
    */
    return NULL_VALUE;
}
int  delete_first()
{
    /*This function deletes the first item of the list and
    returns the deleted item*/

    struct node *temp;

    if (head== NULL)
    {
        printf("list empty");
    }

    else if( head -> next == NULL)
    {
        head  == NULL;
        free (head);
        printf("Node delted");
    }
    else
    {
        temp = head;
        head = head ->next;
        head ->prev = NULL;
        free(temp);
        printf("node deleted");
    }
    return NULL_VALUE;
}

int  delete_last()
{
    /*This function deletes the last item of the list and
     returns the deleted item*/


    struct node *temp, *temp1, *temp2;
    temp =  head;
    if(temp == NULL)
    {
        printf("List Empty");
    }
    else if(temp ->next == NULL)
    {
        temp = NULL;
        free(temp);
        printf("node deleted");
    }
    else
    {
        /*temp =  head ;
        if(temp -> next != NULL){

          temp = temp ->next;
        }
        temp ->prev ->next =NULL;
        free(temp);
        printf("delete");
        */
        temp = tail ;
        temp1 = tail ->prev;
        temp1 ->next = NULL;
        tail = temp1;
        free(temp);
        printf("delete node ");

    }
    return NULL_VALUE;
}


int delete_first_occurrence(int item)
{
    /*This function deletes the first occurrence of parameter item from
    the list and returns success_value. However, if the item is not
    present in the linked list it returns null_value*/
    return NULL_VALUE;
}

void print_forward()
{
    /*This function prints the linked list forward*/
    struct node* tem = head;
    while(tem != 0)
    {
        printf("%d ", tem->item);
        tem = tem->next;
    }
    printf("\n");
}


int main()
{
    /*Implement the main function in a way that it works as a driver function,
    i.e. all the fuctions can be called based on different input value of ch.
    A sample has been provided for you where the program continuously asks for an input
    ch and based on that ch some operation on the linked list is performed.
    Now complete the function so that it can deal with all the functions of the linked list.
    */
    initialize_list();
    while(1)
    {
        printf("\n1. Insert new item. \n2. Print Linked List Forward\n3.Delete first node\n4. delete last node\n");
        int ch;
        scanf("%d",&ch);
        if(ch == 1)
        {
            int item;
            scanf("%d", &item);
            insert_first(item);
        }
        if(ch == 2)
        {
            print_forward();
        }

        if(ch == 3)
        {

            delete_first();
        }
        if(ch == 4)
        {
           delete_last();
        }
    }
}

