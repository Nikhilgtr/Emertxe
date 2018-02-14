#ifndef ENCODE_H
#define ENCODE_H

#include "common.h"
#include "types.h" // Contains user defined types

/* Encoding function prototype */

/* Get File pointers for i/p and o/p files */
Status open_files_encode(EncodeInfo *encInfo);

/* close files for clean exit */
void close_files_encode(EncodeInfo *encInfo);

/* Get file size */
uint get_file_size(FILE *fptr);

/* Get image size */
uint get_image_size_for_bmp(FILE *fptr_image);

/* check capacity */
Status check_capacity(EncodeInfo *encInfo);

/* Copy bmp image header */
Status copy_bmp_header(FILE * fptr_src_image, FILE *fptr_dest_image);

/* Encode secret file size */
Status encode_secret_file_size(long file_size, EncodeInfo *encInfo);

/* Encode a byte into LSB of image data array */
Status encode_byte_tolsb(char data, char *image_buffer);

/* Encode secret file data*/
Status encode_secret_file_data(EncodeInfo *encInfo);

/* Copy remaining image bytes from src to stego image after encoding */
Status copy_remaining_img_data(FILE *fptr_src, FILE *fptr_dest);

#endif
