#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "encode.h"

/* Function Definitions */

/* Get File pointers for i/p and o/p files
 * Inputs: Src Image file, Secret file and
 * Stego Image file
 * Output: FILE pointer for above files
 * Return Value: e_success or e_failure, on file errors
 */
Status open_files_encode(EncodeInfo *encInfo)
{
    printf("INFO: Opening required files\n");
    // Src Image file
    printf("INFO: Opening %s\n",encInfo->src_image_fname);
    encInfo->fptr_src_image = fopen(encInfo->src_image_fname, "r");
    //Do encInfo->secret_fnameError handling
    if (NULL == encInfo->fptr_src_image)
    {
        print_file_error(encInfo->src_image_fname);
        return e_failure;
    }
    printf("INFO: Opening %s\n",encInfo->secret_fname);
    // Secret file
    encInfo->fptr_secret = fopen(encInfo->secret_fname, "r");
    //Do Error handling
    if (NULL == encInfo->fptr_secret)
    {
        print_file_error(encInfo->secret_fname);
        return e_failure;
    }

    printf("INFO: Opening %s\n",encInfo->stego_image_fname);
    // Stego Image file
    encInfo->fptr_stego_image = fopen(encInfo->stego_image_fname, "w");
    //Do Error handling
    if (NULL == encInfo->fptr_stego_image)
    {
        print_file_error(encInfo->stego_image_fname);
        return e_failure;
    }

    printf("INFO: Done\n");
    // No failure return e_success
    return e_success;

}

/* Get file size
 * Input: Secret file ptr
 * Output: uint size
 * Description: In file.txt, go to the EOF and seek the poistion
 * and save, once done, reset the position to 0 and return the
 * saved value which gives the size of the file
 */
uint get_file_size(FILE *fptr)
{

    printf("INFO: ## Encoding Procedure Started ##\n");
    uint file_size;
    printf("INFO: Checking size Text file \n");
    // Seek to nth byte
    fseek(fptr, 0L, SEEK_END);
    // Save the current position value
    file_size = ftell(fptr);
    // Seek back to 0th byte
    fseek(fptr, 0L, SEEK_SET);

    //Return the size
    return file_size;
    printf("INFO: Done.Not Empty\n");
}

/* Get image size
 * Input: Image file ptr
 * Output: width * height * bytes per pixel (3 in our case)
 * Description: In BMP Image, width is stored in offset 18,
 * and height after that. size is 4 bytes
 */
uint get_image_size_for_bmp(FILE *fptr_image)
{

    uint image_size;

    // Seek to nth byte
    fseek(fptr_image, 0L, SEEK_END);
    // Save the current position value
    image_size = ftell(fptr_image);
    // Seek back to 0th byte
    fseek(fptr_image, 0L, SEEK_SET);

    //Return the size
    return image_size;

}

/* check capacity
 * Input: EncodeInfo - image capacity and secret file size
 * Output: Status: success if true
 * Description: BMP Image size should be able to handle 1:8
 *  ratio encoding excluding the header 54 bytes
 */
Status check_capacity(EncodeInfo *encInfo)
{
    printf("INFO: Checking for %s capacity to handle %s\n",encInfo->src_image_fname,encInfo->secret_fname);
    /* Check for Size Compatibility */
    if ( ((((long int)encInfo->image_capacity) - 54) - (8 * encInfo->size_secret_file)) < 1)
    {
        return e_failure;
    }
    printf("INFO: Done.Found OK\n");
    return e_success;
}


/* Copy bmp image header
 * Inputs: Src Image file and Stego Image file pointers
 * Output: Status: success if true
 * Description: e_success or e_failure, on 54 byte copy errors
encInfo->secret_fname */
Status copy_bmp_header(FILE * fptr_src_image, FILE *fptr_dest_image)
{
    printf("INFO: Copying Image Header\n");
    char image_header_data[55];
    int readptr, writeptr, i;

    /* To read exactly 54 bytes that contain header info */
    if ((readptr = fread(image_header_data, 1, 54, fptr_src_image)) != 54)
    {
        if (ferror(fptr_src_image) != 0)
        {
            fprintf(stderr, "Reading error. \n" );
            clearerr(fptr_src_image);
            return e_failure;
        }

    }

    /* If failed to write what is read into dest header */
    if ((writeptr = fwrite(image_header_data, 1, readptr, fptr_dest_image)) != readptr)
    {
        return e_failure;
    }
    printf("INFO: Done\n");
    return e_success;
}

