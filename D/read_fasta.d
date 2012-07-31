/*
 * Dependencies:
 *   ldc ldc-phobos
 * Compile with:
 *   ldc2 read_fasta.d
 */

import std.stdio;

int main()
{
    writefln("%s World!", "Hello");
    
    File file = File("../fasta.sample", "r");

    while (!file.eof())
    {
        string line = chomp(file.readln());
        writeln("read line -> |", line);
    }
    file.close();
    return 0;
}
