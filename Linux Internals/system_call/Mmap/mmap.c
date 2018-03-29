#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<sys/wait.h>
#include<sys/types.h>
#include<sys/stat.h>
#include<sys/mman.h>
#include<fcntl.h>
#include<string.h>

int main(int argc,char *argv[])
{
	
	off_t size;
	char *ptr_src,*ptr,*ptr_dest;
	int fd,fd_1,i=0;
	struct stat info;

	/* checking for cli argument validity */
	if(argc!=3)
	{
		printf("Invalid argument sequence!\n");
		printf("Usage : ./a.out <source file> <destination file>\n");
		return 0;
	}
	/* opening source file */
	printf("INFO : Opening source file %s\n",argv[1]);
	fd=open(argv[1],O_RDONLY);
	/* failure */
	if(fd==-1)
	{
		perror("open");
		return 1;
	}
	/* opening destination file and create if non existent file */
	printf("INFO : Opening destination file %s\n",argv[1]);
	fd_1=open(argv[2],O_RDWR|O_CREAT|O_TRUNC,0666);
	/* failure */
	if(fd_1==-1)
	{
		perror("open");
		return 1;
	}

	/* getting size of file */
	fstat(fd,&info);
	size=info.st_size;

	/* seeking to get valid address range for mapping */
	lseek(fd_1,size-1,SEEK_SET);
	/* writing a dummy byte at the end of file */  
	write(fd_1," ",1);


	printf("INFO : Mapping size=%ld\n",info.st_size);
	/* memory mapping source file in read mode */
	printf("INFO : Creating memory map for source file\n");
	ptr_src=mmap(NULL,size,PROT_READ,MAP_SHARED,fd,0);

	/* failure */
	if(ptr_src==(void *)-1)
	{
		perror("mmap");
		return 1;
	}
	
	/* memory mapping destination file in write  mode */
	printf("INFO : Creating memory map for destination file\n");
	ptr_dest=mmap(NULL,size,PROT_WRITE|PROT_READ,MAP_SHARED,fd_1,0);
	/* failure */
	if(ptr_dest==(void *)-1)
	{
		perror("mmap");
		return 1;
	}
	/* copying memory  from source file into destination file */
	printf("INFO : Copying mapped memories\n");
	ptr=memcpy(ptr_dest,ptr_src,size);
	/* failure */
	if(ptr==NULL)
	{
		perror("memcpy");
		return 1;
	}
    
	/* unmapping source memory */
	printf("INFO : Unmapping source memory\n");
	munmap(ptr_dest,size);
    /* unmapping destination memory */
	printf("INFO : Unmapping destination memory\n");
	munmap(ptr_src,size);
	printf("INFO : Copy successful\n");
	printf("INFO : Open %s and %s to confirm\n",argv[1],argv[2]);
	
	/* closing file */
	close(fd);
	close(fd_1);
	return 0;
}
