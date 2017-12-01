#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "film.h"

Film *film_new(int year, char title[100], char ageRating[12],
        char catagory[50], int runtime, double criticRating){
   // n.b check allocation successful
    
   Film *film = (Film*)malloc(sizeof(Film));
   
   // n.b. error checking to be added
   memcpy(film->title, title, 100);  
   memcpy(film->catagory, catagory, 50);
   film->year = year;
   film->runtime = runtime;
   film->criticRating = criticRating;
   memcpy(film->ageRating, ageRating, 12);
   return film;
}

void film_free(Film *film){
    free(film);
}

Film *bufferToFilm(char buf[]){
    char *title ,*year, *ageRating, *catagory, 
            *runtime, *criticRating, *secondHalfTitle;
    
    title = strtok(buf, ",");
    int len = strlen(title);
    char *lastElement = &title[len-1];
    if(strncmp(lastElement, "\"", 1) != 0){
        secondHalfTitle = strtok(NULL, ",");        
        custom_strcat(title, secondHalfTitle);
    }

    year = strtok(NULL, ",");
    ageRating = strtok(NULL, ",");
    catagory = strtok(NULL, ",");
    runtime = strtok(NULL, ",");
    criticRating = strtok(NULL, ",");
    
    Film *film = film_new(atoi(year), title, ageRating,
                catagory, atoi(runtime), atof(criticRating));
   
    return film;
}

void film_printf(Film *film){
    printf("Title: %s\nYear: %i\nAge Rating: %s\nRuntime: %i\n"
            "Genre: %s\nCritic Score: %f\n\n", film->title,
            film->year, film->ageRating, film->runtime,
            film->catagory, film->criticRating);
}

void film_setTitle(Film *film, char title[]){
    memcpy(film->title, title, 100); 
}
