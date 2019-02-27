//
//  main.cpp
//  YPiler
//
//  Created by syd on 2019/2/26.
//  Copyright © 2019 sy. All rights reserved.
//

#include <iostream>
using namespace std;
//#include "scanner.cpp"

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

class Scanner
{
public:
    void make(istream&);
    void getCorpus(void);
    void getNumLine(void);
    Scanner(istream&);
    
private:
    string corpus;
    int numLine;
    
};

Scanner::Scanner(istream& stin)
{
    cout << "scanner Object is being created" << endl;
    
    numLine = 0;
    this->make(stin);
}

void Scanner::make(istream& stin)
{
    getline(stin,corpus);
    //stream >> this->corpus; // Cross your fingers this doesn't fail
}

void Scanner::getCorpus(void)
{
    cout<<corpus;
}

void Scanner::getNumLine(void)
{
    cout<<this->numLine;
}

int main(int argc, const char * argv[]) {
    // insert code here...
    Scanner sc(cin);
    sc.getCorpus();
    return 0;
}
