/* 
 * File:   comandos.h
 * Author: Rodrigo
 *
 * Created on 28 de Novembro de 2013, 23:31
 */

#ifndef COMANDOS_H
#define	COMANDOS_H

#ifdef	__cplusplus
extern "C" {
#endif

#ifdef	__cplusplus
}
#endif

#endif	/* COMANDOS_H */

#define MAX 50

typedef struct{
    int    id;          // 1, 2, 3...
    char name[50];      // "nome do arquivo.txt"
    char size[10];      // "100", "15487"... (KB)
    char http[100];     // Endereco gerado para disponibilizacao do arquivo
    char md5[50];       // Assinatura do arquivo para validacao
} archive_def;

typedef struct proto{
    char protocol[5];   // Nome do protocolo
    char command[20];   // Identificacao do comando
    int  status;        // Codigo de erro ou validacao
    char passport[30];  // Chave de autenticacao
    char back[200];     // Dado retornado
    archive_def file;   // Informacoes sobre arquivo
    char sender[20];    // IP Remetente
    char recipient[20]; // IP Destinatario
    int  ok;            // Construcao correta do protocolo
} protocolo;

typedef struct ips{
    char ip[MAX][20];
    int size;
} ips_list;

void * cliente();

int porta(char * ip_destino);

int servidor();

void * start_connection(void *porta);

char * ping(char * meu_ip, char * seu_ip);

char * pong(char * meu_ip, char * seu_ip);

char * agent_list(char * meu_ip, char * seu_ip);

char * agent_list_back(int code, char * ips_string, char * ip_meu, char * ip_destino);

char * authenticate(char * pass, char * ip_meu, char * ip_destino);

char * authenticate_back(int code, char * ip_meu, char * ip_destino);

char * archive_list(char * ip_meu, char * ip_destino);

char * archive_list_back(int code, archive_def * archs, int quant_archs, char * ip_sender, char * ip_recipient);

char * archive_request(char * arch_id, char * ip_meu, char * ip_destino);

char * archive_request_back(int code, archive_def arch, char * ip_meu, char * ip_destino);

char * end_connection(char * ip_meu, char * ip_destino);

char ** get_command();

int run_command(char ** comando, char * ip_return, int * quit);

char * get_my_ip();

/* quem: 0 = lista de IPs do cliente,
 *       1 = lista de IPs so servidor */
int insert_ip(int quem, char ips_string[50][20], char * novo_ip);

int remove_ip(int quem, char ips_string[50][20], char * target);

char * get_ips_string(char ips_string[50][20]);

int tem_arch(archive_def * archs, int quant_archs, int id);

protocolo set_proto(char * entrada);

//int set_ips_array(char ips_string[50][20], char * proto_back);

int server_ips_size(int modifier);

int server_ips_size(int modifier);

int client_ips_size(int modifier);

int server_find_ip(char ips_array[50][20], char * target);

void help();

