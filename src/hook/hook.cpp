#include "hook.hpp"

/*
    *  src/hook/hook.cpp
    *  Author: 0x7fe73
    *  Date: 04/02/2022 
*/

bool Hook::HookFunction(void *target, void *jump, size_t size) {
    if (!ProtectHook(target, size))
          return false;

    uint8_t instructions[] = {0xE9, 0x0, 0x0, 0x0, 0x0};
    const uint32_t addr = (uint32_t *)jump - ((uint32_t *)target + sizeof(instructions));

    memcpy(instructions + 1, &addr, 4);
    memcpy(jump, instructions, sizeof(instructions));

    return true;
}

BOOL Hook::ProtectHook(void *hook, size_t size) {
    DWORD protect;
    BOOL resp = VirtualProtect(hook, size, PAGE_EXECUTE_READWRITE, &protect);
    return resp;
}
