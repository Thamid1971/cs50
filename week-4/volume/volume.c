#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

typedef struct
{
    char RIFF[4];
    int32_t file_length;
    char WAVE[4];
    char fmt[4];
    int32_t fmt_size;
    int16_t PCM;
    int16_t channels;
    int32_t sample_rate;
    int32_t byte_rate;
    int16_t block_align;
    int16_t bits_sample;
    char data[4];
    int32_t data_size;
} WAV_HEADER;

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
        printf("Could not open file input.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file output.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    // Read header from input file and write updated header to output file

    WAV_HEADER header;

    fread(&header, sizeof(header), 1, input);
    fwrite(&header, sizeof(header), 1, output);

    int16_t sample;

    while (fread(&sample, sizeof(sample), 1, input) == 1)
    {
        sample = sample * factor;
        fwrite(&sample, sizeof(sample), 1, output);
    }

    // Close files
    fclose(input);
    fclose(output);
}
