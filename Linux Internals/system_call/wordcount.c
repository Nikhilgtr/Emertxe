#include "syscalls.h"

int main(int argc, char **argv)
{
	int i;
	int c, index = 0 ;
	extern int optind, optopt;
	extern char *optarg;

	//get the flags using getopt and set the flags accordingly
	while ((c = getopt (argc, argv, "clwn:")) != -1)
	{
		switch (c)
      		{
			case 'l':
				line_flag = 1;
				break;
			case 'w':
				word_flag = 1;
				break;
			case 'c':
				char_flag = 1;
				break;
			case '?':
				fprintf (stderr, "Unknown option `-%c'.\n", optopt);
				return -1;
		}
	}

	//if no files are given read from stdin
	if(argv[optind] == NULL)
	{
		int fd = dup(0);
        	//read from stdin and get the word count
		ccount = 0;
		wcount = 0;
		lcount = 0;

		/* to get the word count */
		word_count(fd, &lcount, &wcount, &ccount);

		/* close the fd */
		close(fd);

		/* print the file and respective word counts */
		print_report("stdin", lcount, wcount, ccount, line_flag, word_flag, char_flag);

	}
	else
	{
		//for multiple file cases
		for (i = optind; i < argc; i++)
		{
			index++;
			if (process_word_count(argv[i]) == FAILURE)
			{
				printf("processing the file failed.\n");
				return -1;
			}
		}

		/* print the file and respective word counts */
		if (index > 1)
		{
			print_report("total ", total_lcount, total_wcount, total_ccount,0,0,0);
		}
	}

}

// to process words i.e to open the file, get the word count, and then print accordingly
int process_word_count(char *pathname)
{
	int fd;

	/* To open file to read */
	if ( (fd = open(pathname, O_RDONLY)) == -1 )
	{
		perror("open");
		return FAILURE;
	}
	ccount = 0;
	wcount = 0;
	lcount = 0;

	/* to get the word count */
	word_count(fd, &lcount, &wcount, &ccount);

	/* close the fd */
	close(fd);

	/* print the file and respective word counts */
	print_report(pathname, lcount, wcount, ccount, line_flag, word_flag, char_flag);

	total_ccount += ccount;
      	total_wcount += wcount;
       	total_lcount += lcount;
}


// to get the word count, line count and bytes count
int word_count(int fd, int *lines, int *words, int *bytes)
{
	int read_len = 0, temp_line = 0, temp_words = 0, i, sp ;
	char buff[BUFF_SIZE];

	while( ((read_len = read(fd, buff, BUFF_SIZE)) != -1 ) && (read_len != 0))
	{
		// number of characters
		*bytes = read_len;

		// number of lines and words
		for(i = 0; i < read_len; i++)
		{
			//to get lines
			if(buff[i] == '\n')
			{
				temp_line++;
			}

			//to get words
			if(buff[i] == ' ' || buff[i] == '\n') sp = 1;
        		else if(sp)
			{
       	    			++temp_words;
			        sp = 0;
		        }
		}

	}
	*lines = temp_line;
	*words = temp_words;
}

//print the report depending on the flags set
void print_report(char *pathname, int lines, int words, int bytes, int l_flag, int w_flag, int c_flag)
{
	//check for flag outputs

	if (line_flag == 1)
	{
		if (word_flag == 1)
		{
			if (char_flag == 1)
			{
				//if all flags are set
				printf ("%d %3d %3d %s\n", lines, words, bytes, pathname);
			}
			else
			{
				//if -l and -w is set
				printf ("%d %3d %s\n", lines, words, pathname);
			}
		}
		else if (char_flag == 1)
		{
			// if -l and -c is set
			printf ("%d %3d %s\n", lines, bytes, pathname);
		}
		else
		{
			//if -l is set
			printf ("%d %s\n", lines, pathname);
		}
	}
	else if (word_flag == 1)
	{
		if (char_flag == 1)
		{
			//if -w and -c is set
			printf ("%d %3d %s\n", lines, bytes, pathname);

		}
		else
		{
			//if -w is set
			printf ("%d %s\n", words, pathname);
		}
	}
	else if (char_flag == 1)
	{
		//if -c is set
		printf ("%d %s\n", bytes, pathname);
	}
	else
	{
		//if none are set
		printf ("%d %3d %3d %s\n", lines, words, bytes, pathname);
	}

}
