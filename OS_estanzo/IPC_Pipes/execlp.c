#include <unistd.h>
int main() {
    // Exact path not required
    
    char * filaname = "ls";
    char *arg1 = "-a";
    char *arg2 = "-s";
    execlp(filaname, filaname, arg1, arg2, NULL);
    return 0;
}