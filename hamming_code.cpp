#include<iostream>
using namespace std;

int main(){
	int d[10],p[5];
	
	cout<<"***SENDER***";
	cout<<"\nEnter 4 bit data: ";
	cin>>d[0]>>d[1]>>d[2]>>d[4];
	
	//calc rem.
	d[3] = d[0]^d[1]^d[2];
	d[5] = d[0]^d[1]^d[4];
	d[6] = d[0]^d[2]^d[4];
	
	cout<<"\nTranmitted msg: ";
	for(int i=0; i<7; i++)
		cout<<d[i]<<" ";
		
	cout<<"\n\n***RECEIVER***";
	cout<<"\nEnter received msg (7 bit): ";
	for(int i=0; i<7 ; i++)
		cin>>d[i];
		
	//calc position bits - error check
	p[2] = d[3]^d[0]^d[1]^d[2];
	p[1] = d[5]^d[0]^d[1]^d[4];
	p[0] = d[6]^d[0]^d[2]^d[4];
	
	//calc pos
	int pno = 4*p[2] + 2*p[1] + p[0];
	
	//check if error? pos=0 or not
	if(pno == 0)
		cout<<"\nNo error in transmission";
	else
	{
		cout<<"\nError at position "<<pno <<" from the right (or position "
		<<7-pno+1<<" from the left)";
		pno=7-pno;
		d[pno] = !d[pno];
		cout<<"\nMessage corrected!";
	}
	cout<<"\nThe message: "<<d[0]<<" "<<d[1]<<" "<<d[2]<<" "<<d[4];	
}
