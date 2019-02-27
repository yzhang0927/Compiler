//
//  scanner.cpp
//  YPiler
//
//  Created by syd on 2019/2/26.
//  Copyright © 2019 sy. All rights reserved.
//
#include <iostream>
#include "scanner.hpp"
using namespace std;

class Scanner
{
    public:
        void make(std::istream&);
        string getCorpus(void);
        Scanner(void);
    
    private:
        string corpus;
    
};

Scanner::Scanner(void)
{
    cout << "scanner Object is being created" << endl;

}

void Scanner::make(std::istream& stream)
{
    stream >> corpus; // Cross your fingers this doesn't fail
}

string Scanner::getCorpus(void)
{
    return corpus;
}

