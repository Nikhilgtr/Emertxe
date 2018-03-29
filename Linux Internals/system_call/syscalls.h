#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


#define BUFF_SIZE 255
#define SUCCESS 0
#define FAILURE -1

int my_copy(int source_fd, int dest_fd);
int word_count(int fd, int *lines, int *words, int *bytes);
int line_flag = 0, word_flag = 0, char_flag = 0;

typedef int count_t;
count_t ccount;
count_t wcount;
count_t lcount;

count_t total_ccount =0;
count_t total_wcount =0;
count_t total_lcount =0;


int process_word_count(char *pathname);
//void print_report(char *pathname, int lines, int words, int bytes);
void print_report(char *pathname, int lines, int words, int bytes, int l_flag, int w_flag, int c_flag);

