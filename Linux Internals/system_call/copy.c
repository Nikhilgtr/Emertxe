
#include "syscalls.h"

int main(int argc, char *argv[])
{
	int fd, fd2,fd3, read_len;
	char choice;

	//for -p to copy the permission mode
	struct stat sb;

	/* Do arg count check */
    	if (argc < 3)
    	{
        	printf("Insufficient arguments\n");
	      	printf("Usage:- ./my_copy [option] <source file> <destination file> \n");
        	return 1;
    	}

	/* check for -p permissions */
	if (strcmp(argv[1], "-p") == 0 )
	{
		printf("Permissions also copied from source file to destination file.\n");
		/* To open source.txt to read */
		if ( (fd = open(argv[2], O_RDONLY)) == -1 )
		{
			perror("open");
			return -1;
		}

		//get the permission of this file
		//stat(argv[2], &sb);
		if (stat(argv[2], &sb) )
		{
			perror("stat");
			return -1;
		
			fd3=open(argv[3],O_RDONLY);

        /* To create/ open dest.txt to copy the data */
		if ( fd3 != -1)
        {
            close(fd3);

            printf("File %s is already exists.\n Do you want to overwrite (y/n): ", argv[3]);
			scanf("\n%c", &choice);

			if(choice == 'n' || choice == 'N')
			{
				return 0;
			}
			else if (choice == 'y' || choice == 'Y')
			{
				//for overwriting
				if ( (fd2 = open(argv[3], O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1 )
				{
					perror("open");
					return -1;
		0		}
			}
            //change the permisions
            if (chmod(argv[3], sb.st_mode & 07777))
    		{
        		perror("chmod");
                return -1;
    		}

        }
        else
        {
            close(fd3);
            if ( (fd2 = open(argv[3], O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1 )
				{
					perror("open");
					return -1;
				}
        }
	}
	else
    {

		/* To open source.txt to read */
		if ( (fd = open(argv[1], O_RDONLY)) == -1 )
		{
			perror("open");
			return -1;
		}
            fd3=open(argv[2],O_RDONLY);
		/* To create/ open dest.txt to copy the data */
		if ( fd3 != -1 )
		{    close(fd3);
			printf("File %s is already exists.\n Do you want to overwrite (y/n): ", argv[2]);
			scanf("\n%c", &choice);

			if(choice == 'n' || choice == 'N')
			{
				return 0;
			}
			else if (choice == 'y' || choice == 'Y')
			{
				//for overwriting
				if ( (fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1 )
				{
					perror("open");
					return -1;
				}
			}

		}
        else
        {
            close(fd3);
            if ( (fd2 = open(argv[2], O_WRONLY|O_CREAT|O_TRUNC, 0666)) == -1 )
				{
					perror("open");
					return -1;
				}
        }

    }

    my_copy(fd, fd2);

	close(fd);
	close(fd2);

	return 0;
}


int my_copy(int source_fd, int dest_fd)
{
	int read_len = 0;
	char buff[BUFF_SIZE];

	//read the data from the source.txt till end and copy
	while( ((read_len = read(source_fd, buff, BUFF_SIZE)) != -1 ) && (read_len != 0))
	{
		if( write(dest_fd, buff, read_len) == -1 )
		{
			perror("write");
			close(source_fd);
			close(dest_fd);
			return -1;
		}
	}

	return 0;
}

