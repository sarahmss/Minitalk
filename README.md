# Minitalk

Communicating between processes using just *signal* (a signal is an asynchronous notification sent to processes with the purpose of notifying the occurrence of an event. As an example, when you press the Ctrl+C key, a SIGINT is sent to the script and as per defined default action script terminates.)

To represent each character we will need to send 8 signals. With that we convert ASCII character to Bynary character

### Server:
>A process that waits passively for request from clients, processes the work specified, and return the result to the client that originated the request

### Client:
>A process that initiates a service request.

    A running program in UNIX is called a process. Because Unix is a multitasking system, many processes can run at the same time. A process is a sequence of instructions and each process has a block of controlled data associated with it.
    
Allowed functions |
----
◦ write 
◦ ft_printf and any equivalent YOU coded 
◦ signal
◦ sigemptyset
◦ sigaddset
◦ sigaction
◦ kill(options, pid): send a signal to a process
◦ getpid(void) : get process identification id
◦ malloc
◦ free
◦ pause
◦ sleep(time(s)): 
◦ usleep
◦ exit