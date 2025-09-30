#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int getComputerChoice();
int getUserChoice();
int checkWinner(int userChoice, int computerChoice);



int main(){

    srand(time(NULL));

    printf("Welcome to ROCK PAPER SCISSORS!\n"); // Welcome message/

    char start; // Welcome menu, press P to play E to exit - otherwise it will ask you to press P or E
    do {
        printf("You are going to play best of 5:\n");
        printf("Press P to play or E to exit: ");
        scanf(" %c", &start); 
        if(start == 'E' || start == 'e') {
            printf("Exiting game. Goodbye!\n"); 
            printf("\n");
            return 0;
        }
        if(start != 'P' && start != 'p') {
            printf("Error: Wrong input, enter P to play or E to exit\n"); //Error message for wrong input
            printf("\n");
        }


    } while(start != 'P' && start != 'p');

    int userScore = 0;
    int computerScore = 0;
    int round = 1;

    while(userScore < 3 && computerScore < 3){  //The scores of user and computer are counted and the round nr is presented to the user
        printf("\n");
        printf("Round: %d\n", round);
        printf("\n");
    

    int userChoice = getUserChoice();
    int computerChoice = getComputerChoice();

    switch(userChoice){ //Presenting the users choice
        case 1: 
            printf("You chose ROCK! \n");
            break;
        case 2: 
            printf("You chose PAPER! \n");
            break;
        case 3: 
            printf("You chose SCISSORS! \n");
            break;
        case 4: 
            printf("You chose LIZARD! \n");
            break;
        case 5: 
            printf("You chose SPOCK! \n");
            break;
    }

        switch(computerChoice){ //Presenting the computers choice
        case 1: 
            printf("Computer chose ROCK! \n");
            break;
        case 2: 
            printf("Computer chose PAPER! \n");
            break;
        case 3: 
            printf("Computer chose SCISSORS! \n");
            break;
        case 4: 
            printf("Computer chose LIZARD! \n");
            break;
        case 5: 
            printf("Computer chose SPOCK! \n");
            break;
    }

    int result = checkWinner(userChoice, computerChoice); //Compares the value of user and computerchoice and gives the user a corresponding message 
    if(result == 1) userScore++;
    else if(result == -1) computerScore++;

    printf("Score: You %d - Computer %d\n", userScore, computerScore);
    round++;
    }

    if(userScore == 3){ //When one of the players have 3 wins the user is informed if they won or lost
        printf("Congratulations! You won best of 5!");
    } else{
        printf("Sorry, you have lost!\n");
    }

    return 0;
}



int getComputerChoice(){ //Generating a random value between 1-5 that determines the computers choice in the game
    return (rand() % 5) + 1;
}


int getUserChoice(){ //Presenting the user with their options and let them choose

    int choice = 0;

    do{
        printf("Choose an option:\n");
        printf("1. Rock\n");
        printf("2. Paper\n");
        printf("3. Scissors\n");
        printf("4. Lizard\n");
        printf("5. Spock\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        if(choice < 1 || choice > 5){
        printf("Error: Please input a number between 1-5\n"); //Error message for wrong user input
        printf("\n");
        }
    }while(choice < 1 || choice > 5);
    return choice;
}

int checkWinner(int userChoice, int computerChoice){ //Compares the values of user/computer choice to determine who won
    
    if(userChoice == computerChoice){
        printf("It's a TIE!\n");
        return 0;
    }
    else if((userChoice == 1 && (computerChoice == 3 || computerChoice == 4)) || 
           (userChoice == 2 && (computerChoice == 1 || computerChoice == 5)) ||
           (userChoice == 3 && (computerChoice == 2 || computerChoice == 4)) ||
           (userChoice == 4 && (computerChoice == 2 || computerChoice == 5)) ||
           (userChoice == 5 && (computerChoice == 1 || computerChoice == 3 ))
        ){
        printf("You WIN!\n");
        printf("\n");
        return 1;
    }
    else{
        printf("You LOSE!\n");
        printf("\n");
        return -1;
    }


}