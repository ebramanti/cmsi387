/**
 * Implementation of the software paging unit.
 */
#include "addressTranslation.h"

#include <stdio.h>
#include <stdlib.h>

static pagetable *ptr = NULL; // ptr = "page table register"

void setPageTable(pagetable *pt) {
    ptr = pt;
}

int getPhysical(int logical) {
    if (logical < 0 || logical >= 256) {
        return ERR_OUT_OF_RANGE;
    }

    int left = (logical & PAGEMASK) >> PAGEBITS;
    int right = logical & PAGESIZE;

    if (ptr[left].valid == 0) {
        return ERR_INVALID;
    }

    return (((ptr[left].frame) << PAGEBITS) + right);
}