//
//  ParenthesesValidator.hpp
//  SeeEnBee
//
//  Created by Stephen Gowen on 2/10/22.
//  Copyright © 2022 Stephen Gowen. All rights reserved.
//

#pragma once

#include <string>

class ParenthesesValidator
{
public:
    // Algorithmic complexity: O(n)
    static bool isValid(std::string s)
    {
        static size_t upperLimit = pow(10, 4);
        
        size_t length = s.length();
        assert(1 <= length);
        assert(length <= upperLimit);
        
        Stack<char> stack;
        for (size_t i = 0; i < length; ++i)
        {
            char c = s[i];
            assert(isCharParentheses(c));
            
            if (isCharOpeningParentheses(c))
            {
                stack.push(c);
            }
            else if (isCharClosingParentheses(c))
            {
                if (!stack.hasData())
                {
                    return false;
                }
                
                char top = stack.top();
                stack.pop();
                
                if (!isCharParenthesesMatch(top, c))
                {
                    return false;
                }
            }
        }
        return true;
    }
    
    static bool isCharParentheses(char c)
    {
        return isCharOpeningParentheses(c) || isCharClosingParentheses(c);
    }
    
    static bool isCharOpeningParentheses(char c)
    {
        return c == '(' || c == '[' || c == '{';
    }
    
    static bool isCharClosingParentheses(char c)
    {
        return c == ')' || c == ']' || c == '}';
    }
    
    static bool isCharParenthesesMatch(char openingParentheses, char closingParentheses)
    {
        return
        (openingParentheses == '(' && closingParentheses == ')') ||
        (openingParentheses == '[' && closingParentheses == ']') ||
        (openingParentheses == '{' && closingParentheses == '}');
    }
};
