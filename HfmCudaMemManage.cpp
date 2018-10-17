//
// Created by jaken on 18-10-17.
//

#include "HfmCudaMemManage.h"
#include <iostream>
#include <unordered_map>
#include <map>
#include <list>
#include <mutex>

static std::mutex mtx;
static std::unordered_map<size_t,std::map<size_t,std::list<void *>>::iterator> fast_table;
static std::map<size_t,std::list<void *>> biger_table;
static std::unordered_map<void *,size_t> record_table;


bool HPcudaMalloc( void** devPtr, size_t size ){
        mtx.lock();
        if(fast_table.empty())//为空
        {
            mtx.unlock();
            //cudaMalloc

            return true;
        }


        if (fast_table.count(size) == 1 && !fast_table[size]->second.empty()) {
               *devPtr = (fast_table[size]->second).back();
               fast_table[size]->second.pop_back();
               mtx.unlock();
               return true;
        }

            biger_table[size]=std::list<void*>();
            std::map<size_t,std::list<void *>>::iterator it=biger_table.find(size);
            ++it;
            if(it!=biger_table.end()&&it->first<2*size&&!it->second.empty())
            {
                *devPtr = it->second.back();
                it->second.pop_back();
                mtx.unlock();
                return true;
            }

            mtx.unlock();
            //cudaMalloc



}

bool HPcudaFree(void* devPtr){




}