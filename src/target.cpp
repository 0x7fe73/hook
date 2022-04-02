#include "hook/hook.hpp"

/*
    *  src/target.cpp
    *  Author: 0x7fe73
    *  Date: 04/02/2022
*/

int Good() { 
    return 50; 
}
int Bad() { 
    return 1; 
} 

int main() {
    /* Only works on x86 operating systems */
    Hook hook;
    printf("Before: Good(); -> %d\n", Good());
    hook.HookFunction((void *)Good(), (void *)Bad(), sizeof(Good()));
    printf("After: Good(); -> %d\n", Good());
}