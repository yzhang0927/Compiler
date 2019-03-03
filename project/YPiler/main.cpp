//
//  main.cpp
//  YPiler
//
//  Created by syd on 2019/2/26.
//  Copyright © 2019 sy. All rights reserved.
//
#include "scanner.hpp"
/*
 test example
 // initialize scanner
 scanner=Scanner.make(stdin);
 
 // next() operation to advnace the scanner.  if scanner sees errors, it complains about them to standard output, skips them, and keeps going.  it does NOT report them to the caller (we will discuss the advantages and disadvantages of this in class)
 token = scanner.next();
 
 while (token != Token.EOF)
 {
 Token.PrettyPrint(token);
 token = scanner.next();
 }
 Token.PrettyPrint(token); // EOF at this pout
 count << "I am done" <<endl;
 
 */

int main(int argc, const char * argv[]) {
    // insert code here...
    Scanner sc;
    string filePath = "/Users/syd/Desktop/source.txt";
    cout<<filePath<<endl;
    sc.readFile(filePath);
    sc.getCorpus();
    Token* token = sc.next();
    if (token==nullptr)
    {
        cout<<"eof";
    }
    else
        token->getType();
    while(token!=nullptr)
    {
        token = sc.next();
    }
    sc.printTokens();
    cout << "I am done" <<endl;
}

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
