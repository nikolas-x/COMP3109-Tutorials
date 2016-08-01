/*
 * COMP3109 Scanner Driver
 *
 * Reads line by line from stdin and tokenizes the 
 * the input, and prints the tokens. 
 */

#include "exception.h"
#include "scanner.h"

using namespace std;

/*
 * test driver for scanner
 */
int main(int argc, char **argv)
{
    // until eof is reached
    while(!cin.eof())
    {
        try
        {
            // read line from stdin
            string line;
            getline(cin,line);

            // tokenize input line
            scanner s(line);
            token t;
            while((t=s.next())!=t_eol)
            {
                switch(t)
                {
                    case t_lparen:
                        cout << "LPAREN ";
                        break;
                    case t_rparen:
                        cout << "RPAREN ";
                        break;
                    case t_plus:
                        cout << "PLUS ";
                        break;
                    case t_minus:
                        cout << "MINUS ";
                        break;
                    case t_multiply:
                        cout << "MULTIPLY ";
                        break;
                    case t_divide:
                        cout << "DIVIDE ";
                        break;
                    case t_equal:
                        cout << "ASSIGN ";
                        break;
                    case t_ident:
                        cout << "IDENT(" << s.get_identifier() << ") ";
                        break;
                    case t_number:
                        cout << "NUMBER(" << s.get_number() << ") ";
                        break;
                    case t_let:
                        cout << "LET ";
                        break;
                    default:
                        break;
                }
            }
            cout << "\n";
        }
        catch (calc_exception &e)
        {
            cerr << e.what() << "\n";
        }
    }
}
