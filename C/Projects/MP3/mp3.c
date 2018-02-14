/*
  This is an example program that shows how to extract MP3 ID3v1 tags.
  It is written in standard ANSI C and can be compiled with any working
  C compiler.


  Author: Nikhil Gautam, 2018-01-14
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define GENRES 148

char *genres[GENRES] = {
  "Blues", "Classic Rock", "Country", "Dance",
  "Disco", "Funk", "Grunge", "Hip-Hop",
  "Jazz", "Metal", "New Age", "Oldies",
  "Other", "Pop", "R&B", "Rap",
  "Reggae", "Rock", "Techno", "Industrial",
  "Alternative", "Ska", "Death Metal", "Pranks",
  "Soundtrack", "Euro-Techno", "Ambient", "Trip-Hop",
  "Vocal", "Jazz+Funk", "Fusion", "Trance",
  "Classical", "Instrumental", "Acid", "House",
  "Game", "Sound Clip", "Gospel", "Noise",
  "AlternRock", "Bass", "Soul", "Punk",
  "Space", "Meditative", "Instrumental Pop", "Instrumental Rock",
  "Ethnic", "Gothic", "Darkwave", "Techno-Industrial",
  "Electronic", "Pop-Folk", "Eurodance", "Dream",
  "Southern Rock", "Comedy", "Cult", "Gangsta",
  "Top 40", "Christian Rap", "Pop/Funk", "Jungle",
  "Native American", "Cabaret", "New Wave", "Psychadelic",
  "Rave", "Showtunes", "Trailer", "Lo-Fi",
  "Tribal", "Acid Punk", "Acid Jazz", "Polka",
  "Retro", "Musical", "Rock & Roll", "Hard Rock",
  "Folk", "Folk/Rock", "National folk", "Swing",
  "Fast-fusion", "Bebob", "Latin", "Revival",
  "Celtic", "Bluegrass", "Avantgarde", "Gothic Rock",
  "Progressive Rock", "Psychedelic Rock", "Symphonic Rock", "Slow Rock",
  "Big Band", "Chorus", "Easy Listening", "Acoustic",
  "Humour", "Speech", "Chanson", "Opera",
  "Chamber Music", "Sonata", "Symphony", "Booty Bass",
  "Primus", "Porn Groove", "Satire", "Slow Jam",
  "Club", "Tango", "Samba", "Folklore",
  "Ballad", "Powder Ballad", "Rhythmic Soul", "Freestyle",
  "Duet", "Punk Rock", "Drum Solo", "A Capella",
  "Euro-House", "Dance Hall", "Goa", "Drum & Bass",
  "Club House", "Hardcore", "Terror", "Indie",
  "BritPop", "NegerPunk", "Polsk Punk", "Beat",
  "Christian Gangsta", "Heavy Metal", "Black Metal", "Crossover",
  "Contemporary C", "Christian Rock", "Merengue", "Salsa",
  "Thrash Metal", "Anime", "JPop", "SynthPop"
};

int main(int argc, char **argv) {
    int i;
  /* 128 bytes needed for raw ID3 data */
        char id3[128];
        char buff[128];
        if(argc == 1)
        {
            printf("ERROR: ./mp3_tag_reader.out: Invalid Arguments\n");
            printf("USAGE: ./mp3_tag_reader.out: -h for help\n");
            return 0;

        }

        if (!strcmp(argv[1], "-h"))
        {
            printf("Help Menu for the MP3 TAG Reader and Editor\n\n");
            printf("For viewing the tags-   ./mp3_tag_reader -v <.mp3 file name> \n\n");
            printf("For editing the tags-   ./mp3_tag_reader -e <.mp3 file name> <Modifier> <tag> \n\n");;
            printf("\n\tModifier\tFunction\n");
            printf("\t-t\t        Title Tag\n");
            printf("\t-a\t        Artist Tag\n");
            printf("\t-A\t        Album Tag\n");
            printf("\t-y\t        Year Tag\n");
            printf("\t-c\t        Comment Tag\n");
            printf("\t-g\t        Genre Tag\n");
            exit(EXIT_SUCCESS);
        }

   /*Opening the file and it is in read mode for viewing it
    and checking it is opened*/

        {
      FILE *fp = fopen(argv[2], "r");

      if (!fp)
        {
            printf("Couldn't open file %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
     /* Read last 128 bytes of the file, if we can*/


      if (fseek(fp, -128, SEEK_END) || fread(id3, 128, 1, fp) != 1)
        {
            printf("Couldn't jump/read in file %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
    fclose(fp);
        }
      /* Now we have read the last 128 bytes and it's time to see if we
	 have some ID3 there or not. A valid ID3 tag has the characters
	 'T', 'A', and 'G' as its 3 identifying characters. */

    if (!strcmp(argv[1], "-v"))
      {

          if (strncmp(id3, "TAG", 3))
        {
            printf("File \"%s\" doesn't have an ID3 tag\n\n", argv[i]);
        }
            else
            {

        unsigned char *s = id3+3;
        char title_p[31];
        char artist_p[31];
        char album_p[31];
        char year_p[5];
        char comment_p[31];
        char genre_p[31];

	/* Id3 tag elements don't necessarily end in a '\0' if they
	   occupy the full 30 character space. Thus, we'll have to
	   nul-terminate all strings just to be sure. */

	strncpy(title_p, s, 30);
	title_p[30] = '\0';
	s += 30;

	strncpy(artist_p, s, 30);
	artist_p[30] = '\0';
	s += 30;

	strncpy(album_p, s, 30);
	album_p[30] = '\0';
	s += 30;

	strncpy(year_p, s, 4);
	year_p[4] = '\0';
	s += 4;

	strncpy(comment_p, s, 30);
	comment_p[30] = '\0';
	s += 30;

	/* The genre field is not encoded as a string, but just one byte
	   that indexes the decoding tabl(!strcmp(argv[1], "-v"))e. If memory is too expensive,
	   the whole field may be ignored or just shown as a number. */
	if (*s >= GENRES)
	  strcpy(genre_p, "Unknown");
	else
	  strcpy(genre_p, genres[*s]);

	/* And now the final printing */
	printf("\nMP3 TAG Reader And Editor\n");
	printf("-------------------------\n\n");
	printf("Version ID\t:\t2.3\n");

	printf("Title\t\t:\t%-30s\nArtist\t\t:\t%s\n", title_p, artist_p);
	printf("Album\t\t:\t%-30s\nYear\t\t:\t%s\n", album_p, year_p);
	printf("Comment\t\t:\t%-30s\nGenre\t\t:\t%s\n\n", comment_p, genre_p);
      }
    return 0;

    }

    /*end of viewing part*/

if (!strcmp(argv[1], "-e"))
{
    char title[30];
    char *p;
    char artist[30];
    char album[30];
    char year[4];
    char comment[30];
    char genre[30];
   FILE *fp2 = fopen(argv[2], "r+");

      if (!fp2)
        {
            printf("Couldn't open file %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
     /* Read last 128 bytes of the file, if we can*/


      if (fseek(fp2, -125, SEEK_END))
        {
            printf("Couldn't jump/read in file %s\n", argv[2]);
            exit(EXIT_FAILURE);
        }
        for (i=1; i<argc; i++)
        {
            if (!strcmp(argv[i], "-t"))
                  {
                    p=(argv[4]);
                    for(i=0;i<strlen(p);i++)
                    {
                         title[i]= p[i];
                    }
                    title[i]='\0';
                    fwrite(title,30,1,fp2);
                    printf("Title Modification done\n");
                    return 0;
                    }

            if (!strcmp(argv[i], "-a"))
                {
                    fseek(fp2, -95,SEEK_END);
                    p=(argv[4]);
                    for(i=0;i<strlen(p);i++)
                    {
                         artist[i]=p[i];
                    }
                    artist[i]='\0';
                    fwrite(artist,30,1,fp2);
                    printf("Artist Modification done\n");
                    return 0;
                }

        if (!strcmp(argv[i], "-A"))
                {
                    fseek(fp2, -65,SEEK_END);
                    p=(argv[4]);
                    for(i=0;i<strlen(p);i++)
                    {
                         album[i]=p[i];
                    }
                    album[i]='\0';
                    fwrite(album,30,1,fp2);
                    printf("Album Modification done\n");
                    return 0;
                }
            if (!strcmp(argv[i], "-y"))
                {
                      fseek(fp2, -35,SEEK_END);
                    p=(argv[4]);
                    for(i=0;i<strlen(p);i++)
                    {
                         year[i]=p[i];
                    }
                    year[i]='\0';
                    fwrite(year,4,1,fp2);
                    printf("Year Modification done\n");
                    return 0;
                }
            if (!strcmp(argv[i], "-c"))
                {
                    fseek(fp2, -31,SEEK_END);
                    p=(argv[4]);
                    for(i=0;i<strlen(p);i++)
                    {
                         comment[i]=p[i];
                    }
                    comment[i]='\0';
                    fwrite(comment,30,1,fp2);
                    printf("Comment Modification done\n");
                    return 0;
                }
            if (!strcmp(argv[i], "-g"))
            {
                    fseek(fp2, -1,SEEK_END);
                    p=(argv[4]);
                    for(i=0;i<strlen(p);i++)
                    {
                        genre[i]=p[i];
                    }
                    genre[i]='\0';
                    fwrite(genre,1,1,fp2);
                    printf("Genre Modification done\n");
                    return 0;
            }

        }

}
  return 0;

}
