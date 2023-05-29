#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_PORT 8081

int main() {
    int serverSocket, clientSocket;
    struct sockaddr_in serverAddress, clientAddress;
    char clientMessage[1024];
    char response[1024];

    // Create socket
    if ((serverSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server details
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_addr.s_addr = INADDR_ANY;
    serverAddress.sin_port = htons(SERVER_PORT);

    // Bind the socket to the specified IP and port
    if (bind(serverSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Bind failed");
        exit(EXIT_FAILURE);
    }

    // Listen for incoming connections
    if (listen(serverSocket, 1) < 0) {
        perror("Listen failed");
        exit(EXIT_FAILURE);
    }

    printf("Server listening on port %d...\n", SERVER_PORT);

    // Accept the connection from the client
    socklen_t clientAddressLength = sizeof(clientAddress);
    if ((clientSocket = accept(serverSocket, (struct sockaddr*)&clientAddress, &clientAddressLength)) < 0) {
        perror("Accept failed");
        exit(EXIT_FAILURE);
    }

    // Receive the number from the client
    int number;
    if (recv(clientSocket, &number, sizeof(number), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    // Determine if the number is even or odd
    if (number % 2 == 0) {
        sprintf(response, "%d is an even number", number);
    } else {
        sprintf(response, "%d is an odd number", number);
    }

    // Send the response to the client
    if (send(clientSocket, response, strlen(response), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    return 0;
}
