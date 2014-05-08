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
    // JD: For full robustness, you could have computed the maximum
    //     condition based on the #defines in addressTranslation.h.
    //     That way, switching to a different configuration would have
    //     been a matter of changing the #defines.
    if (logical < 0 || logical >= 256) {
        return ERR_OUT_OF_RANGE;
    }

    int left = (logical & PAGEMASK) >> PAGEBITS;
   // JD: No need for the "&"---you're right-shifting!
    int right = logical & PAGESIZE;

    if (ptr[left].valid == 0) {
        return ERR_INVALID;
    }

    return (((ptr[left].frame) << PAGEBITS) + right);
}
