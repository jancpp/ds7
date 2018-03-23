//
//  Heap.h
//  ds7
//
//  Created by Jan Polzer on 3/19/18.
//  Copyright © 2018 Jan Polzer. All rights reserved.
//

#ifndef Heap_h
#define Heap_h

class Heap {
private:

public:

//    Heap();
    // virtual ~Heap() {}

    virtual void buildheap() = 0;

    virtual bool insert(int key) = 0;

    virtual bool deletemin()  = 0;

    virtual bool deletemax()  = 0;

    virtual int findmin() = 0;

    virtual int findmax() = 0;

    virtual void levelorder() = 0;

};

#endif /* Heap_h */
