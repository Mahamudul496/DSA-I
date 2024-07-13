#include<stdio.h>
#include<stdlib.h>

 struct node{

    int value;
    struct node *next;
    struct node *prev;
 };

 struct node *head,*tail;

  void insert(int val)
  {
      struct node *newItem;
      newItem = (struct node *)malloc(sizeof(struct node));

      newItem->value = val;
      newItem->prev = NULL;
      newItem->next = head;
      if(head == NULL)
      {
          head = newItem;
      }
      if(head != NULL)
      {
          head->prev = newItem;

      }
      head = newItem;
      printf("val %d Insert Successfully\n\n",val);
      return 1;
  }

  void print()
  {
      struct node *temp = head;
      if(temp == NULL)
      {
          printf("List is Empty");
          return;
      }

      while(temp != NULL)
      {
          printf("%d -> ",temp->value);
          temp = temp->next;
      }
  }

  void reverse()
  {
      struct node *temp = head;

      while(temp->next != NULL)
      {
          temp = temp->next;
      }
      while(temp != NULL)
      {
          printf("%d -> ",temp->value);
          temp = temp->prev;
      }
  }

  void swap()
  {
      struct node *first = head;
      struct node *last = head;

      while(last->next != NULL)
      {
          last = last->next;
      }
      int temp = first->value;
      first->value = last->value;
      last->value = temp;
      printf("Swap Successful");
      return;
  }

  void deleteMiddle()
  {
      int firstPos = 0;
      int lastPos = 0;
      int mid = 0;
      struct node *temp = head;
      struct node *temp1 = head;
      struct node *temp2 = NULL;

      while(temp->next != NULL)
      {
          temp = temp->next;
          lastPos++;
      }

      mid = (firstPos + lastPos)/2;

      for(int i=0; i<mid; i++)
      {
          temp2 = temp1;
          temp1 = temp1->next;
      }

      temp2->next = temp1->next;
      temp1->next->prev = temp2;
      printf("Val %d delete from the middle",temp1->value);
      free(temp1);

  }


 int main()
 {
     head = NULL;
     tail = NULL;
     int choice,val;

     while(1)
     {
         printf("\n1.Insert\n2.Delete\n3.Print\n4.Reverse\n5.Delete middle element\n6.SwapFirstLast\n7.Exit\n");
         printf("Enter your Choice: ");
         scanf("%d",&choice);

         if(choice == 1)
         {
             printf("Enter val: ");
             scanf("%d",&val);
             insert(val);
         }
         else if(choice == 2)
         {

         }
         else if(choice == 3)
         {
             print();
         }
         else if(choice == 4)
         {
             reverse();

         }
         else if(choice == 5)
         {

         deleteMiddle();
         }
         else if(choice == 6)
         {
             swap();
         }
         else if(choice == 7)
         {
             break;
         }
         else
            printf("Wrong choice!!");

     }

     return 0;

 }
