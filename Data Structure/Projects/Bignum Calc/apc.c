#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct node
{

int data;
struct node *next, *prev;

}Dlist_t;

void slice(char *expression, Dlist_t **var1, Dlist_t **var2);
Dlist_t *apc_evaluation_sum(Dlist_t **var1, Dlist_t **var2, char operator);
Dlist_t *apc_evaluation_mul(Dlist_t **var1, Dlist_t **var2, char operator);
void apc_evaluation_power(Dlist_t **var1, Dlist_t **var2);
int apc_evaluation_div(Dlist_t **var1, Dlist_t **var2, char operator);
int check_greater(Dlist_t **var1, Dlist_t **var);
Dlist_t *dl_create_node(int val);
void dl_insert_first(Dlist_t **head, int val);
void dl_insert_last(Dlist_t **head, int val);
void dl_insert_after(Dlist_t **head,int element, int val);
void dl_insert_before(Dlist_t **head,int element, int val);
void dl_insert_nth(Dlist_t **head,int pos, int val);
void dl_print_list(Dlist_t *head);
void dl_delete_first(Dlist_t **head);
void dl_delete_last(Dlist_t **head);
void dl_delete_node(Dlist_t **head, int val);
void dl_delete_list(Dlist_t **head);

int main()
{

char expression[1024];
Dlist_t *var1 = NULL, *var2 = NULL;
scanf("\n%[^\n]", expression);
slice(expression, &var1, &var2);
}






