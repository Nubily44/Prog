#include <stdio.h>
#include <stdlib.h>

typedef struct No2{
    int a;
    int b;
}No2;

struct No1{
    int a;
    int b;
};

int main() {
    
    float matrix[3][2] = {{1,2},
                        {3,4},
                        {5,6}
                        };

    struct No1 a = {1,2};
    No2 b = {2,3};

    printf("%p", matrix);
    
    /*printf("%d, %d",a.a, a.b);
    printf("%d, %d",b.a, b.b);*/

}