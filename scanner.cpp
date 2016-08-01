/*
 * COMP3109 Calculator Exercise
 *
 * Task: Fill in the missing code for method next() that 
 * produces a sequence of tokens from a stream of
 * characters. 
 */

#include <stdlib.h>
#include <sstream>
#include "exception.h"
#include "scanner.h"

using namespace std;

// get next token from input line
enum token scanner::next()
{
    stringstream ss;

    // skip spaces
    while (idx < input.length() && isspace(input[idx]))
    {
        ++idx;
    }

    // check if the line has ended
    if (idx >= input.length())
    {
        return t_eol;
    }

    // check number
    if (isdigit(input[idx]))
    {
        ss << input[idx++];
        while (idx < input.length() && isdigit(input[idx]))
        {
            ss << input[idx++];
        }

        num_value = atof(ss.str().c_str());
        ss.str(string());
        ss.clear();

        return t_number;
    }

    // check identifier
    if (isalpha(input[idx]))
    {
        ss << input[idx++];
        while (idx < input.length() && isalnum(input[idx]))
        {
            ss << input[idx++];
        }
        id_value = ss.str();
        ss.str(string());
        ss.clear();

        if (id_value == "let")
        {
            return t_let;
        }
        else
        {
            return t_ident;
        }
    }

    // plus
    else if(input[idx]=='+')
    {
        idx ++;
        return t_plus;
    }

    // minus
    else if(input[idx]=='-')
    {
        idx ++;
        return t_minus;
    }

    // multiply
    else if(input[idx]=='*')
    {
        idx ++;
        return t_multiply;
    }

    // divide
    else if(input[idx]=='/')
    {
        idx ++;
        return t_divide;
    }

    // assign
    else if(input[idx]=='=')
    {
        idx ++;
        return t_equal;
    }

    // left parenthesis
    else if(input[idx]=='(')
    {
        idx ++;
        return t_lparen;
    }

    // right parenthesis
    else if(input[idx]==')')
    {
        idx ++;
        return t_rparen;
    }

    // unrecognised token
    else
    {
        throw calc_exception();
    }
}
