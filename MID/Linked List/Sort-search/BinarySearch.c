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