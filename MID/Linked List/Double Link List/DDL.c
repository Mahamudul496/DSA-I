//Mahmudul hasan 0112310496
#include<stdio.h>
#include<stdlib.h>
struct node{
	int value;
	struct node *next;
	struct node *prev;
};
struct node *head, *tail;

void ftraversal()
{
    struct node * t = head;
        if(head==NULL)
        {
            printf("\nList empty");
            return;
        }
        while(t!=NULL)
        {
            printf("%d -> ", t->value);
            t=t->next;
        }
}

void btraversal()
{
    struct node * temp = head;
      if(temp == NULL)
      {
          printf("Empty List");
          return;
      }

    while (temp->next != NULL)
    {
        temp = temp->next;
    }
    while (temp != NULL)
    {
        printf("%d -> ", temp->value);
        temp = temp->prev;
    }
}



int insertFirst(int val) {
    struct node *newNode = (struct node *)malloc(sizeof(struct node));
    newNode->value = val;
    newNode->prev = NULL;
    newNode->next = head;

    if (head != NULL) {
        head->prev = newNode;
    }

    head = newNode;
    printf("Inserted %d at the beginning.\n", val);
    return 1;
}

int insertLast(int val)
{
    struct node *newItem;
    newItem = (struct node*)malloc(sizeof(struct node));
    if(newItem == NULL)
    {
        printf("Memory is not allocated/n ");
        return 0;
    }

    newItem->value = val;
    newItem->next = NULL;
    newItem->prev = NULL;
    struct node *temp = head;

    if(temp == NULL)
    {
        temp = newItem;
    }
    else{

         while(temp->next != NULL)
      {
        temp = temp->next;
      }

    temp->next = newItem;
    newItem->prev = temp;
    printf("Value %d Inserted at the end..",val);
    return 1;

    }

}

void insertAfterValue(val, after_val)
{
    struct node *newItem;
    newItem = (struct node*)malloc(sizeof(struct node));

    newItem->value = val;
    newItem->next = NULL;
    newItem->prev = NULL;

    struct node *temp;
    temp = head;

    while(temp->value != after_val)
    {
        temp = temp->next;
    }

    newItem->next = temp->next;
    temp->next = newItem;


}


 void insertAtPosition(int val, int pos)
 {
     struct node *newItem;
    newItem = (struct node*)malloc(sizeof(struct node));

    newItem->value = val;
    newItem->next = NULL;
    newItem->prev = NULL;

    struct node *temp = head;
    for(int i=1; i<pos; i++)
    {
        temp = temp->next;

    }

    newItem->next = temp->next;
    temp->next = newItem;

 }

 int deleteVal(int val)
 {
     struct node *temp1 = head;
     struct node *temp2 = NULL;
     while(temp1->value != val)

     {
         temp2 = temp1;
         temp1 = temp1->next;
         if(temp1->value == val)
         {
              temp2->next = temp1->next;
              temp1->next->prev = temp2;
              free(temp1);
               printf("Value %d delete from the list.",val);
               return;
         }
         temp1 = temp1->next;
         if(temp1 == NULL)
         {
             printf("This value is not in this list");
             return;
         }
     }




 }

 void searchVal(int val)
 {
     struct node *temp = head;
     int pos = 1;


     while(temp->value != NULL)
     {


        if(temp->value == val)
         {
             printf("The value %d found at %d position.",val,pos);
             return;
         }

         temp = temp->next;
         pos++;

       if(temp->next == NULL)
        {
            printf("Value not found in this list\n\n");
            return;
       }

     }
 }


  void swap()
  {

      if(head == NULL || head->next == NULL)
      {
          printf("No elements found!!");
          return;
      }

      struct node *first = head;
      struct node *last = head;


      while (last->next != NULL)
      {
          last = last->next;
      }

      int temp;
      temp = last->value;
      last->value = first->value;
      first->value = temp;
      printf("Swap the first in Last is COmplete!!");
      return;
  }


int main()
{
    head=NULL;
    tail=NULL;
    int choice,val,after_val,pos;

    printf("Mahmudul Hasan 0112310496\n");
while(1)
{
    printf("\n1. F Traversal \n2. B Traversal \n3. Insert First \n4. Insert Last \n5. Insert After a val \n6. Insert at a middle pos \n7. Delete\n8. Search\n9. SwapFirstLast!  \n10.EXIT\nEnter choice: ");
    scanf("%d", &choice);

    if(choice==1)
    {
        ftraversal();
    }
    else if(choice==2)
    {
         btraversal();
    }
    else if(choice==3)
    {
        printf("Enter Val: ");
        scanf("%d",&val);
        insertFirst(val);


    }
    else if(choice==4)
    {
        printf("Enter Val: ");
        scanf("%d",&val);
        insertLast(val);


    }
    else if(choice==5)
    {

            printf("\nEnter val to insert: ");
            scanf("%d", &val);
            printf("\nEnter Value to insert after: ");
            scanf("%d", &after_val);
            insertAfterValue(val, after_val);
    }
    else if(choice==6)
    {

         printf("\nEnter val to insert: ");
            scanf("%d", &val);
            printf("\nEnter Value to insert at a Position: ");
            scanf("%d", &pos);
            insertAtPosition(val, pos);
    }
    else if(choice==7)
    {

            printf("\nEnter val to delete: ");
            scanf("%d", &val);
            deleteVal(val);
    }
    else if(choice==8)
    {

         printf("\nEnter val to Search: ");
            scanf("%d", &val);
            searchVal(val);
    }
    else if(choice==9)
    {

         swap();
    }

    else if(choice==10)
        break;

    else
    {
        printf("Wrong choice, enter again");
    }

}

}
