#include "fasta.h"
#include <string.h>
#include <stdio.h> // provides printf

const char* Fasta::header()
{
    return strdup(_header.c_str());
}

const char* Fasta::data()
{
    return strdup(_data.c_str());
}

int Fasta::length()
{
    return _data.length();
}

int Fasta::gccontent()
{
    if (_data.length() == 0){
        return 0;
    }
    int gccontent = 0;

    std::string s(_data);
    for (std::string::iterator it = s.begin(), end = s.end(); it != end; ++it)
    {
        char c = tolower(*it);
        if (c == 'c' || c == 'g')
        {
            gccontent = gccontent + 1;
        }
    }
    return (gccontent * 100 / _data.length());
}

void Fasta::setName(const std::string& name)
{
    _header = name;
}

void Fasta::setSequence(const std::string& sequence)
{
    _data = sequence;
}

void Fasta::addSequence(const std::string& sequence)
{
    if (!_data.empty())
    {
        _data = _data + sequence;
    } else {
        _data = sequence;
    }
}
