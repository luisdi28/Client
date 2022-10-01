#include <arpa/inet.h>
#include <stdio.h>
#include <string.h>
#include <sys/socket.h>
#include <unistd.h>
#define PORT 8080
#include <iostream>
#include <opencv4/opencv2/opencv.hpp>
#define SIZE 20

using namespace std;


int main(int argc, char const* argv[])
{
    int sock = 0, valread, client_fd;
    struct sockaddr_in serv_addr;
    char* hello = "Hello from client qwwef";
    int buffer[SIZE];
    if ((sock = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        printf("\n Socket creation error \n");
        return -1;
    }

    serv_addr.sin_family = AF_INET;
    serv_addr.sin_port = htons(PORT);

    // Convert IPv4 and IPv6 addresses from text to binary
    // form
    if (inet_pton(AF_INET, "127.0.0.1", &serv_addr.sin_addr)
        <= 0) {
        printf(
                "\nInvalid address/ Address not supported \n");
        return -1;
    }

    if ((client_fd
                 = connect(sock, (struct sockaddr*)&serv_addr,
                           sizeof(serv_addr)))
        < 0) {
        printf("\nConnection Failed \n");
        return -1;
    }

    FILE *imagen = fopen("/home/andres/CLionProjects/Cliente-Servidor_prueba/Cliente/Imagen1.jpg", "rb");

    int readBytes = fread(&buffer, sizeof(int), 20, imagen);
    string t = to_string(readBytes);
    char const *n_char = t.c_str();
    send(sock, n_char, strlen(n_char), 0);
    valread = read(sock, buffer, 1024);
    //printf("%s\n", buffer);

    // closing the connected socket
    close(client_fd);
    fclose(imagen);

    return 0;
}