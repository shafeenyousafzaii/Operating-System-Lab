 #include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
// Check Man
 void *print_message(char *ptr)
 {
 char *message;
 message = *ptr;
 printf("%s \n", message);
 }
 int main()
 {
 pthread_t thread1, thread2;
 char *message1 = "Thread 1";
 char *message2 = "Thread 2";
 int return_value1, return_value2;
 return_value1 = pthread_create(&thread1,NULL, print_message, *message1);
 return_value2 = pthread_create(&thread2,NULL, print_message, *message2);
 pthread_join( thread1, NULL );
 pthread_join( thread2, NULL );
 exit();
 }
