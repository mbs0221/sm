#include "page.h"

int init_encl_pgtable(int level, pte_t* tb, uintptr_t base, uintptr_t size){
  pte_t* walk;
  int ret = 0;
  int i=0;
  
  for (walk=tb; walk < tb + (RISCV_PGSIZE/sizeof(pte_t)) ; walk += 1)
  {
    if(*walk == 0)
      continue;

    pte_t pte = *walk;
    uintptr_t phys_addr = (pte >> PTE_PPN_SHIFT) << RISCV_PGSHIFT;
    if(! (phys_addr >= base && phys_addr < base + size))
    {
      *walk = 0;
      continue;
    }
    if(level > 1)
    {
      ret |= init_encl_pgtable(level - 1, (pte_t*) phys_addr, base, size);
    }
  }
  return ret;
}