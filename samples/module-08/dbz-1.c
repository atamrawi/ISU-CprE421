#include <stdbool.h>

int a1 = 1, a2 = 2;
int y = 2;
bool C1 = true;
bool C2 = false;
bool C3 = true;
void foo() {
    int x = a1 + a2;
    int d = a1;
    if(C1){
        x = a1;
    }else{
        x = a2 - 1;
    }

    if(C2){
        if(C3){
            y = a1;
        }else{
            d = d - a1;
        }
    }else{
        d = d + 1;
    }
    int z = x / d;
}

void main() {
    
}
