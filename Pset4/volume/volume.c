// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

/* uint8_t type represents one byte in file header,
   uint16_t type represents two bytes as a unit for each audio sample in file*/
typedef uint8_t BYTE;
typedef int16_t AUDIO;

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // TODO: Copy header from input file to output file
    BYTE header[HEADER_SIZE];
    fread(header, sizeof(BYTE), 44, input);
    fwrite(header, sizeof(BYTE), 44, output);

    // TODO: Read samples from input file and write updated data to output file
    AUDIO buffer;
    while(fread(&buffer, sizeof(AUDIO), 1, input) == 1)
    {
        buffer = buffer * factor;
        fwrite(&buffer, sizeof(AUDIO), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
