/*
 * COMP3109 Calculator Exercise
 *
 * Task: Fill in the missing code for method next() that 
 * produces a sequence of tokens from a stream of
 * characters. 
 */

#include "exception.h"
#include "scanner.h"

using namespace std;

// get next token from input line
enum token scanner::next() 
{
    // write your own tokenizer here!!
    throw calc_exception();
}
