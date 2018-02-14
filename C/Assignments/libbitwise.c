/*
 *  functions in bitwise library.
 *      -> int get_nbits(int num, int n);
 *      -> int set_nbits(int num, int n, int val);
 *      -> int get_nbits_from_pos(int num, int n, int pos);
 *      -> int set_nbits_from_pos(int num, int n, int pos, int val);
 *      -> int toggle_bits_from_pos(int num, int n, int pos);
 *      -> void print_nbits(unsigned int num, int n);
 *      -> void print_bits(unsigned int num, int n);
 *
 *      -> int circular_right_shift(int num, int n);
 *      -> int circular_left_shift(int num, int n);
 */

int get_nbits(int num, int n);
int set_nbits(int num, int n, int val);
int get_nbits_from_pos(int num, int n, int pos);
int set_nbits_from_pos(int num, int n, int pos, int val);
int toggle_bits_from_pos(int num, int n, int pos);
void print_nbits(unsigned int num, int n);
void print_bits(unsigned int num, int n);

int circular_right_shift(int num, int n);
int circular_left_shift(int num, int n);