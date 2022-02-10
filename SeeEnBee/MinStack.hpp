//
//  MinStack.hpp
//  SeeEnBee
//
//  Created by Stephen Gowen on 2/10/22.
//  Copyright © 2022 Stephen Gowen. All rights reserved.
//

#pragma once

#include "Stack.hpp"

// -2^31 <= val <= 2^31 - 1 constraint satisfied by int32_t data type
class MinStack : public Stack<int32_t>
{
public:
    MinStack() : Stack<int32_t>(), _minVal(0)
    {
        // At most 3 * 10^4 calls will be made to push, pop, top, and getMin.
        _data.reserve(3 * pow(10, 4));
    }
    
    virtual void push(int32_t val)
    {
        Stack<int32_t>::push(val);
        
        redetermineMinVal();
    }
    
    virtual void pop()
    {
        Stack<int32_t>::pop();

        redetermineMinVal();
    }
    
    // retrieves the minimum element in the stack.
    int32_t getMin()
    {
        // Methods pop, top and getMin operations will always be called on non-empty stacks.
        assert(hasData());
        
        return _minVal;
    }
    
private:
    int32_t _minVal;
    
    // Algorithmic complexity: O(n)
    void redetermineMinVal()
    {
        static int32_t maxValue = pow(2, 31) - 1;
        
        int32_t smallestValue = maxValue;
        for (int32_t i : _data)
        {
            if (i < smallestValue)
            {
                smallestValue = i;
            }
        }
        _minVal = smallestValue;
    }
};
