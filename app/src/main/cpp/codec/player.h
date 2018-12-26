//
// Created by bob on 18-12-17.
//

#ifndef HELLOCMAKE_PLAYER_H
#define HELLOCMAKE_PLAYER_H

#include <sys/types.h>

typedef struct _player{
    int state;
    pthread_t tid;
}player_t;
int player_create();
int player_close();
#endif //HELLOCMAKE_PLAYER_H
