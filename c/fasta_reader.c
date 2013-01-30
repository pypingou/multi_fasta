#include <stdio.h>   /* required for file operations */
#include <stdlib.h>

void chomp(char *s) {
    while(*s && *s != '\n' && *s != '\r') s++;
 
    *s = 0;
}


int main ( int argc, char *argv[] )
{
    // Check argument
    if (argc != 2)
    {
        printf("usage: %s filename\n", argv[0]);
        return 1;
    }

    FILE *file = fopen(argv[1], "r");

    /* fopen returns 0, the NULL pointer, on failure */
    if (file == 0)
    {
        printf("Could not open file: '%s'\n", argv[1]);
        return 2;
    }

    char * line = NULL;
    size_t len = 0;
    ssize_t read;
    int sequence_length = 0;
    int sequence_gc = 0;
    while ((read = getline(&line, &len, file)) != -1)
    {
        chomp(line);
        if (line[0] == '>')
        {
            if (sequence_length)
            {
                printf("-> %i", sequence_length);
                if (sequence_gc)
                {
                    printf(" - GC: %i%%", sequence_gc * 100 / sequence_length);
                }
                printf("\n");
            }
            printf("%s ", line);

            sequence_length = 0;
            sequence_gc = 0;
        }
        else
        {
            int i;
            for (i = 0; line[i] != 0; i++){
                char c = tolower(line[i]);
                if (c == 'c' || c == 'g')
                {
                    sequence_gc = sequence_gc + 1;
                }
                sequence_length = sequence_length + 1;
            }
        }
    }
    if (sequence_length)
    {
        printf("-> %i", sequence_length);
        if (sequence_gc)
        {
            printf(" - GC: %i", sequence_gc * 100 / sequence_length);
        }
        printf("\n");
    }
    fclose(file);

    if (line)
        free(line);

    return 0;
}
