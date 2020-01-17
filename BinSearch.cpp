#include<iostream>
#include<algorithm>
using namespace std;

bool binarySearchRecursive(int* array, int startIndex, int lastIndex, int element)
{
  int mid =(startIndex+lastIndex)/2;
  if( element == array[mid] )
  {
  	return true;
  }
  else
  {
  	if( element > array[mid] )
		return binarySearchRecursive( array, mid+1, lastIndex, element);
	
	else
		return binarySearchRecursive( array, startIndex, mid-1, element);
  }
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{
  int size = sizeof(array)/sizeof(array[0]);
  int mid = (startIndex+lastIndex)/2;
  for( int i=0; i<size; i++)
  {
  	mid = (startIndex+lastIndex)/2;
	if(element == array[mid])
  	return true;
  	
	else if(element > array[mid])
	startIndex = mid + 1;
	
	else
	lastIndex = mid - 1;
  }
  return false;
}

int main()
{
	int size,choice,element;
	char ans;
	cout<<"\nEnter size of array";
	cin>>size;
	int *arr=new int[size];
	cout<<"\nEnter array elements: ";
	for( int i=0; i<size; i++)
	cin>>arr[i];
	sort(arr,arr+size);
	cout<<"\nEnter element to be searched";
	cin>>element;
	do
	{
		cout<<"\n\t1.Binary search via Iteration";
		cout<<"\n\t2.Binary search via Recursion";
		cout<<"\nEnter your choice(1-2)";
		cin>>choice;
		if(choice==1)
		{
			if(binarySearchIterative( arr, 0, size-1, element))
			{
				cout<<"\nElement found in array";
			}
			else
			{
				cout<<"\nElement NOT found in array";
			}
		}
		else if(choice==2)
		{
			binarySearchRecursive( arr, 0, size-1, element);
		}
		else
		{
			cout<<"\nINVALID CHOICE";
		}
		cout<<"\nDo you wish to continue?(y/n)";
		cin>>ans;
	}while(ans=='y');
  return 0;
}
