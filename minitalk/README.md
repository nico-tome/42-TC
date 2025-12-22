# ☎️ Minitalk

The project introduc the concept of `signals` (will be usefull for minishell). The goal is to create two programs, a clien and a server.
The client will read the user input and store a string from it. Then he will passe it to the server that need to print it on his own terminal.

To do that we will use two signals `SIGUSR1` and `SIGUSR2`. After some reflexion I understood that we will need to use binary to recreate the string.
For exemple:

`a` decimale value is `97` and to represente `97` in binary it's `01100001 (0*128 + 1*64 + 1*32 + 0*16 + 0*8 + 0*4 + 0*2 + 1*1`.

So by using `SIGUSR1` to represent `0` and `SIGUSR2` to represent `1`, we can pass the binary representation of our letter beetween to processus.

For the bonus we need to learn signal mask with struct `sigaction`, function `sigemptyset` and `sigaction` elements like `sa_handler` or `sa_flag`, and how it can store value like the pid of the signal sender and more data. 
It will be usefull for sending back a signal to say that we succesfully receive the string, and also handle UTF-8 characters.

The project was short but really fun to do.
