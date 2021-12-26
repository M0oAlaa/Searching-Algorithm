/*******************************************************************/
/******************** Date: 26/12/2021 *****************************/
/******************** Project: Searching Algorithm *****************/
/******************** Author: Mohamed Alaa *************************/
/******************** Version: 1.0 *********************************/
/*******************************************************************/

#include<stdio.h>
#include<stdint.h>

uint8_t binarySearch(uint8_t* arr,uint8_t u8_size,uint8_t u8_number);

void main(void)
{
	uint8_t arr[]={2,5,6,3,8,10,1};
	uint8_t u8_i,u8_j,u8_temp,u8_size,u8_index,u8_number=2;
	
	u8_size=sizeof(arr);
	
	for(u8_i=0;u8_i<(u8_size-1);u8_i++)
	{
		for(u8_j=0;u8_j<((u8_size-1)-u8_i);u8_j++)
		{
			if(arr[u8_j]>arr[u8_j+1])
			{
				u8_temp=arr[u8_j];
				arr[u8_j]=arr[u8_j+1];
				arr[u8_j+1]=u8_temp;
			}
		}
	}
	u8_index=binarySearch(arr,u8_size,u8_number);
	if(u8_index==255)
	{
		printf("This number is not one of these elements");
	}
	else
	{
		printf("The number's place is %d",u8_index);
	}
}

uint8_t binarySearch(uint8_t* arr,uint8_t u8_size,uint8_t u8_number)
{
	uint8_t u8_start=0,u8_index;
	uint8_t u8_end=u8_size-1;
	uint8_t u8_center;
	if(u8_number<=255)
	{
		while(u8_start<=u8_end)
		{
			u8_center=(u8_start+u8_end)/2;
			if(u8_number>arr[u8_center])
			{
				u8_start=u8_center+1;
				u8_center=(u8_start+u8_end)/2;
			}
			else if(u8_number<arr[u8_center])
			{
				u8_end=u8_center-1;
				u8_center=(u8_start+u8_end)/2;
			}
			else if(u8_number==arr[u8_center])
			{
				u8_index=u8_center;
				break;
			}
		}
		if(u8_number!=arr[u8_center])
		{
			u8_index=-1;
		}
	}
	else{u8_index=-1;}
	return u8_index;
}