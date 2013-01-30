#ifndef __FASTA_H_INCLUDED__
#define __FASTA_H_INCLUDED__

#include <string>

class Fasta {
public:
    // Header of the sequence
    const char* header();

    // Sequence itself
    const char* data();

    // Length of the sequence
    int length();

    // GC content of the sequence
    int gccontent();

    void setName(const std::string& name);

    void setSequence(const std::string& data);
    void addSequence(const std::string& data);

protected:
    std::string _header; // Header of the sequence
    std::string _data; // Sequence itself
};

#endif /* __FASTA_H_INCLUDED__ */
