#include <stdio.h>
#include <stdlib.h>

#define SUCCESS 0
#define FAILURE -1
#define EMPTYLIST -2
#define NOELEMENT -3

typedef int data_t;
typedef struct snode
{
	data_t data;
	struct snode *link;
}SLink;

/* prints the elements in the list
 */
void print_list(SLink *);

/* insert a node at the first
 */
int insert_at_first(SLink **, data_t);

/* insert a node in the last of the list
 */
int insert_at_last(SLink **, data_t);

/* delete a node from the first of the list
 */
int delete_first(SLink **head);

/* delete a node from the last of the list
 */
int delete_last(SLink **head);

/* delete a given node from the list if present
 */
int delete_element(SLink **head, data_t data);

/* delete the list i.e all nodes
 */
int delete_list(SLink **head);

/* insert a node after a given node in the list if present
 */
int insert_after(SLink **head, data_t a_data, data_t n_data);

/* insert a node before a given node in the list if present
 */
int insert_before(SLink **head, data_t b_data, data_t n_data);

/* find a node at a given index in the list if present
 */
int getNth(SLink *head, int index);

/* insert a node at a given index in the list if valid index is given within the list
 */
int insert_Nth(SLink **head, int index, data_t data);

/* find a mid node index in the list 
 */
int find_mid(SLink *);

/* insert a node in the list in sorted manner
 */
int sorted_insert(SLink **head, data_t data);

/* List is changed it to be in sorted order
 */
int insert_sort(SLink **head);

/* append list b to the end of list a
 */
int append(SLink **ahead, SLink **bhead);

/* split the list into half and place first half in a and the other in b
 */
int splithalf(SLink **head, SLink **ahead, SLink **bhead);

/* alternatively split the list into two and place even elements in b and the odd elemenst in a
 */
int split_alternatively(SLink *head, SLink **ahead, SLink **bhead);

/* Remove duplicates from the list and update that list
 */
int remove_duplicate(SLink **head);

/* Merge list a with list b in sorted fashion and return
 */
SLink * merge_sortedlinks(SLink *ahead, SLink *bhead);

/* reverse the list and update that list
 */
int reverse(SLink **head);

/* find length of the list 
 */
int findLength(SLink *head);

/* to find the count of the number of times a given element occurs in a list.
 */
int countKey(SLink *head, data_t data);


