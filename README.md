##  Description 
This project was 
The purpose of this project is to create a small data exchange program using UNIX signals in the form of a client and a server.
- The client communicates to the server by translating a passed string into "a binary form" and then send it to the server in the form of UNIX signals.
- The server must receive the signals from the client and handle them correctly by decoding them back into a string.

##  Usage

####  Compilation

` make `
####  Run server

`$ ./server`
######  Running the server executable will display its PID.
####  Run client

`$ ./client <server_pid> <message>`
##  Additional Notes
My goal from this project was to make my program as fast as possible, using the least memory possible, by sending, allocating, decoding, displaying, and freeing every character on its own, which worked well for, but on slower machines, you may notice some signal interruptions in the form of garbage values. all you have to do in this case is to increase the time in `usleep` function to 1000, 2000, or even more.
