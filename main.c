/* 
 * File:   main.c
 * Author: benbriggs
 *
 * Created on October 24, 2016, 12:24 PM
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "film.h"
#include "moviedatabase.h"
/*
 * 
 */

void custom_strcat(char *s, char *t);

int main(int argc, char** argv) {
    MovieDatabase *movieDatabase = movieDatabase_new();
    MovieDatabase *noirMovieDatabase = movieDatabase_new();
    MovieDatabase *sciFiMovieDatabase = movieDatabase_new();
    
    //Task #1
    printf("Task 1: \n\n");
    movieDatabase = fillDatabaseFromFile(movieDatabase);
//    movieDatabase_sortByYear(movieDatabase);
//    printDatabase(movieDatabase);
    
    //Task #2
    printf("Task 2: \n\n");
    noirMovieDatabase = fillDatabaseWithCatagory(movieDatabase, noirMovieDatabase, "Film-Noir");
    movieDatabase_sortByLength(noirMovieDatabase);
    movieDatabase_printFilmAtIndex(noirMovieDatabase, 2);
    movieDatabase_free(noirMovieDatabase);
    
    //Task #3
    printf("Task 3: \n\n");
    sciFiMovieDatabase = fillDatabaseWithCatagory(movieDatabase, sciFiMovieDatabase, "Sci-Fi");
    movieDatabase_sortByCriticRating(sciFiMovieDatabase);
    movieDatabase_printFilmAtIndex(sciFiMovieDatabase, 9);
    movieDatabase_free(sciFiMovieDatabase);
    
    //Task #4
    printf("Task 4: \n\n");
    Film *topRatedFilm = (Film*)malloc(sizeof(Film));
    topRatedFilm = findHighestRatedFilm(movieDatabase);
    film_printf(topRatedFilm);
    free(topRatedFilm);
    
    //Task #5
    printf("Task 5: \n\n");
    findShortestFilmTitle(movieDatabase);
    
    
    //Task #6
    printf("Task 6: \n\n");
    
    printf("length:  %i\n", movieDatabase_length(movieDatabase));    
    movieDatabase_free(movieDatabase);
    
        return (EXIT_SUCCESS);
}

// http://codereview.stackexchange.com/questions/40616/pointer-version-of-strcat
void custom_strcat(char *s, char *t) {
    while(*s) /* finding the end of the string */
        s++;

    while((*s++ = *t++)) /* copy t */
        ;
}