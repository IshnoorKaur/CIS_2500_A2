#include "../include/kaurIshnoorA2.h"

int main (int argc, char *argv[]) {

	//Variables 
	char *stringRead; 

	char *aString;
	int numWords; 
	int numSentences;

	char *stretched;

	char *fun5; 
	char **fun4; 
	int num; 

	//Function 1 call
	if((stringRead = readFile(argv[1])) != NULL) {
   		printf("String read is \n%s\n",stringRead);
		printf("Length = %lu\n", strlen(stringRead)); 
    		printf("Function 1 Successful!\n"); 
	}
	printf("\n");


	//String input 
	aString = "The red readymade dress was made for you! It was going to be ready tomorrow. What was the colour of the dress? Oh, it was red!";

	//Function 2 call 
	dejaVu(aString, &numWords, &numSentences);

	printf("Function 2 Successfull!\n");

	printf("\n");

	//Function 3 call
	stretched = goBig("Hello!");

	printf("New string: %s\n", stretched);
	free(stretched);
	printf("Function 3 Successful!\n");
	printf("\n");
 
	//Function 4 call 
	fun4 = goAway(aString, &num);
	printf("Number of words: %d\n", num);

	for(int i = 0; i < num; i++) {
		printf("%s\n", fun4[i]);
		free(fun4[i]);
	} 
 	free(fun4); 
	printf("Function 4 Successful!\n");
	printf("\n");


	//function 5 call 
	char newString[] = "One , Two ! Three? Four. . Done!";
	printf("String: %s \n", newString); 
	fun5 = breathless(newString);
	printf("New String is: %s \n", fun5); 
	printf("Function 5 Sucessful!\n");
	printf("\n");

	//function 6 call 
	char *str3 = "Now is the winter of our discontent Made glorious summer by this Sun of York.";
	int whichWord = 15; 
	char *desiredSuffix = "otter";
	tail(str3, whichWord, desiredSuffix);
	printf("Function 6 Done\n");
	printf("\n");

	return 0; 

}
