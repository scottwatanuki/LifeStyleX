#include <stdio.h> //printf
#include <cs50.h> //get functions
#include <string.h> //strlen
#include <ctype.h> //isalpha
#include <stdlib.h> //random
#include <time.h> //time

void luckyNumber(int lower, int upper, int count) // function that generates and prints a random number within determined range
{
    int i; // declare local variable used for the for loop
    for (i = 0; i < count; i++) // for loop to run through the random numbers
    {
        int num = (rand() % (upper - lower + 1)) + lower; // **new concept. calculations for determining random number and storing it into a integer variable
        printf("\nYour luck number is %d! Have a good day!\n", num); // print lucky number after everything else is take care of
    }
}

string ask(string name, string question[], int choiceA, int choiceB, int choiceC, int choiceD); // declaration of function for asking questions

string ask(string name, string question[], int choiceA, int choiceB, int choiceC, int choiceD) // function for asking functions
{
    for (int i = 0; i < 7; i++) // for loop to run through the questions
    {
        char answer = get_char("%s", question[i]); //print questions from in order and ask for user input, which is the answer choice
        if (answer == 'a') // if the answer choice inputted by the user is a, then add count to choiceA variable
        {
            choiceA++;
        }
        else if (answer == 'b') // if the answer choice inputted by the user is b, then add count to choiceB variable
        {
            choiceB++;
        }
        else if (answer == 'c') // if the answer choice inputted by the user is c, then add count to choiceC variable
        {
            choiceC++;
        }
        else if (answer == 'd') // if the answer choice inputted by the user is d, then add count to choiceD variable
        {
            choiceD++;
        }
        else //otherwise, print the proper usage and end the program entirely
        {
            printf("Usage a/b/c/d: \n");
            return NULL;
        }
    }
    printf("\nCongratulations %s! You are categorized into one of the four scientifically proven chronotypes.\n", name); // print message
    if (choiceA > (choiceB || choiceC || choiceD)) // if the number of counts for choiceA is greater than any other choice, then print chronotype schedule for a bear.
    {
        printf("Your chronotype is a bear.\n\nThe ideal bear schedule looks like this:\n7–8 a.m.: Wake up\n10 a.m.–2 p.m.: Focus on deep work\n2–4 p.m.: Work on lighter tasks\n4–10 p.m.: Relax and unwind\n10–11 p.m.: Get ready for bed\n11 p.m.–7 a.m.: Sleep\n");
    }
    else if (choiceB > (choiceA || choiceC || choiceD)) // if the number of counts for choiceB is greater than any other choice, then print chronotype schedule for a lion.
    {
        printf("Your chronotype is a lion.\n\nThe ideal lion schedule looks like this:\n7:30–9 a.m.: Wake up\n10 a.m.–12 p.m.: Focus on lighter tasks\n12–2 p.m.: Complete deep or creative work\n2–5 p.m.: Focus on lighter, less intense tasks\n5–9 p.m.: Engage in creative tasks\n9–10 p.m.: Unwind from the day\n10 p.m.–12 a.m.: Prepare for bed\n12–7:30 a.m.: Sleep\n");
    }
    else if (choiceC > (choiceB || choiceA || choiceD)) // if the number of counts for choiceC is greater than any other choice, then print chronotype schedule for a wolf.
    {
        printf("Your chronotype is a wolf.\n\nThe ideal wolf schedule looks like this:\n6–7 a.m.: Wake up\n8 a.m.–12 p.m.: Focus on deep work\n12–4 p.m.: Focus on lighter tasks\n4–9 p.m.: Daily unwind and relax\n9–10 p.m.: Get ready for bed\n10 p.m. – 6 a.m.: Sleep\n");
    }
    else if (choiceD > (choiceB || choiceC || choiceA)) // if the number of counts for choiceD is greater than any other choice, then print chronotype schedule for a dolphin.
    {
        printf("Your chronotype is a dolphin.\n\nThe ideal dolphin schedule looks like this:\n6:30–7:30 a.m.: Wake up\n8–10 a.m.: Engage with easy to-dos\n10 a.m.–12 p.m.: Focus on demanding tasks\n12–4 p.m.: Complete less demanding tasks\n4–10 p.m.: Relax, unwind from the day\n10–11:30 p.m.: Prepare for bed\n12–6:30 a.m.: Sleep\n");
    }
    int rating = get_int("\nPlease rate your experience with us out of 10!: "); //ask for rating of the service out of 10
    //printf("%i", rating)
    printf("\nA special thanks to %s from LifeStyleX!\n", name); //print message
    int lower = 1, upper = 9, count = 1; //variables for generating random number. the count variable determines the number of random numbers
    srand(time(0)); //** new concept. uses current time as seed for generating the random number so it doesn't have a pattern
    luckyNumber(lower, upper, count); //send the variables to the luckyNumber function
    return 0; //return 0 for success
}

int main(int argc, string argv[]) //main function
{
    string name = argv[1]; //create a variable for argv[1], which is the name inputted by the user in the command line
    if (argc != 2) // if number of arguments isn't 2
    {
        printf("Usage: ./lifestylex name\n"); //print the proper usage
        return 1; // return 1 for error
    }
    else if (argc == 2)// otherwise
    {
        for (int i = 0; i < strlen(name); i++) // for loop
        {
            if (!isalpha(name[i])) // if there is any letter besides an alphabet in the key,
            {
                printf("Usage: ./lifestylex name\n"); // print the proper usage
                return 1; //return 1 for error
            }
        }
    printf("Hello %s! Thank you for using LifeStyleX.\n", name); // print message (inside else if)
    }
    printf("\nAnswer this quiz and we'll create a personalized lifestyle schedule for you!\n"); //print message
    int a = 0, b = 0, c = 0, d = 0; // variables for each answer choice
    // save the seven questions for the quiz inside an array named question
    // questions are extracted from https://www.youtube.com/watch?v=U7qCF461WPA
    string question[] = {
        "\n#1: What time do you NATURALLY wake up?\nA. 8am or 9am\nB. About 6am or even earlier\nC. Somewhere around 11am\nD. I barely sleep through the night, so the time I wake up varies\nAnswer: ",
        "\n#2: How do you feel about parties?\nA. They're ok\nB. Not really my cup of tea\nC. I love them!\nD. I can't stand them\nAnswer: ",
        "\n#3: What time do you usually go to bed?\nA. As early as I possibly can!\nB. About 9-10pm\nC. No later than 12am\nD. Very late\nAnswer: ",
        "\n#4: What do you do on the weekends?\nA. Try to recoup my sleep\nB. Clean up the house and prepare my schedule for the next week\nC. Meet up with my friends or family\nD. Relax at home\nAnswer: ",
        "\n#5: Do you get enough sleep at night?\nA. No, I always want more!\nB. Not really\nC. Yes, but mornings are still hard for me\nD. Definitely not!\n\nAnswer: ",
        "\n#6: What part of the day does your mind feel at its sharpest\nA. Afternoon\nB. Morning\nC. Evening\nD. Midday\nAnswer: ",
        "\n#7: How often do you take naps?\nA. Very frequently\nB. Quite rarely\nC. Almost never\nD. Often enough\nAnswer: "};
    string q = ask(name, question, a, b, c, d); //send the variables to ask function, which will ask the questions.
}