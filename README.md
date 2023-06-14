# client-client-chat-server
This project implements a chat server in C language that utilizes the knowledge of a client sending data from one client to another using the server as a relay node. The server facilitates connections between clients A and B by providing the necessary port and IP information. The code is written in C language.

**Instructions to Run:**

Compilation:
Open a terminal or command prompt.
Navigate to the directory containing the source code files.
Compile the server.c file using the following command:
**gcc server.c -o server**
Compile the client.c file using the following command:
**gcc client.c -o client**

Running the Server:
In the terminal or command prompt, run the server executable using the following command:
**./server**
The server will start and bind to a specific port, waiting for client connections.

Connecting Clients:
In separate terminals or command prompts, run the client executable using the following command:
**./client**

The client will prompt you to enter the server's IP address and port number.
Enter the server's IP address and port number provided by the server.
The client will establish a connection with the server and request a connection with another client.
The server will provide the necessary information (port and IP) for the client to establish a direct connection with the other client.
Once connected, the clients can exchange messages through the server acting as a relay node.

**Notes:**
Ensure that the server is running before the clients attempt to connect.
It is recommended to test the chat server on the same machine or within a local network for simplicity.
You can modify the server's logic in server.c to implement additional features or customize the chat functionality.
Remember to terminate the program gracefully to release network resources.
