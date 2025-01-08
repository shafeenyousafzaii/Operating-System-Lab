#include <stdio.h>
#include <stdlib.h>

int main() {
    struct coord {
        int x, y, z;
    };
    struct coord *p;
    p = malloc(sizeof(struct coord) * 3);
    if (p==NULL) {
        printf("Failed");
    }
    else {
        printf("\n%d bytes allocated at address %d\n", sizeof(struct coord), p);
    }
    // free(p);
    // p = NULL;
    // Changing the size to *10 
    p = realloc(p, sizeof(struct coord)*3);
    printf("size %d\n", sizeof(p));
    return 0;
}