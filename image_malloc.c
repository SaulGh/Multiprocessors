#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *image, *outputImage, *lecturas;
    
    unsigned char* img = (unsigned char*)malloc(927361*3*sizeof(unsigned char));
    unsigned char* grey = (unsigned char*)malloc(927361*3*sizeof(unsigned char));
    image = fopen("sample.bmp","rb");          //Imagen original a transformar
    outputImage = fopen("img3_dd.bmp","wb");    //Imagen transformada}

    unsigned char r, g, b;               //Pixel
    int j = 0;

    for(int i=0; i<54; i++) fputc(fgetc(image), outputImage);   //Copia cabecera a nueva imagen
    

    while(!feof(image)){
        *(img+j) = fgetc(image);
        j++;
    }

    for (int i = 54; i < 927361*3; i+=3)
    {
        r = *(img+i);
        g = *(img+i+1);
        b = *(img+i+2);

        unsigned char pixel = 0.21*r+0.72*g+0.07*b;

        *(grey+i) = pixel;
        *(grey+i+1) = pixel;
        *(grey+i+2) = pixel;
    }
    for (int i = 0; i < 927361*3; i++)
    {
        fputc(*(grey+i), outputImage);
    }
    free(img);
    free(grey);
    printf("Termino\n");
    fclose(image);
    fclose(outputImage);
    return 0;
}