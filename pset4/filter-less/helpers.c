#include "helpers.h"
#include <math.h>


// Convert image to grayscale
// we are averging our rgbt structs
// naturally, we need to do this for every single pixel
// please round it
// look, you'll need to loop through every row
// then loop through each individual pixel in the row
// assign the average to each pixel
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // float originalRed = image[i][j].rgbtRed;
            // float originalBlue = image[i][j].rgbtBlue;
            // float originalGreen = image[i][j].rgbtGreen;

            // int average = round(originalRed + originalBlue + originalGreen) / 3.0;
            int rgbgray = round((image[i][j].rgbtRed + image[i][j].rgbtGreen + image[i][j].rgbtBlue) / 3.0);

            image[i][j].rgbtRed = rgbgray;
            image[i][j].rgbtGreen = rgbgray;
            image[i][j].rgbtBlue = rgbgray;
            //image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen;
        }
    }

    return;
}




// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float originalRed = image[i][j].rgbtRed;
            float originalBlue = image[i][j].rgbtBlue;
            float originalGreen = image[i][j].rgbtGreen;

            int sepiaRed     =     round(.393 * originalRed + .769 * originalGreen + .189 * originalBlue);
            int sepiaGreen   =     round(.349 * originalRed + .686 * originalGreen + .168 * originalBlue);
            int sepiaBlue    =     round(.272 * originalRed + .534 * originalGreen + .131 * originalBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }
            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }
            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;

        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
// Simplest solution, but a tricky algorithm:
// https://youtu.be/eoHIX_PNGcE?t=795
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][width - (j + 1)];
            image[i][width - (j + 1)] = temp;
        }
    }


    return;
}




// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // Solution here: https://youtu.be/eoHIX_PNGcE?t=1040
    RGBTRIPLE temp[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            temp[i][j] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int totalRed, totalBlue, totalGreen;
            totalRed = totalBlue = totalGreen = 0;
            float counter = 0.00;

            // get neighbouring pixels
            for (int x = -1; x < 2; x++)
            {
                for (int y = -1; y < 2; y++)
                {
                    int currentX = i + x;
                    int currentY = j + y;

                    //check if neighbouring pixel is valid
                    //below, x refers to row (top-to-bottom) and y actually refers to order (left-to-right)
                    if (currentX < 0 || currentX > (height - 1) || currentY < 0 || currentY > (width - 1))
                    {
                        continue;
                    }

                    //get image value
                    totalRed += image[currentX][currentY].rgbtRed;
                    totalBlue += image[currentX][currentY].rgbtBlue;
                    totalGreen += image[currentX][currentY].rgbtGreen;

                    counter++;
                }

                // calculate average of neighbouring pixels
                temp[i][j].rgbtRed = round(totalRed / counter);
                temp[i][j].rgbtBlue = round(totalBlue / counter);
                temp[i][j].rgbtGreen = round(totalGreen / counter);
            }
        }
    }
//copy new pixels into original image
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
        }
    }

    return;
}