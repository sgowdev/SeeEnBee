//
//  Stack.hpp
//  SeeEnBee
//
//  Created by Stephen Gowen on 2/10/22.
//  Copyright © 2022 Stephen Gowen. All rights reserved.
//

#pragma once

#include <vector>
#include <math.h>

template <typename T>
class Stack
{
public:
    Stack()
    {
        // Empty
    }
    
    // pushes the element val onto the stack.
    virtual void push(T val)
    {
        _data.push_back(val);
    }

    // removes the element on the top of the stack.
    virtual void pop()
    {
        // Methods pop, top and getMin operations will always be called on non-empty stacks.
        assert(hasData());
        
        _data.pop_back();
    }

    // gets the top element of the stack.
    T top()
    {
        // Methods pop, top and getMin operations will always be called on non-empty stacks.
        assert(hasData());
        
        return _data.back();
    }
    
    bool hasData()
    {
        return !_data.empty();
    }
    
protected:
    std::vector<T> _data;
};
