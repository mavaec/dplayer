#include <stdlib.h>
#include <dirent.h>
#include "definitions.h"

const char *get_filemane_ext(const char *);
bool is_audio_file(char *);


int get_audio_file(char *folder, char *m_file, int pos){ /////////////////////////////////////////
	DIR *dpdf;
	struct dirent *epdf;
	int i = 0;

	if(pos < 0)
		return 1;

	dpdf = opendir(folder);
	//dpdf = opendir("./");
	if (dpdf != NULL){
	   while (epdf = readdir(dpdf)){
	      //printf(" %s \n",epdf->d_name);
	      // std::cout << epdf->d_name << std::endl;
		   if(i == pos){
			   //strcpy(m_file, epdf->d_name);
			   //printf("Ext: %s \n", get_filemane_ext(m_file));
			   if(is_audio_file(epdf->d_name)){
				   strcpy(m_file, epdf->d_name);
				   break;
			   }
			   else
				   i--;
				//   printf("it is audio \n");
			   //else
				 //  printf("it isn't audio \n");


		   }

			   i++;
	   }
	}
	closedir(dpdf);

	if(pos > i)
		return 2;

	return 0;
}

const char *get_filemane_ext(const char *filename){ ///////////////////////////////////////////////
	const char *dot = strrchr(filename, '.');
	if(!dot || dot == filename) return "";
	return dot + 1;
}

bool is_audio_file(char *file){ ///////////////////////////////////////////////////////////////////
	char ext[3];
	strcpy(ext, get_filemane_ext(file));
	//printf("Ext: %s \n", ext);
	if(!strcmp(ext, "wav"))
		return true;
	if(!strcmp(ext, "mp3"))
		return true;

	return false;
}
