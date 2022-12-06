#include <winsock2.h>
#include <stdio.h>
#include <windows.h>
#include <process.h>
#include "strdonn.h"

typedef int socklen_t;
typedef unsigned char byte;

#define PORT 1989

Tmaillon *t, *q;

void Traiter_Info() {
	POINT p;

	while(1) {
		if (!File_vide(t)){
			Defiler(&t, &q, &p);
			SetCursorPos(p.x, p.y);
		}
	}
}

int main(void)
{
	WSADATA WSAData;
	int erreur = WSAStartup(MAKEWORD(2,2), &WSAData);
 
    SOCKET sock;
    SOCKADDR_IN sin;
	
    HOSTENT *remoteHost;
    IN_ADDR addr;
	
	POINT p;
 
    /* Si les sockets Windows fonctionnent */
    if(!erreur)
    {
        /* Création de la socket */
        sock = socket(AF_INET, SOCK_STREAM, 0);
		
		remoteHost = gethostbyname("SONY-VAIO");

		if (remoteHost != NULL && remoteHost->h_addrtype == AF_INET) {
			addr.s_addr = *(u_long *) remoteHost->h_addr_list[0];
		}
 
        /* Configuration de la connexion */
		sin.sin_addr = addr;
        sin.sin_family = AF_INET;
        sin.sin_port = htons(PORT);
 
        /* Si l'on a réussi à se connecter */
        if(connect(sock, (SOCKADDR*)&sin, sizeof(sin)) != SOCKET_ERROR)
        {
            printf("Connection à %s sur le port %d\n", inet_ntoa(sin.sin_addr), htons(sin.sin_port));
            
			init_File(&t, &q);
			
            /* Si l'on reçoit des informations : on les affiche à l'écran */
			
			_beginthread(Traiter_Info, 0, NULL);
			
			while (1) {
				if(recv(sock, (void *)&p, sizeof(POINT), 0) != SOCKET_ERROR)
					Enfiler(&t, &q, p);
			}

        }
        /* sinon, on affiche "Impossible de se connecter" */
        else
        {
            printf("Impossible de se connecter\n");
        }
 
        /* On ferme la socket */
        closesocket(sock);
 

		WSACleanup();
    }
 
    /* On attend que l'utilisateur tape sur une touche, puis on ferme */
    getchar();
 
    return EXIT_SUCCESS;
}
