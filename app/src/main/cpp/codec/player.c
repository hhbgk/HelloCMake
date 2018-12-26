//
// Created by bob on 18-12-17.
//

#include <unistd.h>
#include <pthread.h>
#include <malloc.h>
#include "player.h"
#include "../log.h"
#define tag "player"
static void *thread(void *arg)
{
    player_t *player = arg;
//    pthread_setspecific(key, &gHello);

    sleep((unsigned int) player->state);
//    loge(tag, "%lx, hello=%d, state=%d", pthread_self(), gHello, player->state);
//    int hello = *((int *)pthread_getspecific(key));
//    loge(tag, "%lx, hello=%d", pthread_self(), hello);
    pthread_exit(NULL);
}
int player_create()
{
    player_t *player = calloc(1, sizeof(player_t));
    player->state = 2;
    pthread_create(&player->tid, NULL, thread, player);
    pthread_join(player->tid, NULL);
    free(player);
    return 0;
}
int player_close()
{
    return 0;
}