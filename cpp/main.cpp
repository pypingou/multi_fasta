#include <stdio.h>
#include <vector>   // provides the vector
#include <iostream> // provides cout
#include <fstream>  // to read the file

#include "fasta.h"

int main (int argc, char *argv[])
{
    if (argc == 1){
        printf("Missing one argument the fasta file to read");
        return 1;
    }

    std::string line;
    std::ifstream stream (argv[1]);
    Fasta* fasta = NULL;
    std::vector< Fasta > fasta_list;
    if (stream.is_open())
    {
        while ( !stream.eof() )
        {
            getline (stream, line);
            if (line[0] == '>')
            {
                if (fasta != NULL)
                {
                    fasta_list.push_back(*fasta);
                }
                fasta = new Fasta;
                fasta->setName(line);
            }
            else 
            {
                fasta->addSequence(line);
            }
        }
        stream.close();
        if (fasta != NULL)
        {
            fasta_list.push_back(*fasta);
        }

        for (std::vector<Fasta>::iterator sequence = fasta_list.begin();
                                   sequence != fasta_list.end(); 
                                   ++sequence)
        {
            printf("%s -> %i \n", sequence->header(), sequence->length());
        }
    }
    else printf("Unable to open file\n");
    return 0;
}
