/*
 ============================================================================
 Name        : mpd_test.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
//#include <dirent.h>

int main(void) {
	//puts("!!!Hello World!!!"); /* prints !!!Hello World!!! */
	//char music_folder[] = "/home/mauricio/Música/";
	char music_folder[] = "/media/mauricio/SEAGATE/01 MUSICA/Blues/Eric Clapton/Unplugged/";
	char music_file[256] = "test";
/*	DIR *dpdf;
	struct dirent *epdf;


	dpdf = opendir("/home/mauricio/Música/");
	//dpdf = opendir("./");
	if (dpdf != NULL){
	   while (epdf = readdir(dpdf)){
	      printf("Filename: %s \n",epdf->d_name);
	      // std::cout << epdf->d_name << std::endl;
	   }
	}
	closedir(dpdf);
*/

	get_audio_file(&music_folder, &music_file, 3);
	printf("Filename: %s \n",music_file);
	printf("%i \n", get_audio_file(&music_folder, &music_file, 6));
/*
	char c;
	c = getchar();

	while(c != 'e')
	{
		putc(c,stdout);

		switch(c){
			case 'a':
				system("mpc play");
				break;
			case 'b':
				system("mpc stop");
				break;

		}

		c = getchar();

	}
*/
	return EXIT_SUCCESS;
}
