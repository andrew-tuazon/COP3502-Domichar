// Andrew Tuazon
// COP 3502, Spring 2020
// an623310

#include "Domichar.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

// recursive main function to process arbitrary amount of strings
int main(int argc, char **argv)
{
	int i;
	for (i = 1; i < argc; i++)
	printDomichar(argv[i]);
	return 0;
}

void printDomichar(char *str)
{
	int i, strLength = strlen(str); 						// acquire string length
	char ch = str[0]; 										// initialize character variable
	double vowCount = 0.0, conCount = 0.0, nonCount = 0.0;
	double domVow, domCon, domNon;
	// for loop reads through the string and categorizes each letter adding to a counter
	for (i = 0; i < strLength; i++)							
	{	
		ch = str[i];
		if (isVowel(ch) == 1)								
			vowCount++;
		if (isConsonant(ch) == 1)
			conCount++;
		if (isNonalphabetic(ch) == 1)
			nonCount++;
	}
	
	domVow = vowCount / strLength;							// calculate domination percentages
	domCon = conCount / strLength;
	domNon = nonCount / strLength;
	
	printf("%s ", str);										// print the string
	
	// compare values to determine domination by majority/plurality or a tie
	if (domVow > 0.5000)									
		printf("(m:v)\n");
	else if (domVow == 0.5000 && ((domCon < .5000) && domNon < .5000))
		printf("(p:v)\n");
	else if (domCon > 0.5000)
		printf("(m:c)\n");
	else if (domCon == 0.5000 && ((domVow < .5000) && domNon < .5000))
		printf("(p:c)\n");
	else if (domNon > 0.5000)
		printf("(m:~)\n");
	else if (domNon == 0.5000 && ((domCon < .5000) && domVow < .5000))
		printf("(p:~)\n");	
	else if (fabs(domVow - domCon < 0.00001) && domNon == 0.0)			
		printf("(vc)\n");
	else if (fabs(domNon - domVow < 0.00001) && domCon == 0.0)
		printf("(v~)\n");
	else if (fabs(domCon - domNon < 0.00001) && domVow == 0.0)
		printf("(c~)\n");
	else if (fabs(domVow - domCon < 0.00001) && fabs(domVow - domNon < 0.00001) 
		&& fabs(domCon - domNon < 0.00001))
		printf("(vc~)\n");
}

// determine if the character is an uppercase or lowercase vowel
int isVowel(char c)
{
	int vowel;
	vowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' 
	|| c == 'A' || c == 'E' || c == 'I'|| c == 'O' || c == 'U');
	if (vowel)
		return 1;
	else
		return 0;
}

// determine if character is a consonant if it is alphabetic and is not a vowel
int isConsonant(char c)
{
	int consonant;
	consonant = (isalpha(c) != 0 && (c != 'a' && c != 'e' && c != 'i' && c != 'o' && c != 'u'
	&& c != 'A' && c != 'E' && c != 'I' && c != 'O' && c != 'U'));
	if (consonant)
		return 1;
	else
		return 0;
}

// determine if the character is nonalphabetic
int isNonalphabetic(char c)
{
	if (isalpha(c) == 0)
		return 1;
	else
		return 0;
}

double difficultyRating(void)
{
	return 4.0;
}

double hoursSpent(void)
{
	return 22.0;
}
