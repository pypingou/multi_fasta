#!/usr/bin/env python
# -*- coding: utf-8 -*-

""" This file is a simple python script reading a fast file and save it
to memory into Fasta object.
"""

import os


class Fasta(object):
    """ Class representing a FASTA sequence.
    This class has two attributes, a name corresponding to the header
    line and a data corresponding to the sequence itself.
    """

    def __init__(self, name=None, data=None):
        """ Constructor. """
        self.name = name
        self.data = data

    def __repr__(self):
        return '<Fasta "%s">' % self.name


def read_fasta(filename):
    """ Read a fasta file and return a list of Fasta object. """
    if not os.path.exists(filename):
        print "No file '%s' found" % filename
        return
    stream = open(filename, 'r')
    fasta = None
    fasta_seq = []
    for row in stream.readlines():
        if row.startswith('>'):
            if fasta:
                fasta_seq.append(fasta)
            name = row.split('>', 1)[1].strip()
            fasta = Fasta(name = name)
        else:
            if fasta is not None:
                if fasta.data:
                    fasta.data = fasta.data + row.strip()
                else:
                    fasta.data = row.strip()
    if fasta:
        fasta_seq.append(fasta)
    return fasta_seq


if __name__ == '__main__':
    for seq in read_fasta(os.path.join(os.path.dirname(
        os.path.abspath( __file__ )),
        '..', 'sample.fasta')):
        print seq.name, len(seq.data)
