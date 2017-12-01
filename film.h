/* 
 * File:   film.h
 * Author: benbriggs
 *
 * Created on October 24, 2016, 12:30 PM
 */

#ifndef FILM_H
#define	FILM_H

#ifdef	__cplusplus
extern "C" {
#endif
                        
typedef struct FilmStruct
{
  int year;
  
  char title[100];
  
  char ageRating[12];
  
  char catagory[50];
  
  int runtime;
  
  double criticRating;    
}
Film;

Film *film_new(int year, char title[100], char ageRating[12],
                char catagory[50], int runtime, double criticRating);
void film_free(Film *film);  
Film *bufferToFilm(char buf[]);
void film_printf(Film *film);
#ifdef	__cplusplus
}
#endif

#endif	/* FILM_H */

