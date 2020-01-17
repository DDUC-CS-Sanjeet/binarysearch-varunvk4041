#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchRecursive(int* array, int startIndex, int lastIndex, int element)
{
  int mid =(startIndex+lastIndex)/2;
  if( startIndex <= lastIndex )
  {
		if( element == array[mid] )
	{
		return false;		// false if element found as we can't alter last statement in layout
	}
	else
	{
		if( element > array[mid] )
			return binarySearchRecursive( array, mid+1, lastIndex, element);
		
		else
			return binarySearchRecursive( array, startIndex, mid-1, element);
	}
  }
  else
  return true;
}


bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
  int mid = (startIndex+lastIndex)/2;
  while( startIndex <= lastIndex )
  {
  	mid = (startIndex+lastIndex)/2;
	if(element == array[mid])			// false if element found as we can't alter last statement in layout
  	return false;
  	
	else if(element > array[mid])
	startIndex = mid + 1;
	
	else
	lastIndex = mid - 1;
  }
  return true;
}

int main()
{
	int size,choice,element;
	char ans;
	do
	{
		cout<<"\nEnter size of array: ";
		cin>>size;
		int *arr=new int[size];
		cout<<"\nEnter array elements: ";
		for( int i=0; i<size; i++)
		cin>>arr[i];
		sort(arr,arr+size);
		cout<<"\nEnter element to be searched: ";
		cin>>element;
		cout<<"\n\t1.Binary search via Iteration: ";
		cout<<"\n\t2.Binary search via Recursion:";
		cout<<"\n\nEnter your choice(1-2): ";
		cin>>choice;
		if(choice==1)
		{
			if(!binarySearchIterative( arr, 0, size-1, element))
			cout<<"\nElement found in array: ";
			
			else
			cout<<"\nElement NOT found in array: ";
		}
		else if(choice==2)
		{
			if(!binarySearchRecursive( arr, 0, size-1, element))
			cout<<"\nElement found in array: ";
			
			else
			cout<<"\nElement NOT found in array: ";
		}
		else
		{
			cout<<"\nINVALID CHOICE: ";
		}
		cout<<"\n\nDo you wish to continue?(y/n): ";
		cin>>ans;
		if(ans=='n')
		cout<<"\n\nPROGRAM ENDED";
	}while(ans=='y');
  return 0;
}
