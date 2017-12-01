/* 
 * File:   moviedatabase.h
 * Author: benbriggs
 *
 * Created on October 24, 2016, 12:30 PM
 */
#include "film.h"

#ifndef MOVIEDATABASE_H
#define	MOVIEDATABASE_H

#ifdef	__cplusplus
extern "C" {
#endif
typedef struct MovieNodeStruct
{
  Film* film;  
  struct MovieNodeStruct* next;
}MovieNode;

typedef struct MovieDatabaseStruct
{
    MovieNode* first;
    MovieNode* last;   
}MovieDatabase;

MovieDatabase *movieDatabase_new();
MovieDatabase *fillDatabaseFromFile(MovieDatabase *movieDatabase);
void movieDatabase_free(MovieDatabase *movieDatabase);
void addFilm(MovieDatabase* movieDatabase, Film* film);
void printDatabase(MovieDatabase *movieDatabase);
int movieDatabase_length(MovieDatabase *movieDatabase);
void movieDatabase_sortByYear(MovieDatabase *movieDatabase);
void movieDatabase_sortByLength(MovieDatabase *movieDatabase);
void movieDatabase_sortByCriticRating(MovieDatabase *movieDatabase);
void movieDatabase_printFilmAtIndex(MovieDatabase *movieDatabase, int index);
Film *findHighestRatedFilm(MovieDatabase *movieDatabase);
void findShortestFilmTitle(MovieDatabase *movieDatabase);
MovieDatabase *fillDatabaseWithCatagory(MovieDatabase *fromMovieDatabase, MovieDatabase *toMovieDatabase, char* catagory);

#ifdef	__cplusplus
}
#endif

#endif	/* MOVIEDATABASE_H */

