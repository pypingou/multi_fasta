/*
 * Dependencies:
 *   ldc ldc-phobos
 * Compile with:
 *   ldc2 read_fasta.d
 */

import std.stdio;
import std.string;
import std.algorithm;

class Sequence {
    private:
        string _name;
        string _sequence;

    public:
        ~this() { }
        string getName()
        {
            return _name;
        }

        void setName(string name)
        {
            _name = name;
        }

        string getSequence()
        {
            return _sequence;
        }

        void setSequence(string sequence)
        {
            _sequence = sequence;
        }

        void appendSequence(string sequence)
        {
            _sequence = _sequence ~ sequence;
        }

        ulong getSequenceLength()
        {
            return _sequence.length;
        }
}

int main()
{
    File file = File("../sample.fasta", "r");

    Sequence[] sequences;
    Sequence sequence;
    string header_start = ">";
    while (!file.eof())
    {
        string line = file.readln().chomp;
        if (line && strip(line))
        {
            if (line.startsWith(">"))
            {
                if (sequence)
                {
                    ++sequences.length;
                    sequences[sequences.length - 1] = sequence;
                }
                sequence = new Sequence();
                sequence.setName(line[1..line.length]);
            } else {
                sequence.appendSequence(line);
            }
        }
    }
    if (sequence)
    {
        ++sequences.length;
        sequences[sequences.length - 1] = sequence;
    }
    file.close();

    for (int cnt; cnt < sequences.length; cnt++)
    {
        writefln("Sequence: %s -- %d", sequences[cnt].getName(),
            sequences[cnt].getSequenceLength());
    }

    return 0;
}
