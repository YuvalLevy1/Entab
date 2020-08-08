#include <stdio.h>

#define MAX_INPUT 1000
#define TAB_LENGTH 4

void getChars(char phrase[], int maxLine);

void enTabString(char phrase[], char enTabPhrase[], int tabLength);

void stringCut(char str[], int index1, int index2);

int main() {

    char phrase[MAX_INPUT]; // the phrase we receive from the user.
    char enTabPhrase[MAX_INPUT]; // the phrase with tabs instead of spaces.
    printf("enter a phrase: ");
    getChars(phrase, MAX_INPUT);
    enTabString(phrase, enTabPhrase, TAB_LENGTH);
//    stringCut(phrase, 2, 4);
    printf("the new phrase is:\n%s\n", enTabPhrase);
    printf("I\t am best");
    return 0;

}

void getChars(char phrase[], int maxLine) {

    int c, i = 0;

    for (; i < maxLine - 1 && (c = getchar()) != EOF && c != '\n'; i++)
        phrase[i] = c;

    if (c == '\n') {
        phrase[i] = c;
        i++;
    }

    phrase[i] = '\0';
    printf("finished copying input");
}

void enTabString(char phrase[], char enTabPhrase[], int tabLength) {

    int iPhrase = 0, iEnTabPhrase = 0, c, spaceAmount, tabsReplaceSpace;

    while ((c = phrase[iPhrase]) != '\0') {
        if (c == ' ') {
            spaceAmount = 0;
            while (phrase[iPhrase] == ' ') {
                spaceAmount++;
                iPhrase++;
            }

            tabsReplaceSpace = spaceAmount / tabLength;
            spaceAmount = spaceAmount % tabLength;

            for (int i = 0; i < tabsReplaceSpace; i++) {
                enTabPhrase[iEnTabPhrase++] = '\t';
            }

            for (int i = 0; i < spaceAmount; i++)
                enTabPhrase[iEnTabPhrase++] = ' ';

        } else {
            enTabPhrase[iEnTabPhrase++] = c;
            iPhrase++;
        }
    }

    enTabPhrase[iEnTabPhrase] = '\0';
}