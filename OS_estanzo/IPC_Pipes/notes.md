# IPC(InterProcess Communication)

To make the pipes you have to define array in which you stored key keys for reading and writing

Now pipe function create pipes and now we can read and write to it

It is suggested that create the pipes before the fork becuase the pipes will be assinged to the new process with new  memory storage. 

The pipes are independent on each other they can be opened in process and may closed on another process.

fd[2] because same as real life pipe has two ends one is the read end and one is the right end.

fd[0] - read end    (read the data)
fd[1] - write   end (write the data)


File Descriptors are inhereted so we have to manage our file descriptors on each end


<!-- Standard Procedure is that you have to close the end
 -->


Whenever you write or read check for error 

In execlp(file_name, file_name, arg1, arg2, NULL) we donot need the complete path of the executable we only need name like ls is the filename and then 
the arguments it is going to take -s -l will be exeucuted.

In execv command you can pass the the parameters as the array and at Last we have NULL


0777 => 0 is very important it is telling it octal value not the decimal value

Three File Descriptors that opened before you go to the main are 
0  -> STDINPUT
1  -> STDOUT
2  -> STDERROR

Next file descriptor created when you open a file using the different flags called O_CREATE, O_RDONLY

dup(file) returns another file descriptor for our result
dup function take our file descriptor and duplicated it 
and it returned another file descriptor and that is also points to same file here

dup2 function take two parameters one the file descriptor that we want to duplicate and the second one is the new value that we want our
new file descriptor to have

dup2(file, 1)

Now it find 1 in stdOutput it is going to put our new file there on stdOutput

with new id
It doesnot change the process id nor the file descriptors

Now stdout is the file instead of printing to a file it is going to print on that file that we have passed in dup 2 function 

so instead of printing on console it is going to print to that file


STDOUT_FILENO => 1 stdoutput file descriptor

we should just close the file descriptor that is not used

     