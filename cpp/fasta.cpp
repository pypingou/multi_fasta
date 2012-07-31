#include "fasta.h"
#include <string.h>

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
