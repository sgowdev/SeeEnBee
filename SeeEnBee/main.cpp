//
//  main.cpp
//  SeeEnBee
//
//  Created by Stephen Gowen on 2/10/22.
//  Copyright © 2022 Stephen Gowen. All rights reserved.
//

#include "MinStack.hpp"
#include "ParenthesesValidator.hpp"

#include <assert.h>
#include <stdio.h>

void testMinStack()
{
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    assert(minStack.getMin() == -3);
    minStack.pop();
    assert(minStack.top() == 0);
    assert(minStack.getMin() == -2);
    
    printf("testMinStack successful \n");
}

void testValidParentheses()
{
    // Example 1:
    assert(ParenthesesValidator::isValid("()") == true);
    
    // Example 2:
    assert(ParenthesesValidator::isValid("()[]{}") == true);
    
    // Example 3:
    assert(ParenthesesValidator::isValid("(]") == false);
    
    // Example 4:
    assert(ParenthesesValidator::isValid("([)]") == false);
    
    // Example 5:
    assert(ParenthesesValidator::isValid("{[]}") == true);
    
    printf("testValidParentheses successful \n");
}

int main(int argc, const char* argv[])
{
    // Coding part 1 - Min Stack
    testMinStack();
    
    // Coding part 2 - Valid Parentheses
    testValidParentheses();
}
