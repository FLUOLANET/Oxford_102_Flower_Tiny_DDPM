#include <iostream>
#include <sys/socket.h>
#include <netinet/in.h>
#include <unistd.h>

int main() {

    // Generate Listening Socket
    // - socket(domain, type, protocol): returns file descriptor(number ticket)
    // - AF_INET: address family = IPv4
    // - SOCK_STREAM: TCP
    // - 0: most proper protocol
    int listen_fd = socket(AF_INET, SOCK_STREAM, 0);

    // Address Card Struct
    sockaddr_in address; // sockaddr_in: struct in <netinet/in.h>
    address.sin_family = AF_INET; // sin: socket internet
    address.sin_addr.s_addr = INADDR_ANY; //INADDR: internet address - any IP
    address.sin_port = htons(8080); // htons(): host to network short(type), 0808 -> 8080

    // Binding: connect my socket with (IP address, Port)
    // - bind(int fd, const struct sockaddr *address card, address card length): 
    // - address: sockaddr_in type -> need to cast to sockaddr type
    bind(listen_fd, (struct sockaddr*)&address, sizeof(address));

    // Listening
    listen(listen_fd, 3);
    std::cout << "Listening...Port: 8080" << std::endl;

    return 0;
}