#include<stdio.h>

 void insertion_sort(int arr[],int n)
  {
      int i,j,temp;

      for(i=1; i<n; i++)
      {
          temp = arr[i];
          j = i-1;

          while(j >= 0 && arr[j] > temp)
          {
              arr[j+1] = arr[j];
              j--;
          }
          arr[j+1] = temp;

      }
      printf("Insertion Complete!!\n\n");

  }

  void bubbleSort(int arr[],int n)
  {
      int flag;
      for(int i=0; i<n-1; i++)
      {
           flag = 0;
          for(int j=0; j<n-1-i; j++)
          {
              if(arr[j] > arr[j+1])
              {
                  int temp = arr[j];
                  arr[j] = arr[j+1];
                  arr[j+1] = temp;

                  flag = 1;
              }
              if(flag == 0)
              {
                  break;
              }
          }
      }
  }

  void linearSearch(int arr[],int n, int key)
  {
      int flag = 0;
      for(int i=0; i<n; i++)
      {
          if(arr[i] == key)
          {
              printf("The element %d in %d index\n\n",arr[i],i);
              flag++;
          }
      }
      if(flag == 0)
      {
          printf("The elements not in that array\n");
      }

  }

  int binarySearch(int arr[],int n, int key)
  {
      int l,r,mid,flag=0;
      l=0;
      r=n-1;


      while(l<=r)
      {
          mid = (l+r)/2;

          if(key == arr[mid])
          {
              return mid;
          }
          else if(key > arr[mid])
          {
              l = mid+1;
          }
          else if(key < arr[mid])
          {
              r = mid-1;
          }
          else
          {
              printf("The element not in that Array");
          }
      }


  }

  void printArray(int arr[],int n)
  {

      for(int i=0; i<n; i++)
      {
          printf("%d ",arr[i]);
      }
  }




int main()
{
    int n,choice,key;

    printf("Enter the Array length: ");
    scanf("%d",&n);
    int arr[n];

    printf("Enter Array elements:\n");
    for(int i=0; i<n; i++)
    {
        printf("Array[%d]: ",i);
        scanf("%d", &arr[i]);
    }


    while(1){
        printf("\n\nMenu:\n");
        printf("1.Insertion Sort \n2.Counting Sort \n3.Bubble Sort \n4.Linear Search \n5.Binary Search \n6.Print All \n7.Exit");
        printf("\n\nEnter Your Choice: ");
        scanf("%d",&choice);

        if(choice == 1)
        {
            insertion_sort(arr,n);
            printf("After Insertion Sort:\n");
            printArray(arr,n);

        }

        else if(choice == 3)
        {
            bubbleSort(arr,n);
            printf("After Bubble Sort:\n");
            printArray(arr,n);
        }

        else if(choice == 4)
        {
            printf("Search element:");
            scanf("%d",&key);
            linearSearch(arr,n,key);
        }

        else if(choice == 5)
        {
            printf("Search element:");
            scanf("%d",&key);
            int result = binarySearch(arr,n,key);
            if(result == -1)
            {
                printf("The element not found in that array");
            }
            else
            {
                 printf("The element %d in %d index\n\n",arr[result],result);
            }
        }


        else if(choice == 7)
        {
            break;
        }

    }
}

