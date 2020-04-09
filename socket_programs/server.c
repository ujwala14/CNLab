#include<stdio.h>
#include<netinet/in.h>
#include<netdb.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/socket.h>
#include<fcntl.h>
#include<unistd.h>
#include<arpa/inet.h>

int main(int argc, char ** argv){
	int sockfd,newsockfd,fd,n,m,clen;
	struct sockaddr_in serv_addr,cli_addr;
	char b1[4096],b2[4096];

	sockfd = socket(AF_INET, SOCK_STREAM,0);
	serv_addr.sin_family = AF_INET;
	serv_addr.sin_port = htons(5035);
	serv_addr.sin_addr.s_addr = INADDR_ANY;
	printf("\nStart");

	bind(sockfd, (struct sockaddr*)&serv_addr, sizeof(serv_addr));
	printf("\nListening");

	listen(sockfd,5);
	clen = sizeof(cli_addr);
	newsockfd = accept(sockfd, (struct sockaddr*)&cli_addr, &clen);
	printf("\nAccepted");

	n = read(newsockfd, b1, 4096);
	fd = open(b1,O_RDWR);
	m = read(fd, b2, 4096);
	write(newsockfd, b2, 4096);

	printf("\nClient's request: %s:\n%s\n",b1,b2);

	close(newsockfd);
	close(sockfd);

}
