#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <netdb.h>
#include <string.h>

int main()
{
    baixaArquivo("localhost", 8000, "testeEnvio");
}
int baixaArquivo(char shost[64], int porta, char url[128])
{
    char req[512];
    int sock;
    struct sockaddr_in addr;
    struct hostent  * host = NULL;
    
    //port
    //int porta=8000;
    
    //host
    //char shost[64];
    //sprintf(shost,"localhost");

    // Cria socket para conectar ao servidor http
    if((sock = socket(AF_INET,SOCK_STREAM,0))<0)
        return 1;
    addr.sin_family=AF_INET;
    addr.sin_port = htons(porta);//seta porta
    host = gethostbyname(shost);//sera host

    if(host == NULL) //se host não responde, cai fora
        return 1;

    //ajusta ip do host
    memcpy(&addr.sin_addr,host->h_addr_list[0],host->h_length);

    //conecta
    if(connect(sock,(struct sockaddr*)&addr,sizeof(addr))<0)
        return 1;

    // Requisição
    sprintf(req,"GET /%s HTTP/1.1\r\n\r\n",url);//monta requisição com a url
    
    send(sock,req,strlen(req),0); // Envia requisição

    char buffer[512]; // Buffer para armazenar dados

    int bytes = 1; // Bytes recebidos
    while(bytes > 0) // Enquanto estiver recebendo
    {
        memset(buffer,0,512); // Limpa o buffer
        bytes = recv(sock,buffer,512,0); // Recebe dados
        printf("%s",buffer); // Mostra-os
    }

    close(sock); // Fecha socket
    
    return 0;
}
