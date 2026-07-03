#include <stdio.h>
#include <stdlib.h>

typedef struct No{
    int a;
    int b;
}No;

int main() {
    No a = {2,3};

    printf("%d, %d",a.a, a.b);

}