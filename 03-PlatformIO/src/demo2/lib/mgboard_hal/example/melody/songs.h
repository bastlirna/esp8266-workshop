#ifndef _SONGS_H
#define _SONGS_H

typedef struct{
  int *melody;
  int *tempo;
  uint32_t lenght;
}song_t;



extern song_t mario;
extern song_t underworld;

#endif
