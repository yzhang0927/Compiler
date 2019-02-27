//
//  scanner.hpp
//  YPiler
//
//  Created by syd on 2019/2/26.
//  Copyright © 2019 sy. All rights reserved.
//
#ifndef scanner_hpp
#define scanner_hpp

#include <stdio.h>


enum class Token
{
    /** specifics: tokens **/
    
    OP_UMINUS,       // "-" NOTICE it's identical to OP_MINUS; will discuss in class, two    different ways to deal with it.
    OP_LESS,         //"<"
    OP_GREATER,      //">"
    OP_LESSEQUAL,    //"<="
    OP_GREATEREQUAL, //">="
    OP_EQUAL,        //"=="
    OP_NOTEQUA,      //"!="
    OP_PLUS,         //"+"
    OP_MINUS,        //"-"
    OP_MULT,         //"*"
    OP_DIV,          //"/"
    OP_DOT,      //"."
    OP_DOTDOT,   //".."
    OP_COMMA,    //","
    
    SEMI,        //";"
    LBRAK,       //"["
    RBRAK,       //"]"
    LPAR,        //"("
    RPAR,        //")"
    ASSIGN,      //"="
    EXCHANGE,    //"<->"
    RETURN,      //"return"
    PRINT,       //"print"
    
    KW_ARRAY,    //"array"
    KW_TUPLE,    //"tuple"
    KW_LOCAL,    //"local"
    KW_GLOBAL,   //"global"
    KW_DEFUN,    //"defunc"
    KW_END,      //"end"
    KW_WHILE,    //"while"
    KW_DO,       //"do"
    KW_IF,       //"if"
    KW_THEN,     //"then"
    KW_ELSIF,    //"elsif"
    KW_ELSE,     //"else"
    KW_FOREACH,  //"foreach"
    KW_IN,       //"in"
    
    ID,          //id
    /* ([a-zA-Z_])\1{10,80}
    any sequence of one or more letters. I include "_" (underscore) in letters.  no digits.  you have to accept IDs of length at least 10 characters.  you have to put a limit on the length of IDs (no arbitrarily long IDs).  you limit should not be more than 80.  if the scanner sees an ID of length more than the limit, it should process it, complain about it in a ERROR message, and then truncate it to the limit.
     */
    
    INT_LIT,     //INT_LIT
    /*
     any sequence of one or more decimal digits.  similar to ID, you MUST implement a limit, but now on the VALUE of the number.  You may also implement a limit on the number of digits.  Please check that these fit into 32 bit signed integers.  Complain if you see a number that does not fit.
    */
};

/*
POLICY
 * only ASCII characters are legal in the input
   [entertaining option: extend IDs to accept alphanumeric-like characters from other languages in UNICODE]. 
   No other characters are allowed.
 * the language is CASE-SENSITIVE: "if" "IF" "If" and "iF" are four different things.  Three of them are IDs. "if" is a keyword.
 * keywords are in LOWER CASE.
 * a couple of keywords are there for possible future extensions,
 * COMMENT: from "***" to the end of the current line.  Does not matter what else is on the line.
 * WS (white space): any sequence of space, tabs, formfeeds etc are ignores
 * END-OF-LINE: ignored, but counted
 * better write code can deal with all END-OF-LINE (CR on old Macs, NL on Unix/Linux/Mac OS, CR LN on Windows)
*/

/*
 FUNCTION REQUIREMNT FOR SCANNER
 -- count lines
 -- count character positions
 -- store with every token the string it corresponds to in the program text, with line number and starting and ending character positions
 -- be able to read a file for input, or standard input
 -- each time there is a problem, it has to output the line number, character positions (start and finish) of the problem
 -- be uncrashable: whatever the input, it should process it, generate reasonable tokens if it find them, generate errors/warnings otherwise, and do not quit until input is exhausted
 
 -- your scanner should be initialized by giving it a source of input (say, an input stream "cin" / "stdin" or an opened file name)
 -- it must support the operation next() which returns the next token and advances the scanner
 -- it must support the operation peek() which shows the next token but does NOT advance the scanner
 -- it's not clear if we need an operation unput() or backup() which puts a token back into the buffer.  hopefully not.
 */

#endif /* scanner_hpp */
