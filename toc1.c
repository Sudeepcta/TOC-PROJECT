 
#include <stdio.h> 
#include <string.h> 
 
#define MAX_WORDS 50 
#define MAX_LEN 100 
 
// Function to tokenize the sentence into words 
int tokenize(char *sentence, char words[MAX_WORDS][MAX_LEN]) { 
    int count = 0; 
    char *token = strtok(sentence, " "); 
    while (token != NULL) { 
        strcpy(words[count++], token); 
        token = strtok(NULL, " "); 
    } 
    return count; 
} 
 
// Function to print Reverse Normal Form (RNT) 
void printRNT(char words[MAX_WORDS][MAX_LEN], int word_count) { 
    printf("\nReverse Normal Form (RNT):\n"); 
    for (int i = word_count - 1; i >= 0; i--) { 
        printf("%s ", words[i]); 
    } 
    printf("\n"); 
} 
 
// Function to simulate Abstract Normal Tree (ANT) 
void printANT(char words[MAX_WORDS][MAX_LEN], int word_count) { 
    printf("\nAbstract Normal Tree (ANT):\n"); 
    printf("S\n"); 
    printf("├── NP: %s\n", words[0]); // Subject 
    printf("└── VP:\n"); 
    printf("    ├── V: %s\n", words[1]); // Verb 
    printf("    └── NP: "); 
    for (int i = 2; i < word_count; i++) { 
        printf("%s ", words[i]); // Object 
    } 
    printf("\n"); 
} 
 
int main() { 
    char sentence[MAX_LEN]; 
    char words[MAX_WORDS][MAX_LEN]; 
    int word_count; 
6 
 
    printf("Enter a simple sentence :\n"); 
    fgets(sentence, MAX_LEN, stdin); 
    sentence[strcspn(sentence, "\n")] = 0; // Remove newline 
 
    word_count = tokenize(sentence, words); 
    printRNT(words, word_count); 
    printANT(words, word_count); 
 
    return 0; 
} 