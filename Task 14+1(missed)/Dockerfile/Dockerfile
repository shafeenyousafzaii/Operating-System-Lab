FROM ubuntu

#install gcc (c compiler) and other necessary packages
RUN apt-get update && apt-get install -y gcc

#copy teh c program inot the container

COPY code.c /home/ubuntu

#set the working directory to user/src
WORKDIR /home/ubuntu

#compile the C program 
RUN gcc -o code code.c

#run the compiled C program when the container starts
CMD ["./code"]
