#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "moviedatabase.h"
#include "film.h"

MovieDatabase *movieDatabase_new(){
   MovieDatabase *movieDatabase = (MovieDatabase*)malloc(sizeof(MovieDatabase*));
    
   if (movieDatabase == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate memory in list_new()\n");
      
      exit(EXIT_FAILURE);
   }
   
   movieDatabase->first = NULL;
   movieDatabase->last  = NULL;
   
   return movieDatabase; 
}

void addFilm(MovieDatabase* movieDatabase, Film* film)
{
   MovieNode* movieNode = (MovieNode*)malloc(sizeof(MovieNode));
   
   if (movieNode == NULL)
   {
      fprintf(stderr, "Error: Unable to allocate memory in list_add()\n");
      
      exit(EXIT_FAILURE);
   }
   
   movieNode->film = film;
   movieNode->next  = NULL;
    
   if (movieDatabase->last == NULL)
   {
      movieDatabase->first = movieDatabase->last = movieNode;
   }
   else
   {
      movieDatabase->last = movieDatabase->last->next = movieNode;  
   }
}

int movieDatabase_length(MovieDatabase *movieDatabase)
{
   int length = 0;
    
   for (MovieNode* node = movieDatabase->first; node != NULL; node = node->next)
   {
       length++;
   }
    
   return length;
}

void movieDatabase_sortByYear(MovieDatabase *movieDatabase){
   if (movieDatabase->first != movieDatabase->last)   // list contains two or more items
   {
      int sorted;
      
      do
      {
         sorted = 1; 
         
         for (MovieNode* node=movieDatabase->first; node->next!=NULL; node=node->next)
         {
            if (node->film->year > node->next->film->year)
            {
               Film *temp           = node->film;
               node->film         = node->next->film;
               node->next->film   = temp;
               sorted             = 0;
            }
         }
      }
      while (!sorted);
   }
}

void movieDatabase_sortByLength(MovieDatabase *movieDatabase){
   if (movieDatabase->first != movieDatabase->last){
      int sorted;
      
      do{
         sorted = 1; 
         
         for (MovieNode* node=movieDatabase->first; node->next!=NULL; node=node->next){       
            if (node->film->runtime < node->next->film->runtime){
               Film *temp          = node->film;
               node->film          = node->next->film;
               node->next->film    = temp;
               sorted              = 0;
            }
         }
      }
      while (!sorted);
   }
}

void movieDatabase_sortByCriticRating(MovieDatabase *movieDatabase){
   if (movieDatabase->first != movieDatabase->last){
      int sorted;
      
      do{
         sorted = 1; 
         
         for (MovieNode* node=movieDatabase->first; node->next!=NULL; node=node->next){             
            if (node->film->criticRating < node->next->film->criticRating){
               Film *temp           = node->film;
               node->film            = node->next->film;
               node->next->film      = temp;
               sorted                = 0;
            }
         }
      }
      while (!sorted);
   }
}

void movieDatabase_printFilmAtIndex(MovieDatabase *movieDatabase, int index){
    int i = 0;
    for (MovieNode *node = movieDatabase->first; node != NULL; node = node->next){
        if(i == index){
            film_printf(node->film);
        }
        i++;
    }
}

Film *findHighestRatedFilm(MovieDatabase *movieDatabase){
    Film *highestRatedFilm = (Film*)malloc(sizeof(Film));
    for (MovieNode *node = movieDatabase->first; node != NULL; node = node->next){
        if(highestRatedFilm->criticRating < node->film->criticRating){
            highestRatedFilm = node->film;
        }
    }
    return highestRatedFilm;
}

void findShortestFilmTitle(MovieDatabase *movieDatabase){
    Film *shortestTitledFilm = (Film*)malloc(sizeof(Film));
    shortestTitledFilm = movieDatabase->first->film;
    for (MovieNode *node = movieDatabase->first; node != NULL; node = node->next){
        
        if(strlen(shortestTitledFilm->title) > strlen(node->film->title)){
                shortestTitledFilm = node->film;
                
        }
    }
    film_printf(shortestTitledFilm);
    film_free(shortestTitledFilm);
}

MovieDatabase *fillDatabaseWithCatagory(MovieDatabase *fromMovieDatabase, MovieDatabase *toMovieDatabase, char* catagory){
    for (MovieNode *node = fromMovieDatabase->first; node != NULL; node = node->next){
        if(strstr(node->film->catagory, catagory) != NULL){
            addFilm(toMovieDatabase, node->film);
        }
    }
    
    return toMovieDatabase;
}

MovieDatabase *fillDatabaseFromFile(MovieDatabase *movieDatabase){
    Film *film;
          
    FILE *input = fopen("films.txt", "r");
    char buf[2000];
    
    if (input == NULL){
        printf("Error: unable to open ‘albums.txt’ in mode ’r’\n");
        exit(EXIT_FAILURE);
    }

    while (fgets(buf,1000, input)){        
        film = bufferToFilm(buf);
        addFilm(movieDatabase, film);
    }
    film_free(film);
    return movieDatabase;
}

void movieDatabase_free(MovieDatabase *movieDatabase){
    free(movieDatabase);
}

void printDatabase(MovieDatabase *movieDatabase){
    for (MovieNode *node = movieDatabase->first; node != NULL; node = node->next){
       film_printf(node->film);
    }
}
