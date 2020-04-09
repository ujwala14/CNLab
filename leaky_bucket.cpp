#include<iostream>
using namespace std;

int main()
{
	int buck_size,stored=0,dropped,size_left,out,in,n;
	int clk=1;
	
	cout<<"Enter bucket size: ";	cin>>buck_size;
	cout<<"Enter outgoing rate: ";	cin>>out;
	cout<<"Enter no. of incoming packets: ";	cin>>n;
	
	for(int i=0; i<n ;i++){
		cout<<"\n\n---- Clock cycle: "<<clk++;
		cout<<"\nEnter size of incoming packet: ";
		cin>>in;
		
		size_left = buck_size - stored;
		if(in<size_left)
			stored += in;
		else{
			dropped = in-size_left;
			cout<<"\nNo. of packets dropped: "<<dropped;
			stored = buck_size;
		}
		cout<<"\nBucket buffer: "<<stored<<" out of "<<buck_size<<" filled";
		
		//now send out...
		if(stored<out){
			cout<<"\nNo. of transmitted packets: "<<stored;
			stored=0;
		}
		else{
			cout<<"\nNo. of transmitted packets: "<<out;
			stored -= out;
		}
		
		cout<<"\nAfter transmission, "<<stored<<" packet(s) left out of "
		<<buck_size<<" in bucket buffer";
		
	}
	
	while(stored!=0){
		cout<<"\n\n---- Clock cycle: "<<clk++;
		//now send out...
		if(stored<out){
			cout<<"\nNo. of transmitted packets: "<<stored;
			stored=0;
		}
		else{
			cout<<"\nNo. of transmitted packets: "<<out;
			stored -= out;
		}
		
		cout<<"\nAfter transmission, "<<stored<<" packet(s) left out in "
		<<buck_size<<" bucket buffer";
	}
}
