#include<iostream>
using namespace std;
void divi(int temp[], int gen[],int n,int r)
{
	for(int i=0; i<n; i++)	//how many times div should take place
		if(gen[0] == temp[i])
			for(int j=0,k=i; j<r+1; j++,k++)	//to iterate through gen and do XOR
				temp[k] = temp[k]^gen[j];
}
int main()
{
	int msg[50],temp[50],n,r=16;
	int gen[]={1,0,0,0,1,0,0,0,0,0,0,1,0,0,0,0,1};
	
	cout<<"***Sender***";
	cout<<"\nEnter no. of bits in message: ";
	cin>>n;
	cout<<"\nEnter the msg: ";
	for(int i=0;i<n;i++)
	{
		cin>>msg[i];
		temp[i]=msg[i];
	}
	
	//appending 16 0s
	for(int i=0;i<r;i++)
	{
		temp[n+i]=msg[n+i]=0;
	}
	
	//crc 16 gen
	cout<<"\nCRC 16 generator: ";
	for(int i=0; i<r+1; i++)
		cout<<gen[i]<<" ";
		
	//division
	divi(temp,gen,n,r);
	
	//display and append rem to msg
	cout<<"\nCRC remainder: ";
	for(int i=0; i<r; i++){
		cout<<temp[n+i]<<" ";
		msg[n+i] = temp[n+i];
	}
	
	cout<<"\nTransmitted message: ";
	for(int i=0; i<n+r; i++)
		cout<<msg[i]<<" ";
		
		
	cout<<"\n\n***Receiver***";
	cout<<"\nEnter received message: ";
	for(int i=0; i<n+r; i++){
		cin>>msg[i];
		temp[i] = msg[i];
	}
	
	//div
	divi(temp,gen,n,r);
	
	//check rem - if 0 accept
	for(int i=0; i<r; i++){
		if(temp[n+i]){
			cout<<"\nError in transmission!!Sorry!";
			return 0;
		}
	}
	
	cout<<"\nNo error in transmission!Yay!!";
	cout<<"\nThe msg: ";
	for(int i=0; i<n; i++)
		cout<<msg[i]<<" ";
		
}
