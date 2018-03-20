//
//  Heap.h
//  ds7
//
//  Created by Jan Polzer on 3/19/18.
//  Copyright © 2018 Jan Polzer. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

#include "Node.h"

class Heap {
public:
    virtual ~Heap() {}
    
    virtual bool insert(int key) = 0;
    
    virtual bool deletemin()  = 0;
    
    virtual bool deletemax()  = 0;
    
    virtual Node *findmin() = 0;
    
    virtual Node *findmax() = 0;
    
    virtual void levelorder() = 0;
    
};

#endif /* Heap_h */
