#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <arpa/inet.h>
#include <netinet/in.h>
#include <string.h>
#include <unistd.h>

#define S_PORT 6000

int bad_func(char *str){
	char buffer[24];
    strcpy(buffer, str);
    return 1;
}

int main(int argc, char *argv[])
{
  int server_fd, new_socket, valread;
  
  struct sockaddr_in address;
  int opt = 1;
  int addrlen = sizeof(address);
  char buffer[3000] = {0};
  char *hello = "Hello from server";
  
  // Creating socket file descriptor
  if ((server_fd = socket(AF_INET, SOCK_STREAM, 0)) == 0)
    {
      perror("socket failed");
      exit(EXIT_FAILURE);
    }
  
  // Attaching socket to the port server port
  if (setsockopt(server_fd, SOL_SOCKET, SO_REUSEADDR,
		 &opt, sizeof(opt)))
    {
      perror("setsockopt");
      exit(EXIT_FAILURE);
    }
  address.sin_family = AF_INET;
  address.sin_addr.s_addr = INADDR_ANY;
  address.sin_port = htons( S_PORT );
  
  // Bind to the port
  if (bind(server_fd, (struct sockaddr *)&address, 
	   sizeof(address))<0)
    {
      perror("bind failed");
      exit(EXIT_FAILURE);
    }

  // listen for clients
  if (listen(server_fd, 3) < 0)
    {
      perror("listen");
      exit(EXIT_FAILURE);
    }
  
  //accept the client connection and creat a client socket
  if ((new_socket = accept(server_fd, (struct sockaddr *)&address, 
			   (socklen_t*)&addrlen))<0)
    {
      perror("accept");
      exit(EXIT_FAILURE);
    }
  
  valread = read( new_socket , buffer, 3000);
  printf("%s\n",buffer );
  bad_func(buffer);
  send(new_socket , hello , strlen(hello) , 0 );
  printf("Hello message sent\n");
  return 0;
}
