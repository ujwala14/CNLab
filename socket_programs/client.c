#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/socket.h>
#include<sys/stat.h>
#include<sys/types.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(int argc, char ** argv){
	int sockfd,n;
	struct sockaddr_in serv_addr;
	char b1[4096],b2[4096];

	sockfd = socket(AF_INET,SOCK_STREAM,0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5035);
	serv_addr.sin_addr.s_addr = inet_addr("10.0.2.15");

	printf("\nReady to send...");
	connect(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));

	printf("\nEnter filename: ");
	scanf("%s",b1);
	
	printf("\nRequested file : %s.",b1);
	write(sockfd,b1,4096);

	n=read(sockfd,b2,4096);
	printf("\nServer's response:\n%s\n",b2);

	close(sockfd);
}
	


