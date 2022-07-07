#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

// Points assigned to each letter of the alphabet
int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);
int char_to_point(char letter);
string string_to_lower(string word);
void print_winner(int p1score, int p2score);

int main(void)
{
    // Get input words from both players
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");

    // Score both words
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);

    // Print the winner
    print_winner(score1, score2);
}

int compute_score(string word)
{
    int score = 0;
    int wordlen = strlen(word);
    word = string_to_lower(word);

    //For each char in word
    for (int i = 0; i < wordlen; i++)
    {
        //Sums its score by points Array
        score += char_to_point(word[i]);
    }

    return score;
}

string string_to_lower(string word)
{
    int wordlen = strlen(word);

    //For each char in word
    for (int i = 0; i < wordlen; i++)
    {
        //replace it for a lowercase
        //version of itself so its
        //ascii value will be
        //between 97 and 122
        word[i] = tolower(word[i]);
    }
    return word;
}

int char_to_point(char letter)
{
    int ascii_code = (int) letter;

    //Take 97 (ascii value of 'a') out of
    //letter, so each char value stays
    //between 0 and 25
    int point_index = ascii_code - 97;

    //If the index is lower than 0 or
    //greater than 25, it means that
    //its ascii code was lower than 97(a)
    //or greater than 122(z), so it doesn't
    //count and returns 0
    if (point_index < 0 || point_index > 25)
    {
        return 0;
    }

    int point = POINTS[point_index];
    return point;
}

void print_winner(int p1score, int p2score)
{
    string print_phrase[3] = {"Player1 wins!", "Player2 wins!", "Tie!"};
    int phrase_index = p1score > p2score ? 0 : p2score > p1score ? 1 : 2;

    printf("%s\n", print_phrase[phrase_index]);
}