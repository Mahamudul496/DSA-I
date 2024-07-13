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