#include <stdint.h>
#include <stdio.h>
#include <time.h>

#define GAME_FIELD_WIDTH 8
#define GAME_FIELD_HEIGHT 16

typedef enum {
    EMPTY,
    TETRIMOS_I,
    TETRIMOS_O,
    TETRIMOS_T,
    TETRIMOS_L,
    TETRIMOS_J,
    TETRIMOS_Z,
    TETRIMOS_S,
    TETRIMOS_DESCENDING,
} tetrimos_e;

tetrimos_e tetrimos;

static tetrimos_e game_field [GAME_FIELD_HEIGHT][GAME_FIELD_WIDTH];

// save the state of the descending tetrimis 
tetrimos_e tetrimos_descending;


/**
    @brief init the game field 
*/
void init_game_field (void)
{
    for(int height = 0; height < GAME_FIELD_HEIGHT; height++)
    {
        for(int width = 0; width < GAME_FIELD_WIDTH; width++)
        {
            game_field[height][width] = EMPTY;
        }
    }
}

void display_game_field (void)
{
    system("clear");
    printf("--------\n");
    printf("GAME FIELD \n");
    printf("--------\n");

    for(int height = 0; height < GAME_FIELD_HEIGHT; height++)
    {
        for(int width = 0; width < GAME_FIELD_WIDTH; width++)
        {
            printf("%d", game_field[height][width]);
        }

        printf("\n");
    }

    printf("--------\n\n\n");
}


void delay(int number_of_seconds)
{
    // Converting time into milli_seconds
    int milli_seconds = 1000 * number_of_seconds;
  
    // Storing start time
    clock_t start_time = clock();
  
    // looping till required time is not achieved
    while (clock() < start_time + milli_seconds);
}

void descente(void)
{
    for(int height = 0; height < GAME_FIELD_HEIGHT - 1; height++) // GAME_FIELD_HEIGHT - 1 because bottom case will't descent
    {
        for(int width = 0; width < GAME_FIELD_WIDTH; width++)
        {
            if (game_field[height - 1][width] == EMPTY && game_field[height][width] != EMPTY)
            {

            }
        }
    }    
}

int main()
{
    printf("Hello World ! \n");
    init_game_field();
    display_game_field();

    // test descent
    for(int i = 0; i < 10; i++)
    {
        display_game_field();
        delay(1000);
    }
}