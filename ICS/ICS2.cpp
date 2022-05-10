#include<bits/stdc++.h>
using namespace std;

int* ip(int ptext[] , int initp[])
{
	for(int i=0;i<8;i++)
	{
		ptext[i] = ptext[initp[i]-1];
	}
	
	return ptext;
}


int main()
{
	
	int ptext[8];
	int temp[8];
	
	cout<<"\n\n\tEnter 8 bit plain text (space seperated) : ";
	for(int i=0;i<8;i++)
	{
		cin>>ptext[i];
		temp[i] = ptext[i];
	}
	
	int initp[8] = {2,6,3,1,4,8,5,7};
	
	temp = ip(temp , initp);
	
	for(int i=0;i<8;i++)
	{
		cout<<temp[i]<<" ";
	}
	
	return 0;
}