/* Encode secret file size
 * Inputs: Secret file size and Stego Image file pointers
 * Output: Status: success if true
 * Description: e_success or e_failure,
 *  on 32 byte size encode  errors
 */

Status encode_secret_file_size(long file_size, EncodeInfo *encInfo)
{
    printf("INFO: Encoding %s file Extenstion\n",encInfo->secret_fname);
    printf("INFO: Done\n");

    char MSBbits[32] = {0};
    int i, j, readptr, writeptr, iterptr, temp;

    /* MSB is in reverse order */
    for (i = 0; i < 32; i++)
    {
       // file_size & 0x00000001;
        if( (file_size & 0x00000001) == 0)
        {
            MSBbits[i] = '0';
        }
        else if( (file_size & 0x00000001) == 1)
        {
            MSBbits[i] = '1';
        }
        file_size >>= 1;
    }
    MSBbits[i] = '\0';
printf("INFO: Done\n");
    //reverse string to get the MSBs in order
    for (i = 0, j = strlen(MSBbits)-1; i < j; i++, j--) {
        temp = MSBbits[i];
        MSBbits[i] = MSBbits[j];
        MSBbits[j] = temp;
    }
printf("INFO: Encoding %s file size\n",encInfo->secret_fname);
    //printf("%s", MSBbits);
    //printf("\n");

    // Seek to 55th byte and onward
    fseek(encInfo->fptr_src_image, 55L, SEEK_SET);
    // Seek to 55th byte and onward
    fseek(encInfo->fptr_stego_image, 55L, SEEK_SET);

    iterptr = ftell(encInfo->fptr_src_image);

    i = 1;
    // Encode the next 32 Image data into buffer for size
    while(iterptr < 87)
    {
        //printf("%d : ", iterptr);

        /* read byte by byte */
        if ((readptr = fread( encInfo->image_data, 1, 1, encInfo->fptr_src_image)) != 1)
        {
            if (ferror(encInfo->fptr_src_image) != 0)
            {
                fprintf(stderr, "Reading error. \n" );
                clearerr(encInfo->fptr_src_image);
                return e_failure;
            }
        }

        //fetched one byte successfully, so now check for encoding

        if(encode_byte_tolsb(MSBbits[i], encInfo->image_data) == e_failure)
        {
            fprintf(stderr, "Encoding error. \n" );
            return e_failure;
        }

        //encoded data saved in image_buffer is written to stegfile
        if((writeptr = fwrite(encInfo->image_data, 1, 1, encInfo->fptr_stego_image)) != 1)
        {
            fprintf(stderr,"write file error.\n");
            return e_failure;
        }

        i++;
        iterptr++;
    }
    printf("INFO: Done\n");
    return e_success;
}

/* Encode a byte into LSB of image data array
 * Inputs: 1 byte of data and 1 byte of image data
 * Output: Status: success if true
 * Description: e_success or e_failure,
 *  on encoding MSB of secret data to LSB of imade data
 */

Status encode_byte_tolsb(char data, char *image_buffer)
{
    //set LSB of the image_buffer with data and
    *image_buffer = ((*image_buffer & ~0x01) | (data & 0x01)) ;
    return e_success;
}

/* Encode secret file data
 * Inputs: Secret file data, image file and
 *  Stego Image file pointers
 * Output: Status: success if true
 * Description: e_success or e_failure,
 *  on all data byte of secret file encode  errors
 */
