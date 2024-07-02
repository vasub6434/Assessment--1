#include <stdio.h>

void menu() 
{
    printf("\nString Operations Menu:\n");
    printf("--------------------------------------");
    printf("1. Reverse a string\n");
    printf("2. Concatenate two strings\n");
    printf("3. Check if a string is a palindrome\n");
    printf("4. Copy a string\n");
    printf("5. Find the length of a string\n");
    printf("6. Find the frequency of a character in a string\n");
    printf("7. Find the number of vowels and consonants\n");
    printf("8. Find the number of blank spaces and digits\n");
    printf("9. Exit\n");
}

// 1
void r_string(char *a) 
{
    int len = string_length(a),i;

    for (i = 0; i < len / 2; i++) 
	{
        char temp = a[i];
        a[i] = a[len - i - 1];
        a[len - i - 1] = temp;
    }
    printf("Reverse : %s\n", a);
}

// 2
void two_string(char *s1, char *s2) 
{
    int len1 = string_length(s1);
    int len2 = string_length(s2);
    int i;
    for (i = 0; i <= len2; i++) 
	{
        s1[len1 + i] = s2[i];
    }
    printf("Concatenated : %s\n", s1);
}

// 3
int is_palindrome(char *a) 
{
    int len = string_length(a),i;
    for (i = 0; i < len / 2; i++) 
	{
        if (a[i] != a[len - i - 1]) 
		{
            return 0;
        }
    }
    return 1;
}

// 4
void copy_string(char *a, char *c) 
{
    int i = 0;
    while (a[i] != '\0') 
	{
        c[i] = a[i];
        i++;
    }
    c[i] = '\0';
    printf("Copie: %s\n", c);
}

// 5
int string_length(char * a) 
{
    int length = 0;
    while (a[length] != '\0') 
	{
        length++;
    }
    return length;
}
// 6
void char_frequency(char *a, char ch) 
{
    int count = 0,i;
    for (i = 0; a[i] != '\0'; i++) 
	{
        if (a[i] == ch)
		{
            count++;
        }
    }
    printf("Frequency of '%c': %d\n", ch, count);
}

// 7
void count_vowels(char *a) 
{
    int vowels = 0, consonants = 0,i;
    for (i = 0; a[i] != '\0'; i++) 
	{
        char ch = tolower(a[i]);
        if (isalpha(ch)) 
		{
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u' || ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U') 
			{
                vowels++;
            } else 
			{
                consonants++;
            }
        }
    }
    printf(" vowels: %d\n", vowels);
    printf("consonants: %d\n", consonants);
}

// 8
void count_digits(char *a) 
{
    int spaces = 0, digits = 0,i;
    for (i = 0; a[i] != '\0'; i++) 
	{
        if (isspace(a[i])) 
		{
            spaces++;
        } else if (isdigit(a[i])) 
		{
            digits++;
        }
    }
    printf(" blank spaces: %d\n", spaces);
    printf("digits: %d\n", digits);
}

int main() 
{
    char str1[100], str2[100], copy[100], ch;
    int choice;
    do 
	{
        menu();
        printf("Enter your choice (1-9): ");
        scanf("%d", &choice);
        getchar();  

        switch (choice) 
		{
            case 1:
                printf("Enter the string to reverse: ");
                gets(str1);
                r_string(str1);
                break;
            case 2:
                printf("Enter the first string: ");
                gets(str1);
                printf("Enter the second string: ");
                gets(str2);
                two_string(str1, str2);
                break;
            case 3:
                printf("Enter the string to check for palindrome: ");
                gets(str1);
                if (is_palindrome(str1)) {
                    printf("'%s' is a palindrome.\n", str1);
                } else {
                    printf("'%s' is not a palindrome.\n", str1);
                }
                break;
            case 4:
                printf("Enter the string to copy: ");
                gets(str1);
                copy_string(str1, copy);
                break;
            case 5:
                printf("Enter the string to find its length: ");
                gets(str1);
                printf("Length of the string: %d\n", string_length(str1));
                break;
            case 6:
                printf("Enter the string: ");
                gets(str1);
                printf("Enter the character to find its frequency: ");
                scanf("%c", &ch);
                getchar();  
                char_frequency(str1, ch);
                break;
            case 7:
                printf("Enter the string: ");
                gets(str1);
                count_vowels(str1);
                break;
            case 8:
                printf("Enter the string: ");
                gets(str1);
                count_digits(str1);
                break;
            case 9:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please select a valid option from the menu.\n");
        }

        if (choice != 9) 
		{
            printf("Do you want to continue? (y/n): ");
            char cont = getchar();
            getchar(); 
            if (cont == 'n' || cont == 'N') 
			{
                break;
            }
        }

    } while (choice != 9);

}

