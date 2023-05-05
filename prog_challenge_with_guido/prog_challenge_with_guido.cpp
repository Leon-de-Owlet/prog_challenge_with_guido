// prog_challenge_with_guido.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <stdio.h>
#include <stdlib.h>
#include <FreeImage.h>
#include <time.h>

int main()
{
    int width, height;
    
    printf("=- Hello GUIDO! =-\n\n");
    
    srand(time(NULL));
    
    int i_rnd = rand() % 59;
    int j_rnd = rand() % 59;

    printf("random indices (%d,%d)\n", i_rnd, j_rnd);
    
    FreeImage_Initialise();
    FIBITMAP* image = FreeImage_Load(FIF_PNG, "image0.png", PNG_DEFAULT);

    if (!image) {
        printf("no image loaded!");
        exit(1); }

    printf("img width: %d\n", width = FreeImage_GetWidth(image));
    printf("img height: %d\n", height = FreeImage_GetHeight(image));

    float w = 35.3, h = 35.3;
    int i = 58, j = 58;
 
    int x = (i - 1) * w, y = (j - 1) * h;
    int x_rnd = i_rnd * w, y_rnd = j_rnd * h;
            
    int width_part = int(w), height_part = int(h);
    
    FIBITMAP* image_part = FreeImage_Copy(image, x, y, x + width_part, y + height_part);
    FIBITMAP* image_part_rnd = FreeImage_Copy(image, x_rnd, y_rnd, x_rnd + width_part, y_rnd + height_part);

    if (!image_part || !image_part_rnd) {
        printf("no (empty) image created!");
        exit(1); }

    RGBQUAD color;
    
    for (int j = 0; j < height_part; j++)
        for (int i = 0; i < width_part; i++) {
            FreeImage_GetPixelColor(image_part, i, j, &color);
            //If (color.rgbRed ==)
            printf("(%d,%d) - rgba(%d,%d,%d)\n", i, j, (unsigned int)color.rgbRed, (unsigned int)color.rgbBlue, (unsigned int)color.rgbGreen); 
        }
    
    
    
    FreeImage_Save(FIF_PNG, image_part, "image0_part.png", PNG_DEFAULT);
    FreeImage_Save(FIF_PNG, image_part_rnd, "image0_part_rnd.png", PNG_DEFAULT);

    FreeImage_Unload(image_part_rnd);
    FreeImage_Unload(image_part);
    FreeImage_Unload(image);

    FreeImage_DeInitialise();

    return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
