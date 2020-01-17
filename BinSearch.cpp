#include<algorithm>
#include<iostream>
using namespace std;

bool binarySearchReacursive(int* array, int startIndex, int lastIndex, int element)
{
	
	int flag=1,middle;
	middle=(startIndex+lastIndex)/2;
	if(startIndex<=lastIndex)
	{
		if(array[middle]==element)
	{
		flag++;	
	}
	else if(array[middle]>element)
	{
		return binarySearchReacursive(array,startIndex,middle-1,element);
	}
	else
	{
		return binarySearchReacursive(array,middle+1,lastIndex,element);
	}
	 
	}
	 //checking the flag
	 
	  if(flag==1)
  	   {
  	   		cout<<element<<" is not present in the array!!";
   			
   	   } 
      else
       {
   			cout<<"\nUsing recursion "<<element<<" is found at index "<<middle;
       } 
	 
  return true;
}

bool binarySearchIterative(int* array, int startIndex, int lastIndex, int element)
{	

   
   int flag=0,middle;
   while(startIndex<=lastIndex)
   {
   	if(array[middle]==element)
   	{
   		flag++;
   		break;
	   }
	else if(array[middle]<element)
	{
		startIndex=middle+1;
		
	 } 
	 else
	 {
	 	lastIndex=middle-1;
	 }
	  middle=(startIndex+lastIndex)/2;
   }
   //testing thes flag
   if(flag==1)
   {
   	cout<<"\nUsing iteration "<<element<<" is found at index "<<middle;
   }
   else
   {
   	cout<<element<<" is not present in the array!!";
   }
   return true;
}

int main()
{
	int num,numdesired;
	cout<<"Enter the size of array: ";
	cin>>num;
	int *arr;
	arr=new int[num];

	
	int first=0;
	int last=num-1;
	cout<<"\nEnter the elements of the array: ";
	
	for(int i=0;i<num;i++)
	{
		cin>>arr[i];
	}
	//using inbuilt sorting function
	sort(arr,arr+num);
	
	cout<<"\nArray after sorting in increasing order:\n";
	for(int i=0;i<num;i++)
	{
		cout<<arr[i]<<" ";
	}

  	cout<<"\nEnter the elements you want to search: ";
  	cin>>numdesired;
  	//calling the iterative function
    binarySearchIterative(arr,first,last,numdesired);
  	//calling the reacursive function
    binarySearchReacursive(arr,first,last,numdesired);
	
  return 0;
}
