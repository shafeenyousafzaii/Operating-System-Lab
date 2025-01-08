#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <pthread.h>

int score = 0;
int no_of_deliveries = 0;
int which_player = 2;
pthread_mutex_t myMutex;

// Struct for the player
struct player {
    int p_score;
    int p_out;
};

void * playerOne(void * player_one_arg) {
    struct player *player_one_data;
    player_one_data = (struct player *) player_one_arg;
    int r = 0;
    while (no_of_deliveries <= 36) {
        // If that is not our player
        r = rand() % 7;
        if (which_player != 1) {
            sleep(1);
        }

        // Player Get 0 score then he will be out
        if (r == 0) {
            pthread_mutex_lock(&myMutex);
            player_one_data->p_out += 1;
            no_of_deliveries += 1;
            player_one_data->p_score -= 10;
            printf("[Player 1] %d run(s) in %d balls OUT!\n", player_one_data->p_score, no_of_deliveries);
            score += player_one_data->p_score;
            if (no_of_deliveries >= 36)
                break;
            pthread_mutex_unlock(&myMutex);
        }

        // change the player
        if (r == 1 || r == 3 || r == 5) {
            pthread_mutex_lock(&myMutex);
            which_player = 2;
            no_of_deliveries += 1;
            player_one_data->p_score += r;

            if (no_of_deliveries <= 6)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 0 , no_of_deliveries);

            else if (no_of_deliveries <= 12)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 1, no_of_deliveries - 6);

            else if (no_of_deliveries <= 18)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 2, no_of_deliveries - 12);   

            else if (no_of_deliveries <= 24)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 3, no_of_deliveries - 18);   

            else if (no_of_deliveries <= 30)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 4, no_of_deliveries - 24);   
            
            else if (no_of_deliveries <= 36)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 5, no_of_deliveries - 30);  

            score += player_one_data->p_score;
            if (no_of_deliveries >= 36)
                break;
            else {
                pthread_mutex_unlock(&myMutex);
                sleep(1);
            }
            pthread_mutex_unlock(&myMutex);
        }

        if (r == 2 || r == 4 || r == 6) {
            pthread_mutex_lock(&myMutex);
            no_of_deliveries += 1;
            player_one_data->p_score += r;

            if (no_of_deliveries <= 6)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 0 , no_of_deliveries);

            else if (no_of_deliveries <= 12)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 1, no_of_deliveries - 6);

            else if (no_of_deliveries <= 18)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 2, no_of_deliveries - 12);   

            else if (no_of_deliveries <= 24)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 3, no_of_deliveries - 18);   

            else if (no_of_deliveries <= 30)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 4, no_of_deliveries - 24);   
            
            else if (no_of_deliveries <= 36)
                printf("[Player 1] %d run(s) in %d.%d overs\n", player_one_data->p_score, 5, no_of_deliveries - 30);  

            score += player_one_data->p_score;
            if (no_of_deliveries >= 36)
                break;
            pthread_mutex_unlock(&myMutex);
        }
    }
    printf("Total Score: %d IN bALLS %d\n", score, no_of_deliveries);
}  

void * playerTwo(void * player_two_arg) {
    struct player *player_two_data;
    player_two_data = (struct player *) player_two_arg;
    int r = 0;
    while(no_of_deliveries <= 36)   {
        r = rand() % 7;

        // player one thread is going to run
        if (which_player != 2) {
            sleep(1);
        }

        // Player Get Out
        if (r == 0) {
            pthread_mutex_lock(&myMutex);
            player_two_data->p_out += 1;
            player_two_data->p_score -= 10;
            no_of_deliveries += 1;

            if (no_of_deliveries <= 6)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 0 , no_of_deliveries);

            else if (no_of_deliveries <= 12)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 1, no_of_deliveries - 6);

            else if (no_of_deliveries <= 18)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 2, no_of_deliveries - 12);   

            else if (no_of_deliveries <= 24)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 3, no_of_deliveries - 18);   

            else if (no_of_deliveries <= 30)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 4, no_of_deliveries - 24);   
            
            else if (no_of_deliveries <= 36)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 5, no_of_deliveries - 30);  

            score += player_two_data->p_score;
              if (no_of_deliveries >= 36)
                break;
             pthread_mutex_unlock(&myMutex);
        }

        if (r == 1 || r == 3 || r == 5) {
             pthread_mutex_lock(&myMutex);
            which_player = 1;
            no_of_deliveries += 1;
            player_two_data->p_score += r;

            if (no_of_deliveries <= 6)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 0 , no_of_deliveries);

            else if (no_of_deliveries <= 12)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 1, no_of_deliveries - 6);

            else if (no_of_deliveries <= 18)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 2, no_of_deliveries - 12);   

            else if (no_of_deliveries <= 24)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 3, no_of_deliveries - 18);   

            else if (no_of_deliveries <= 30)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 4, no_of_deliveries - 24);   
            
            else if (no_of_deliveries <= 36)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 5, no_of_deliveries - 30);  
                
            score += player_two_data->p_score;
            if (no_of_deliveries >= 36)
                break;
            else {
                pthread_mutex_unlock(&myMutex);
                sleep(1);
            }
             pthread_mutex_unlock(&myMutex);
        }

        if (r == 2 || r == 4 || r == 6) {
             pthread_mutex_lock(&myMutex);
            player_two_data->p_score += r;
            no_of_deliveries += 1;

            if (no_of_deliveries <= 6)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 0 , no_of_deliveries);

            else if (no_of_deliveries <= 12)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 1, no_of_deliveries - 6);

            else if (no_of_deliveries <= 18)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 2, no_of_deliveries - 12);   

            else if (no_of_deliveries <= 24)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 3, no_of_deliveries - 18);   

            else if (no_of_deliveries <= 30)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 4, no_of_deliveries - 24);   
            
            else if (no_of_deliveries <= 36)
                printf("[Player 2] %d run(s) in %d.%d overs\n", player_two_data->p_score, 5, no_of_deliveries - 30);  

            score += player_two_data->p_score;
            if (no_of_deliveries >= 36)
                break;
             pthread_mutex_unlock(&myMutex);
        }
       
    }
}

int main() {
    srand(time(NULL));
    // int r = rand() % 7;
    // printf("%d\n", r);
    struct player playerone;
    struct player playertwo;

    playerone.p_score = 0;
    playerone.p_out = 0;

    playertwo.p_score = 0;
    playertwo.p_out = 0;

    pthread_t playerOneThread, playerTwoThread;

    pthread_create(&playerOneThread, NULL, playerOne, (void *) &playerone);
    pthread_create(&playerTwoThread, NULL, playerTwo, (void *) &playertwo);

    pthread_join(playerOneThread, NULL);
    pthread_join(playerTwoThread, NULL);
    return 0;
}