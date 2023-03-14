#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./recover card.raw\n");
        return 1;
    }

    FILE *raw_file = fopen(argv[1], "r");
    if (raw_file == NULL)
    {
        printf("Could not open %s.\n", argv[1]);
        return 2;
    }

    //
    unsigned char buffer[512];

    //tracks images
    int image_count = 0;

    FILE *output_file = NULL;

    //not crazy about this
    char *filename = malloc(8 * sizeof(char));


    while (fread(buffer, sizeof(char), 512, raw_file))
    {
        if (buffer [0] == 0xff && buffer [1] == 0xd8 && buffer [2]
            == 0xff && (buffer [3] & 0xf0) == 0xe0)
        {
            sprintf(filename, "%03i.jpg", image_count);

            output_file = fopen(filename, "w");

            image_count++;
        }

        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(char), 512, output_file);
        }
    }

    //closing the files
    free(filename);
    fclose(raw_file);
    fclose(output_file);

    return 0;


}