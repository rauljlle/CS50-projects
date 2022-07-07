#include <cs50.h>
#include <stdio.h>

int str_len(string str);
bool is_lower(char c);
bool is_upper(char c);
bool is_letter(char c);
char to_lower(char c);
char to_upper(char c);
string cipher_text(string text, string cipher);

int main(int argc, string argv[])
{
    if(argc != 2)
    {
        printf("Incorrect Usage: You should use 1 argument.\n");
        return 1;
    }
    else if(str_len(argv[1]) != 26)
    {
        printf("Incorrect Usage: Your cipher must be 26 characters long.\n");
        return 1;
    }


    string cipher = argv[1];
    string plaintext = get_string("plaintext: ");
    string ciphertext = cipher_text(plaintext, cipher);

    printf("ciphertext: %s\n", ciphertext);
}

string cipher_text(string text, string cipher)
{
    int cipher_index;
    int txtlength = str_len(text);

    for(int i = 0; i < txtlength; i++)
    {
        if(!is_letter(text[i]))
        {
            continue;
        }

        cipher_index = is_lower(text[i]) ? (int) text[i] - 97 : (int) text[i] - 65;

        if(is_lower(cipher[cipher_index]))
        {
            text[i] = is_upper(text[i]) ? to_upper(cipher[cipher_index]) : cipher[cipher_index];
        }
        else
        {
            text[i] = is_lower(text[i]) ? to_lower(cipher[cipher_index]) : cipher[cipher_index];
        }
    }

    return text;
}

int str_len(string str)
{
    int len = 0;

    for(int i = 0; str[i] != '\0';)
    {
        i++;
        len = i;
    }

    return len;
}

bool is_lower(char c)
{
    if((int) c >= 97 && (int) c <= 122)
    {
        return true;
    }

    return false;
}

bool is_upper(char c)
{
    if((int) c >= 65 && (int) c <= 90)
    {
        return true;
    }

    return false;
}

bool is_letter(char c)
{
    if(is_lower(c) || is_upper(c))
    {
        return true;
    }

    return false;
}


char to_lower(char c)
{
    if(is_upper(c))
    {
        int ascii_code = (int) c;
        return (char) ascii_code + 32;
    }

    return c;
}

char to_upper(char c)
{
    if(is_lower(c))
    {
        int ascii_code = (int) c;
        return (char) ascii_code - 32;
    }

    return c;
}