#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define SERVER_IP "127.0.0.1"
#define SERVER_PORT 8080

int main() {
    int clientSocket;
    struct sockaddr_in serverAddress;
    char serverResponse[1024];

    // Create socket
    if ((clientSocket = socket(AF_INET, SOCK_STREAM, 0)) < 0) {
        perror("Socket creation error");
        exit(EXIT_FAILURE);
    }

    // Set server details
    serverAddress.sin_family = AF_INET;
    serverAddress.sin_port = htons(SERVER_PORT);

    // Convert IPv4 and IPv6 addresses from text to binary form
    if (inet_pton(AF_INET, SERVER_IP, &(serverAddress.sin_addr)) <= 0) {
        perror("Invalid address/ Address not supported");
        exit(EXIT_FAILURE);
    }

    // Connect to the server
    if (connect(clientSocket, (struct sockaddr*)&serverAddress, sizeof(serverAddress)) < 0) {
        perror("Connection failed");
        exit(EXIT_FAILURE);
    }

    int number;
    printf("Enter a number: ");
    scanf("%d", &number);

    // Send the number to the server
    if (send(clientSocket, &number, sizeof(number), 0) < 0) {
        perror("Send failed");
        exit(EXIT_FAILURE);
    }

    // Receive the response from the server
    if (recv(clientSocket, serverResponse, sizeof(serverResponse), 0) < 0) {
        perror("Receive failed");
        exit(EXIT_FAILURE);
    }

    printf("Server response: %s\n", serverResponse);



    return 0;
}
