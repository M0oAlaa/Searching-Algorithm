/*******************************************************************/
/******************** Date: 26/12/2021 *****************************/
/******************** Project: Searching Algorithm *****************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/

#include<stdio.h>
#include<stdint.h>

uint8_t binarySearch(uint32_t* u8_arr,uint8_t u8_size,uint8_t u8_number);//Declaration of binary searching algorithm

void main(void)
{
	uint32_t u8_arr[]={2,5,6,3,8,10,1};// the main array that holds elements "{1,2,3,5,6,8,10}"
	uint8_t u8_i,u8_j,u8_flag;//for loop iterations
	uint8_t u8_temp,u8_size,u8_index;
	uint8_t u8_number=10;// selecting element we want to search about
	
	u8_size=sizeof(u8_arr)/sizeof(uint32_t);// calculating size of the array
	/*Check the array elements is sorted or not*/
	for(u8_i=0;u8_i<(u8_size-1);u8_i++)
	{
		/*If sorted -> flag=1*/
		if(u8_arr[u8_i]<u8_arr[u8_i+1])
		{
			u8_flag=1;
		}
		/*If not sorted -> flag=0 and break the loop*/
		else
		{
			u8_flag=0;break;
		}
		
	}
	/*if not sorted we need to sort first*/
	if(u8_flag==0)
	{
		/*Compare each element by its side if > or <*/
		for(u8_i=0;u8_i<(u8_size-1);u8_i++)
		{
			for(u8_j=0;u8_j<((u8_size-1)-u8_i);u8_j++)
			{
				if(u8_arr[u8_j]>u8_arr[u8_j+1])
				{
					/*if > : swap*/
					u8_temp=u8_arr[u8_j];
					u8_arr[u8_j]=u8_arr[u8_j+1];
					u8_arr[u8_j+1]=u8_temp;
				}
				else{}
			}
		}
	}
	/*if sorted, continue to searching*/
	else{}
	u8_index=binarySearch(u8_arr,u8_size,u8_number);//call searching function and keep its return in char index
	/*check if the return index == -1 or >*/
	if(u8_index==255)//if ==-1 that means the number is not between the elements
	{
		printf("This number is not one of these elements");
	}
	else
	{
		printf("The number's place is %d",u8_index);
	}
}

/*Implementation of Searching function*/
uint8_t binarySearch(uint32_t* u8_arr,uint8_t u8_size,uint8_t u8_number)
{
	uint8_t u8_start=0,u8_index;
	uint8_t u8_end=u8_size-1;
	uint8_t u8_center;
	/*check if the elemnt between array elements or not*/
	if(u8_number<=255)
	{
		/*make sure that start <= end*/
		while(u8_start<=u8_end)
		{
			u8_center=(u8_start+u8_end)/2;
			if(u8_number>u8_arr[u8_center])
			{
				u8_start=u8_center+1;
			}
			else if(u8_number<u8_arr[u8_center])
			{
				u8_end=u8_center-1;
			}
			else if(u8_number==u8_arr[u8_center])
			{
				u8_index=u8_center;
				break;
			}
		}
		if(u8_number!=u8_arr[u8_center])
		{
			u8_index=-1;
		}
	}
	else{u8_index=-1;}
	return u8_index;
}