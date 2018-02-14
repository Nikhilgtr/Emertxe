#ifndef DECODE_H
#define DECODE_H

#include "common.h"
#include "types.h" // Contains user defined types

/* Decoding function prototype */

/* Get File pointers for i/p and o/p files */
Status open_files_decode(EncodeInfo *encInfo);

/* close files for clean exit */
void close_files_decode(EncodeInfo *encInfo);

/* Decode secret file size */
Status decode_secret_file_size(FILE * fptr_stego_image, long *size_secret_file);

/* decode a byte into array from LSB of image data  */
Status decode_byte_fromlsb(char *data, char *image_buffer);

/* Decode secret file data */
Status decode_secret_file_data(FILE * fptr_secret, FILE * fptr_stego_image, long size_secret_file);

#endif
