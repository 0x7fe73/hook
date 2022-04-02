#include <iostream>
#include <windows.h>

/*
    *  src/hook/hook.hpp
    *  Author: 0x7fe73
    *  Date: 04/02/2022
*/

class Hook {
    public:
        bool HookFunction(void *target, void *jump, size_t size);
        BOOL ProtectHook(void *hook, size_t size);
};
