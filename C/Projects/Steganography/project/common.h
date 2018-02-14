#ifndef COMMON_H
#define COMMON_H

#include "types.h" // Contains user defined types

#define MAX_SECRET_BUF_SIZE 1
#define MAX_IMAGE_BUF_SIZE (MAX_SECRET_BUF_SIZE * 8)
#define MAX_FILE_SUFFIX 4

/* Structure to store information required for
 * encoding secret file to source Image
 * Info about output file used for decoding and intermediate data is
 * also stored
 */
typedef struct _EncodeInfo
{
    /* Source Image info */
    char *src_image_fname;
    FILE *fptr_src_image;
    uint image_capacity;
    uint bits_per_pixel;
    char image_data[MAX_IMAGE_BUF_SIZE];
    
    /* Secret File Info */
    char *secret_fname;
    FILE *fptr_secret;
    char extn_secret_file[MAX_FILE_SUFFIX];
    char secret_data[MAX_SECRET_BUF_SIZE];
    long size_secret_file;
    
    /* Stego Image Info */
    char *stego_image_fname;
    FILE *fptr_stego_image;
    
} EncodeInfo;



typedef union _MSBBYTE
{
    unsigned char MSB_BYTE;
    
    struct Bits
    {
        unsigned char BIT0 : 1;
        unsigned char BIT1 : 1;
        unsigned char BIT2 : 1;
        unsigned char BIT3 : 1;
        unsigned char BIT4 : 1;
        unsigned char BIT5 : 1;
        unsigned char BIT6 : 1;
        unsigned char BIT7 : 1;
    }bitaccess;	
    
} MsbMap;

/* Commonly used function prototype */

/* Get error message */
void print_usage_error(char * message);
void print_file_error(char * message);

/* Check operation type */
OperationType check_operation_type(char *argv[]);

/* Read and validate Encode args from argv */
Status read_and_validate_encode_args(char *argv[], EncodeInfo *encInfo);

#endif