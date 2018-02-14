#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "decode.h"


/* Function Definitions */

/* Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files_decode(EncodeInfo *encInfo)
{
 printf("INFO: Opening Required files\n");
    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "w");
    //Do Error handling
    if (NULL == encInfo->fptr_secret)
    {
        print_file_error(encInfo->secret_fname);
    	return e_failure;
    }
    printf("INFO: Opened %s\n",encInfo->secret_fname);
 printf("INFO: Opening %s\n",encInfo->stego_image_fname);
    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "r");
    //Do Error handling
    if (NULL == encInfo->fptr_stego_image)
    {
        print_file_error(encInfo->stego_image_fname);
    	return e_failure;
    }
    printf("INFO: Done. Opened all required files\n");
    // No failure return e_success
    return e_success;

}


/* Decode secret file size
 * Inputs: Secret file size and Stego Image file pointer
 * Output: Status: success on true
 * Description: decode 32 bytes of stego image after 54 bytes
 *  of header to get the LSBs that contain secret file size
 */
Status decode_secret_file_size(FILE * fptr_stego_image, long *size_secret_file)
{
    int readptr, i, j, k, iterptr, tempnum, temp;
    char MSBbits[32] = {0};
    char tempdata;
    char file_size_data;
    printf("INFO: Decoding Text File Size\n");
    // Seek to 55th byte and onward
    fseek(fptr_stego_image, 54L, SEEK_SET);


    //printf(" %ld:", ftell(fptr_stego_image));
    // Decode the next 32 Image data into buffer for size
    for(i = 0; i < 32 ;i++)
    {

        //printf(" %ld:", ftell(fptr_stego_image));
        /* To read byte by byte */
        if ((readptr = fread(&file_size_data, 1, 1, fptr_stego_image)) != 1)
        {
            if (ferror(fptr_stego_image) != 0)
            {
                fprintf(stderr, "Reading error. \n" );
                clearerr(fptr_stego_image);
                return e_failure;
            }
        }

        //printf("%x ", file_size_data);


        // Now decode
        if (decode_byte_fromlsb(&tempdata, &file_size_data) == e_failure)
        {
            printf("Decoding of LSb failed.");
            return e_failure;
        }
        MSBbits[i] = tempdata;
    }
    MSBbits[i] = '\0';

    //printf("%s\n", MSBbits);
    //printf("\n");

    //reverse MSB
    for (i = 0, j = strlen(MSBbits)-1; i < j; i++, j--)
    {
        temp = MSBbits[i];
        MSBbits[i] = MSBbits[j];
        MSBbits[j] = temp;
    }

    tempnum = 0;
    //get integer value
    for (i = 0; i < 32; i++)
    {
        if (MSBbits[i] == '1')
        {
            tempnum += pow(2,i);
        }
    }
    *size_secret_file = tempnum;
    //printf("%d \n", tempnum);
    printf("INFO: Done\n");
    return e_success;

}

/* decode a byte into array from LSB of image data
 * Inputs: Secret file size and Stego Image file pointer
 * Output: Status: success on true
 * Description: decode to get LSB of the data and
 *  store in imagebuffer
 */

Status decode_byte_fromlsb(char *data, char *image_data)
{
    //get LSB of the data and store in imagebuffer
    //printf("%d", (*image_data & 0x01));
    *data = (*image_data & 0x01);
    if ((*image_data & 0x01) == 0)
    {
        *data = '0';
    }
    else if ((*image_data & 0x01) == 1)
    {
        *data = '1';
    }

    return e_success;
}

/* Decode secret file data
 * Inputs: Secret file size, Secret file and
 *  Stego Image file pointer
 * Output: Status: success on true
 * Description: decode every 8 bytes of stego image after 86 bytes
 *  of header and size info to get the each 1 byte of secret data
 */
Status decode_secret_file_data(FILE * fptr_secret, FILE * fptr_stego_image, long size_secret_file)
{

    int readptr, writeptr, i, j;

    char tempdata, msbdata, msbdata2;
    char file_size_data;
printf("INFO: Decoding Text File Data\n");
    //get the current cursor value
    fseek(fptr_stego_image, 0L, SEEK_CUR);

    //set to starting position of secret file
    fseek(fptr_secret, 0L, SEEK_SET);


    // Decode the data for the size_secret_file
    for(i = 0; i < size_secret_file; i++)
    {

        //for every 8 bytes we get one byte of data
        for (j = 0; j < 8; j++)
        {
            /* To read byte by byte */
            if ((readptr = fread(&file_size_data, 1, 1, fptr_stego_image)) != 1)
            {
                if (ferror(fptr_stego_image) != 0)
                {
                    fprintf(stderr, "Reading error. \n" );
                    clearerr(fptr_stego_image);
                    return e_failure;
                }
            }

            // Now decode to get LSB
            msbdata = file_size_data & 01;

            // Shift and or
            (msbdata2 <<= 1);
            msbdata2 |= msbdata;

        }
        //printf("%c",  msbdata2  );


        //now that we have the correct byte, write to secret file
        // If failed to write what is read into dest header
        if ((writeptr = fwrite( &msbdata2, 1, 1, fptr_secret)) != 1)
        {
            return e_failure;
        }

    }printf("INFO: Done\n");
printf("INFO: Done\n");
    return e_success;

}

/* close files for clean exit */
void close_files_decode(EncodeInfo *encInfo)
{
    fclose(encInfo->fptr_stego_image);
    fclose(encInfo->fptr_secret);
printf("INFO: ## Decoding Done Successfully\n");
}
