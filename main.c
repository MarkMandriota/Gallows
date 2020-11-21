#include <stdlib.h>
#include <malloc.h>
#include <stdio.h>
#include <conio.h>
#include <time.h>

const char* words[] = {
	"program", "processor", 
	"server", "computer",
};

const char* player[] = {
	"  |\n  #\n /|\\\n /'\\", "  0\n /|\\\n / \\\n",
	"  0\n /|\\\n /\n", "  0\n /|\\\n\n", "  0\n /|\n\n", 
	"  0\n  |\n\n", "  0\n\n\n", "\n\n\n",
};

int main() {
	srand(time(0));
	const char* word = words[rand()%sizeof(words)/sizeof(*words)];
	
	size_t rem = 0; 
	while (word[++rem]);
	
	char* answer = (char*)malloc(rem);
	for (size_t i = 0; word[i]; ++i)
		answer[i] = '_';
	answer[rem] = 0;
	
	size_t lifes = 7;
	while (rem && lifes) {
		printf("\n%s\nGuess Letter: ", answer);
		
		size_t prev = rem;
		char guess = getch();
		
		for (size_t i = 0; word[i]; ++i)
			if (word[i] == guess && answer[i] != guess) {
				answer[i] = guess;
				--rem;
			}
		
#if defined(_WIN32) || defined (_WIN64)
		system("cls");
#else
		system("clear");
#endif

		lifes -= !(rem-prev);
		printf(player[lifes]);
	}
	printf("\n%s\n", answer);

	if (lifes) printf("You won!");
	else printf("You lose...");
	
	getch();
	
	return 0;
}