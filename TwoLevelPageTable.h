// TwoLevelPageTable.h

#ifndef TWO_LEVEL_PAGE_TABLE_H
#define TWO_LEVEL_PAGE_TABLE_H

#include <iostream>
#include <vector>
#include <cstdint>
#include <map>

using namespace std;

/**
 * Create a two-level page table for a process, given the PID.
 * Given page size, vpn, ptePfn and pfn, set a mapping from virtual page to physical frame.
 * Given a vpn, translate it to a pfn, return the pfn, pageSize.
 * Physical memory 32bit
 * Address space 32bit
 * page size from 4KB to 1GB
 */
class TwoLevelPageTable {
private:
    uint32_t pid;
    int physMemBits = 32;
    int virtualMemBits = 32;
    int pfnBits = physMemBits - 12;
    map<uint32_t, uint32_t> mapToPDEs;
    map<uint32_t, uint32_t> mapToPTEs;
    map<uint32_t, uint32_t> vpnAndPageSize;

public:
    TwoLevelPageTable(int pidGiven);

    void setMapping(uint32_t pageSize, uint32_t vpn, uint32_t ptePfn, uint32_t pfn);

    uint32_t translate(uint32_t vpn);

    void free(uint32_t vpn);
};

#endif // TWO_LEVEL_PAGE_TABLE_H
