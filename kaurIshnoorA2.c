#include "../include/kaurIshnoorA2.h"

/* Task 1 - This function takes a filename of a text file as input, opens and reads the contents of the file and returns the contents as a string (char *). Use dynamic allocation */
char *readFile(char *filename)
{

    // reads the txt file
    FILE *fPtr = fopen(filename, "r");

    // pointers
    char *ptr;

    // initialize space
    ptr = malloc(sizeof(char));

    // variables
    char ch;
    int i = 0;

    if (ptr == NULL)
    {
        //printf("Memory not allocated!\n");
        return NULL;
    }

    while (!feof(fPtr))
    {
	ch = fgetc(fPtr);
	ptr[i] = ch;
        i++;
	ptr = realloc(ptr, (i+1) *sizeof(char));
    }

	ptr[i-1] = '\0';

    return ptr; 

    // Deallocating the memory using free
    fclose(fPtr);

    printf("\n");

    printf("Fun 1 done!\n"); 

}

/* Task 2 - This function takes a string as input, and outputs the number of words and number of sentences in it. */
void dejaVu(char *aString, int *numWords, int *numSentences) {

	int i = 0;

	//storing number of words and number of sentences 
	*numWords = 0;
	*numSentences = 0;

	//storing the length of aString 
	int length = strlen(aString);

	//Counts the number of words in the string
	for (i = 0; i < length ; i++) {
		if((aString[i] == ' ') || (aString[i] == '\n')){
		(*numWords)++;

	            //skip over consecutive words delimiters
        	    while (i < length - 1 && ((aString[i + 1] == ' ') || (aString[i + 1] == '\n'))) {
                	i++;
            	    }
		}

	//Counts the number of sentences in the string
	if ((aString[i] == '.') || (aString[i]== '!') || (aString[i] == '?') || (aString[i] == ';')) {

		(*numSentences)++;

		//skip over consecutive sentence delimiters
            while (i < length - 1 && ((aString[i + 1] == '.') || (aString[i + 1] == '!') || (aString[i + 1] == '?') || (aString[i + 1] == ';'))) {
                i++;
            }

	} 

	}
	(*numWords)++;

    //Print statements 
	printf("Output is: \n");
	printf("Number of words = %d\n", *numWords);
	printf("Number of sentences = %d\n", *numSentences);
	printf("End- Function 2\n");
}


/* Task 3 - This function takes a string, it prompts the user to enter exactly n valid positive integers, where n is the length of aString. Each letter repeated by the number of times indicated by the user for that corresponding position.*/
char *goBig(char *aString) {

    //pointer
    char *ptr;

    //variables 
    int i = 0;
    int j = 0;
    int num = 0; 

    //finds the length of the string 
    int length = strlen(aString);

    //this variables is used in the for loop for the input values 
    int value[length];

    //allocates space according to the size of aString
    ptr = malloc(sizeof (char));

    //User enters n number of values 
    printf("Enter %d values: \n", length);

    //scans the number of values entered by the user     
    for(i = 0; i < length; i++) {
        scanf("%d", &value[i]);

    //Entering a 0 or negative number is considered invalid 
    while(value[i] <= 0) {
        scanf("%d", &value[i]);
    }

    }

    //for loop that stretches the string according to the values entered by the user
    for (i = 0; i < length; i++) {
        for(j = 0; j < value[i]; j++) {
            ptr[num++] = aString[i];

	    //reallocate space for the stretched string
	    ptr = realloc(ptr, sizeof(char) * (num + 1));
        }
    }
    //null terminator 
    ptr[num] = '\0';

    //free the pointer and return the stretched string
    return ptr;
}


/* Task 4 - This function takes a string aString, splits it into n words, stores the words in a dynamic 2D array and returns it. The function also outputs the total number of words stored in the given input aString. */
char **goAway(char *aString, int *numWordsReturned){

    // pointers
    char **pointer1;
    char *delimaters = " ";

    // Variables
    int numOfWords = 0;

    char newString[1000];
    strcpy(newString, aString);

        // Allocate memory for a 2D array to hold the words
        pointer1 = malloc(sizeof(char *) * 1);

        if (pointer1 == NULL)
        {
            printf("Memory allocation failed!\n");
            return NULL;
        }

    // Split the string input into words
    char *split = strtok(newString, delimaters);

    // while loop
    while (split != NULL)
    {

        //Checks if the array need to be resized
        if (numOfWords != 0) {
            // reallocate memory
            pointer1 = realloc(pointer1, sizeof(char*) * (numOfWords + 1));
        }

        // length of split
        int length = strlen(split);

        //allocate mem 
        pointer1[numOfWords] = malloc(sizeof(char) * (length +1));

        //Copy the string
        strcpy(pointer1[numOfWords], split);
    
        // null terminator
        pointer1[numOfWords][length] = '\0';

        //Increment 
        numOfWords++; 
  //      i++;

        split = strtok(NULL, delimaters);
    }

    // Number of words returned
    *numWordsReturned = numOfWords;

    // Return - 2D array
    return pointer1;
}


/* Task 5 - This function takes a string aString, finds all punctuations in the given string and removes them from aString. Returns the string with no  puntuations */
char *breathless(char *aString){

        //Declaring variables 
    int i; 
    int j = 0; 
    int length; 
    char * newString; 

    //Length of the string 
    length = strlen(aString);

    //Allocate memorory for the new string 
    newString = malloc(length + 1);

    //Memory not allocated 
    if (newString == NULL) {
        printf("Memory not allocated!\n");
        return NULL;
    }

    //Memory is allocated 
    for(i = 0; i < length; i++ ) {
        char str = aString[i];
        if ((str != '.') && (str != '?') && (str != '!') && (str != ':') && (str != ';')) {
            newString[j++] = str;
        }
    }

    //null terminator 
    newString[j] = '\0';

    //To copy the output back to the input string 
    aString = newString; 

    //Return to main 
    return aString; 
}

/* Task 6 - This function takes a string, finds the word given in position whichWord. Each word printed on the screen starts with a letter in the word at position whichWord and is suffixed by desiredSuffix.*/ 
void tail(char *aString, int whichWord, char *desiredSuffix) {

    // variables
    int word = 0;
    int i = 0;
    int length;

    // pointers
    char delim[] = " ";

    char newString[1000];
    strcpy(newString, aString);

    char *currentW = desiredSuffix;
    char *nextPtr;

    // Checks if the input string is empty
    if (newString == NULL)
    {
        printf("Input String is empty!\n");
        // return;
    }

    // Split the string into words using strtok()
    char *wordPtr = strtok(newString, delim);

    // while loop which allows us to find the word 'whichWord'
    while (wordPtr != NULL)
    {
        word++;
        if (word == whichWord)
        {

        // The if statement checks if the target word is found
        if (currentW != NULL && wordPtr != NULL)
        {

            // Get the length of the word
            length = strlen(wordPtr);

            // A for loop that prints the tail words
            printf("\nOutput:\n");

            for (i = 0; i < length; i++)
            {
		//This if statement makes sure that no puntuation is printed 
		if (isalpha(wordPtr[i])) {
                printf("%c%s\n", wordPtr[i], currentW);

		}
	}
            printf("Function 6 is successful!\n");
        }
        else
        {
            printf("The target word not found!\n");
        }
	break;
    } 
	nextPtr = strtok(NULL, delim);
        if(nextPtr == NULL) {
            break;
        }
        wordPtr = nextPtr;

    }
}



