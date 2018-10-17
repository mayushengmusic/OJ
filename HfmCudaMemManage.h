//
// Created by jaken on 18-10-17.
//

#ifndef MEM_HFMCUDAMEMMANAGE_H
#define MEM_HFMCUDAMEMMANAGE_H

#include <cstdio>

bool HPcudaMalloc(void** devPtr, size_t size );
bool HPcudaFree(void* devPtr);



#endif //MEM_HFMCUDAMEMMANAGE_H