Status encode_secret_file_data(EncodeInfo *encInfo)
{
    MsbMap msbtemp, tempValues;
    printf("INFO: Encoding %s file Data\n",encInfo->secret_fname);
    int readsecretptr, readptr, writeptr, i;
    char tempdata, mask;
    char *tempMsb;


    // Seek to 0th byte and onward for secret file
    fseek(encInfo->fptr_secret, 0L, SEEK_SET);
    // Seek to 87th byte and onward for image file
    fseek(encInfo->fptr_src_image, 86L, SEEK_SET);
    // Seek to 87th byte and onward for steg file
    fseek(encInfo->fptr_stego_image, 86L, SEEK_SET);

    /* Do till EOF for secret file is reached */

    while(feof(encInfo->fptr_secret) == '\0')
    {
        //Read 1 byte from secret file to secretdata buffer
        if((readsecretptr = fread(encInfo->secret_data, 1, 1, encInfo->fptr_secret))!= 1)
        {
            if(ferror(encInfo->fptr_secret)!=0)
            {
                fprintf(stderr,"read file error.\n");
                clearerr(encInfo->fptr_secret);
                return e_failure;
            }

        }

        //Get the MSBs in MSBbit for that secret data
        tempdata = *encInfo->secret_data;
	msbtemp.MSB_BYTE = *encInfo->secret_data;

	/* Reverse MSB and save */
	tempValues.bitaccess.BIT0 = msbtemp.bitaccess.BIT7;
	tempValues.bitaccess.BIT1 = msbtemp.bitaccess.BIT6;
	tempValues.bitaccess.BIT2 = msbtemp.bitaccess.BIT5;
	tempValues.bitaccess.BIT3 = msbtemp.bitaccess.BIT4;
	tempValues.bitaccess.BIT4 = msbtemp.bitaccess.BIT3;
	tempValues.bitaccess.BIT5 = msbtemp.bitaccess.BIT2;
	tempValues.bitaccess.BIT6 = msbtemp.bitaccess.BIT1;
	tempValues.bitaccess.BIT7 = msbtemp.bitaccess.BIT0 ;

    //read image byte and MSBbit and Encode for 8 bits
	//printf("\n ");
        for (i = 0; i < 8; i++)
        {

		// read byte by byte starting from 55th in image
            if ((readptr = fread( encInfo->image_data, 1, 1, encInfo->fptr_src_image)) != 1)
            {
                if (ferror(encInfo->fptr_src_image) != 0)
                {
                    fprintf(stderr, "Reading error. \n" );
                    clearerr(encInfo->fptr_src_image);
                    return e_failure;
                }
            }

		// Get the MSB value in mask
		mask = tempValues.MSB_BYTE & 0x01;
		//printf("%x ", mask);

	    //Only MSb should be used for encoding

	    //fetched one byte successfully, so now check for encoding
             if(encode_byte_tolsb(mask, encInfo->image_data) == e_failure)
            {
                fprintf(stderr, "Encoding error. \n" );
                return e_failure;
            }

	    //encoded data saved in image_buffer is written to stegfile

            if((writeptr = fwrite(encInfo->image_data, 1, 1, encInfo->fptr_stego_image)) != 1)
            {
                fprintf(stderr,"write file error.\n");
                return e_failure;
            }


            tempValues.MSB_BYTE >>= 1;
	}
	/* Do this eight times */

    }
    printf("INFO: Done\n");
    return e_success;
}


/* Copy remaining image bytes from src to stego image after encoding
 * Inputs: image file and Stego Image file pointers
 * Output: Status: success if true
 * Description: e_success or e_failure,
 *  on all the remaining data byte of image file copy  errors
 */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest)
{
    printf("INFO: Copying left Over Data\n");
    int readptr, writeptr, i;
    char image_remaining_data[MAX_IMAGE_BUF_SIZE];

    //get the current cursor value
    fseek(fptr_src, 0L, SEEK_CUR);
    //printf("%ld \n", ftell(fptr_src));


    while(feof(fptr_src)==0)
    {

        // To read remaining data till end
        if ((readptr = fread( image_remaining_data, 1, MAX_IMAGE_BUF_SIZE, fptr_src)) != MAX_IMAGE_BUF_SIZE)
        {
            if (ferror(fptr_src) != 0)
            {
                fprintf(stderr, "Reading error. \n" );
                clearerr(fptr_src);
                return e_failure;
            }

        }

        // If failed to write what is read into dest header
        if ((writeptr = fwrite( image_remaining_data, 1, readptr, fptr_dest)) != readptr)
        {
            return e_failure;
        }
    }
printf("INFO: Done\n");
    return e_success;

}
/* for clean exit close all files */
void close_files_encode(EncodeInfo *encInfo)
{
    fclose(encInfo->fptr_secret);
    fclose(encInfo->fptr_src_image);
    fclose(encInfo->fptr_stego_image);
printf("INFO: ## Encoding Done Successfully ##\n\n");
}