/*-----------------------------------------------------------------------------------------------------------------------*/
/*slicing the function block*/
void slice(char *expression, Dlist_t **var1, Dlist_t **var2)
{

	/*local variable declaration*/
	int idx = strlen (expression) - 1;
	char operator, buff[4] = {'0' , '0', '0', '0'};
	int slice_flag = 0, op_flag = 0, sum = 0;
	int jdx = 3, minus_flag = 0, high_flag;
	Dlist_t *Result = NULL;

	while (idx >= 0)
	{

		if (idx == 0)
		{
			if ( expression[idx] == '-')
			{
				minus_flag = 1;
				break;
			}
		}
		/*if the character is not an operator*/
		if (expression[idx] != '+' &&expression[idx] != '-' && expression[idx] != '*' && expression[idx] != '/' && expression[idx] != '%' && expression[idx] != '^')
		{
			if (slice_flag == 4)
			{

				/*performing atoi on variable 1*/
				if (op_flag == 0)
				{
					sum = atoi(buff);
					dl_insert_first(var1, sum);
				}

				/*performing atoi on variable 2*/
				if (op_flag == 1)
				{
					sum = atoi(buff);
					dl_insert_first(var2, sum);
				}

				slice_flag = 0;

				/*moving 4 characters in to a buffer*/
				for (jdx = 0; jdx < 4; jdx++)
					buff[jdx] = '0';

				jdx = 3;

			}

			buff[jdx] = expression[idx];
			--jdx;
			++slice_flag;

		}

		/*if the character is an operator*/
		else
		{

			if (slice_flag != 0)
			{
				sum = atoi(buff);
				dl_insert_first(var1, sum);
			}

			operator = expression[idx];
			op_flag = 1;
			slice_flag = 0;

			for (jdx = 0; jdx < 4; jdx++)
				buff[jdx] = '0';

			jdx = 3;
		}

		--idx;
	}

	sum = atoi(buff);
	dl_insert_first(var2, sum);
/*
	/*printing var1

	("\nvar1 : ");
	dl_print_list(*var2);

	/*printing var2
	printf("\nvar2 : ");
	dl_print_list(*var1);
*/
	/*calling addition function block for + and - operators*/
	if (operator == '+' || operator == '-')

	{

		/*if op is -, check for greater num and swap*/
		if (operator == '-')
		{
			high_flag = check_greater(var1, var2);
			//printf("\nhigh = %d\n", high_flag);
		}

		Result = apc_evaluation_sum(var1, var2, operator);

		if (operator == '+')
			printf("\nResult = ");

		if (operator == '-')
		{

			/*if the 1st num is less than 2nd num, print - sign*/
			if (high_flag == 1)
				printf("\nResult = -");

			else
				printf("\nResult = ");

		}

		dl_print_list(Result);
		printf("\n");
	}

	/*if the operator is "*"*/
	if (operator == '*')
	{
		Result = apc_evaluation_mul(var1, var2, operator);
		printf("\nResult : ");
		dl_print_list(Result);
	}

	/*if the operator is "/"*/
	if (operator == '/')
	{
		int count = apc_evaluation_div(var1, var2, operator);
		printf("\nResult is %d\n", count);
	}

	/*if the operator is "%"*/
	if (operator == '%')
	{
		apc_evaluation_div(var1, var2, operator);
	}

	/*if the operator is "^"*/
	if (operator == '^')
	{
		apc_evaluation_power(var1, var2);
	}
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*power function block*/
void apc_evaluation_power(Dlist_t **var1, Dlist_t **var2)
{

	/*local variable declaration*/
	Dlist_t *ptr1 = *var1, *Result = *var2;

	/*repetitive multiplication*/
	while (ptr1->data - 1)
	{

		Result = apc_evaluation_mul(var2, &Result, '*');
		ptr1->data = ptr1->data - 1;

	}

	printf("\nResult : ");
	dl_print_list(Result);
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*check greater function block*/
int check_greater(Dlist_t **var1, Dlist_t **var2)
{

	/*local variable declaration*/
	Dlist_t *ptr1 = *var1, *ptr2 = *var2;
	int count1 = 0, count2 = 0, high_flag = 0, idx, flag = 0;

	/*count number of nodes in list1*/
	while (ptr1 != NULL)
	{
		++count1;
		ptr1 = ptr1->next;
	}

	/*count number of nodes in list2*/
	while (ptr2 != NULL)
	{
		++count2;
		ptr2 = ptr2->next;
	}

	ptr1 = *var1;
	ptr2 = *var2;

	/*if the count2 is greater than count1*/
	if (count2 > count1)
	{

		/*if the number in the first node is 0*/
		if (ptr2->data == 0)
		{
			while (ptr2 != NULL)
			{

				if (ptr2->data == 0)
				{
					--count2;
					ptr2 = ptr2->next;
				}

				else
				{
					if (ptr2->data < ptr1->data && count2 == count1)
						flag = 1;
					break;

				}
				if (count2 == 0)
					flag = 1;

			}
		}

		/*swapping the numbers*/
		if (flag == 1)
		{
			Dlist_t *tmp = *var1;
			*var1 = *var2;
			*var2 = tmp;
			high_flag = 1;
		}

	}

	/*if the number of nodes are equal in both the nodes*/
	else if (count1 == count2)
	{
		Dlist_t *tmp1 = *var1, *tmp2 = *var2;

		if (tmp2->data <= tmp1->data)
		{
			while(tmp2->data >= tmp1->data && tmp1->next != NULL)
			{
				tmp1 = tmp1->next;
				tmp2 = tmp2->next;
			}

			/*swapping the numbers*/
			if (tmp1->next != NULL && tmp2->data < tmp1->data)
			{
				Dlist_t *tmp = *var1;
				*var1 = *var2;
				*var2 = tmp;
				high_flag = 1;
			}

			/*swapping the numbers*/
			else if (tmp1->next == NULL && tmp2->data < tmp1->data)
			{

				Dlist_t *tmp = *var1;
				*var1 = *var2;
				*var2 = tmp;
				high_flag = 1;
			}
		}

	}
	return high_flag;
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*division function block*/
int apc_evaluation_div(Dlist_t **var1, Dlist_t **var2, char operator)
{

	/*local variable declatation*/
	unsigned long long int count = 0;
	int  flag = 0;
	int high_flag, idx = 0, stop = 0;
	Dlist_t *diff = NULL, *Result = NULL, *copy = NULL, *temp_var2 = *var2;
	Dlist_t *ptr = NULL;
	high_flag = check_greater(var1, var2);

	while (1)
	{
		/*if the divisor is greater than the dividend*/
		if (flag == 0)
		{

			if (high_flag == 1)
			{
				flag = 2;
				break;
			}

			flag = 1;
		}

		/*repetitively performing the subtraction*/
		Result = apc_evaluation_sum(var1, &temp_var2, '-');

		/*repetitive subtraction is stopped when the remainder goes less than the divisor*/
		stop = check_greater(var1, &Result);

		if (stop == 0)
		{

			/*keep count on subtraction*/
			++count;
			printf("%lld\n", count);

			/*deleting the list not needed*/
			dl_delete_list(&temp_var2);
			temp_var2 = Result;
		}

		else
		{
			break;
		}
	}

	/*if the operator is %, print the result*/
	if (operator == '%')
	{
		printf("\nRemainder is ");

		dl_print_list(*var1);

		printf("\n");
	}

	/*if the operator is /, print the count*/
	if (operator == '/')
	{
		if (flag == 2)
		{
			return 0;
		}

		else
			return count + 1;
	}
}
/*-----------------------------------------------------------------------------------------------------------------------*/
/*multiplication function block*/
Dlist_t *apc_evaluation_mul(Dlist_t **var1, Dlist_t **var2, char operator)
{

	/*local variable declaration*/
	Dlist_t *Result1 = NULL, *Result2 = NULL, *ptr1 = *var1, *ptr2 = *var2, *last;
	int idx = 0, carry = 0, result, num, sum, flag = 0, jdx;

	dl_insert_first(&Result2, 0);

	/*moving the pointer to the last node*/
	while(ptr1->next != NULL)
	{
		ptr1 = ptr1->next;
	}


	/*moving the pointer to the last node*/
	while(ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}

	last = ptr2;

	while (ptr1 != NULL)
	{

		while (ptr2 != NULL)
		{

			/*appending zeros*/
			if (ptr2->next == NULL)
			{
				for (jdx = 0; jdx < (idx); jdx++)
				{
					dl_insert_first(&Result1, 0);
				}
			}

			/*performing multiplication*/
			result = (ptr1->data * ptr2->data) + carry;

			flag = 0;


			/*checking for over flow*/
			if (result > 9999)
			{
				num = result;
				result = num % 10000;
				carry = num / 10000;
				flag = 1;
			}

			if (flag == 0)
				carry = 0;

			dl_insert_first(&Result1, result);

			ptr2 = ptr2->prev;

		}

		if (carry != 0)
		{
			dl_insert_first(&Result1, carry);

		}

		/*calling addition function block*/
		Result2 = apc_evaluation_sum(&Result1, &Result2, '+');
		Result1 = NULL;
		ptr1 = ptr1->prev;
		ptr2 = last;
		carry = 0;
		++idx;
	}


	return Result2;
}

/*-----------------------------------------------------------------------------------------------------------------------*/
/*function block for addition and subtraction*/
Dlist_t *apc_evaluation_sum(Dlist_t **var1, Dlist_t **var2, char operator)
{

	/*local variable declaration*/
	Dlist_t *Result = NULL;
	Dlist_t *ptr1 = *var1, *ptr2 = *var2, *ptr = NULL;
	int carry_flag = 0, result, idx = 0;

	/*point the pointer to the last node, that is where the operation should be started from*/
	while(ptr1->next != NULL)
	{

		/*if the operator is "-", take 2's complement of the number*/
		if (operator == '-')
		{
			ptr1->data = ~(ptr1->data) + 1;
		}

		ptr1 = ptr1->next;

	}

	/*2's complement of the last node*/
	if (operator == '-')
	{
		ptr1->data = ~(ptr1->data) + 1;
	}

	if ( ptr2 == *var2 && ptr2->data < 0)
	{
		ptr2->data = ptr2->data * -1;
	}

	/*move the pointer to the last node*/
	while(ptr2->next != NULL)
	{
		ptr2 = ptr2->next;
	}

	if (operator == '+' || operator == '-')
	{
		while (ptr1 != NULL || ptr2 != NULL)
		{
			if (ptr1 != NULL && ptr2 != NULL)
			{

				/*if the number to be subtracted from is smaller take care of borrow*/
				if (operator == '-' && ptr2 != *var2 && ptr2->data < (ptr1->data * -1))
				{
					ptr = ptr2;

					/*take borrow from node which is not zero*/
					while (ptr->prev->data == 0 && ptr != NULL)
					{
						ptr = ptr->prev;

						if (ptr == *var2)
						{
							break;
						}
					}

					if (ptr != NULL)
					{

						if (ptr != *var2)
							ptr = ptr->prev;

						ptr->data = ptr->data - 1;

						ptr = ptr->next;

						while (ptr != ptr2)
						{
							ptr->data = ptr->data + 10000 - 1;
							ptr = ptr->next;
						}
						ptr->data = ptr->data + 10000;
					}
				}
				result = ptr1->data + ptr2->data + carry_flag;
			}

			/*if there are no nodes available in list1*/
			else if (ptr1 == NULL && ptr2 != NULL)
			{
				result = ptr2->data + carry_flag;
			}

			/*if there are no nodes available in list2*/
			else if (ptr2 == NULL && ptr1 != NULL)
				result = ptr1->data + carry_flag;

			carry_flag = 0;
			/*checking the node for over flow*/
			if (result > 9999)
			{
				carry_flag = 1;
				result = result - 10000;
			}

			dl_insert_first(&Result, result);

			if (ptr1 != NULL)
				ptr1 = ptr1->prev;

			if (ptr2 != NULL)
				ptr2 = ptr2->prev;

		}

	}

	/*if there is a carry from the last node*/
	if (carry_flag == 1 && operator == '+')
	{
		dl_insert_first(&Result, 1);
	}

	if (operator == '-')
	{
		ptr = Result->next;
		while(ptr!= NULL)
		{
			if (ptr->data < 0)
				ptr->data = ptr->data * -1;

			ptr = ptr->next;
		}

		ptr1 = *var1;

		/*reversing the 2's complement done*/
		while(ptr1 != NULL)
		{
			if (operator == '-')
			{
				ptr1->data = ~(ptr1->data) + 1;
			}

			ptr1 = ptr1->next;

		}

	}
	/*returning the result*/
	return Result;

}


void dl_print_list(Dlist_t *head)

{
	Dlist_t *temp = head;

	while(temp)
	{
		printf("%d ", temp -> data);
		temp = temp -> next;
	}
	printf("\n");
}


void dl_delete_list(Dlist_t **head)
{
	/* take a local reference of head */
	Dlist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}
	/* iterate through the list and delete from the head till the tail */
	else
	{

		while(temp -> next)
		{

			dl_delete_first(&temp);
		}
		// update the linked list as empty list
		(*head) = NULL;


		return ;
	}
	return ;

}


void dl_insert_first(Dlist_t **head, int data)
{
	Dlist_t *new = malloc(sizeof(Dlist_t));

	Dlist_t *temp;
	temp = (*head);

	if (NULL == new)
	{
		return ;
	}

	//update newnode data and links
	new -> data = data;
	new -> prev = NULL;
	new -> next = NULL;

	//if list is empty
	if ( NULL == (*head))
	{
		(*head) = new;
		return;
	}

	//if non empty list
	temp -> prev = new;
	new -> next = temp;
	(*head) = new;

	return ;
}

void dl_delete_first(Dlist_t **head)
{
	/* take a local reference of head */
	Dlist_t *temp;
	temp = *head;

	/* check for if list is empty */
	if (NULL == (*head))
	{
		return ;
	}

	/* check for if list has only one node */
	if ( ((*head) -> next) == NULL)
	{
		/* free the node, and update head with null */
		free(*head);
		(*head) = NULL;
		return ;
	}
	else
	{
        /* if list has multiple nodes then, update head and free the first node */
		(*head) = ((*head) -> next);
        /* update the head -> prev to null */
        (*head) -> prev = NULL;
		free(temp);
		return ;
	}

	return ;
}



