/// Samuel Watson-this program reads a data file with messages and uses the command line arguments (file name, phone num1, and phone num2) to search through the file and print the messages that were sent from those phone numbers. Also prints the time each message was sent //////////////////
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

void printHeader(long, long);//prints the header of the output

char *readableTime(long);//converts posix time to readable time

void processMessage(FILE*, long, long, long, int, char[], int);//used to process message from file while #s are matching

void skipMessage(FILE*, int);//used to skip through a file until a match is found

int checkNumbers(long, long, long, long);//returns 0 if phone #s match in order and 1 if they match vice versa

void printLine1(long, long, long, char[]);//prints the time and entire processed line

void printLine2(long, long, long, char[]);//prints the time and entire processed line



int main(int argc, char *argv[])
{
	FILE *fp=fopen(argv[1], "r");
	if(fp==NULL)
	{
	printf("Could not open file.");
		exit(1);
	}
	if(argv[2]==NULL||argv[3]==NULL)
	{
		printf("You did not correctly enter phone numbers.");
		exit(1);
	}
	long commandNum1=atol(argv[2]);
	long commandNum2=atol(argv[3]);
	printHeader(commandNum1, commandNum2);
	long posix=0, fileNum1=0, fileNum2=0;
	int words=0;
	char line[26]="";
	fscanf(fp, "%ld", &posix); //read  in time
	while(!feof(fp))
	{
		fscanf(fp, "%ld %ld", &fileNum1, &fileNum2); //read in the two numbers
		fscanf(fp, " %d", &words); //read in number of words
		int match=checkNumbers(commandNum1, commandNum2, fileNum1, fileNum2);
		if(match==0) //1-1 and 2-2 matching
		{
			printLine1(posix, fileNum1, fileNum2, line);
			processMessage(fp, fileNum1, fileNum2, posix, words, line, match);
		}
		else if(match==1) //1-2 and 2-1 matching
		{
			printLine2(posix, fileNum1, fileNum2, line);
			processMessage(fp, fileNum1, fileNum2, posix, words, line, match);
		}

		else //numbers did not match
		{
			skipMessage(fp, words);
		}
		fscanf(fp, "%ld", &posix);
	}

	return 0;
}

void printHeader(long a, long b)
{
	printf("\nTime\t\t\t      %ld\t\t    %ld\n",a, b);
	printf("=====================================================================================\n");
	return;
}

char *readableTime(long sec)
{
	time_t epoch_time =(time_t) sec;
	return asctime( localtime( &epoch_time) );
}

int checkNumbers(long command1, long command2, long file1, long file2)
{
	if(command1==file1&&command2==file2)
		return 0;
	else if(command1==file2&&command2==file1)
		return 1;
	else
		return 2;
}

void processMessage(FILE *data, long fileNum1, long fileNum2, long posix, int words, char line[], int match)
{
	int count=0;
	strcpy(line, "");
	char str[26]="";
	for(int i=0; i<words; i++)
	{
		fscanf(data, "%s", str);
		if(strlen(line)+1+strlen(str)<26)
		{
			if(strcmp(line, "")!=0)
				strcat(line, " ");
			strcat(line, str);
		}
		else
		{
			if(count>0)
				printf("\t\t\t      ");
			if(match==1&&count>0)
				printf("\t\t\t            ");
			printf("%s\n", line);
			strcpy(line, str);
			count++;
		}
	}
	if(strcmp(str, "")!=0)
	{
		count++;
		if(count>1)
			printf("\t\t\t      ");
		if(match==1&&count>1)
				printf("\t\t                    ");
		printf("%s\n", line);
	}
}


void skipMessage(FILE *data, int words)
{
	char str[26]="";
	for(int i=0; i<words; i++)
		fscanf(data, "%s", str);
}

void printLine1(long time, long fileNum1, long fileNum2, char line[])
{
	char* str=readableTime(time);
	str[(strlen(str)-1)]=' ';
	printf("%s     ", str);
}

void printLine2(long time, long fileNum1, long fileNum2, char line[])
{
	char* str=readableTime(time);
	str[(strlen(str)-1)]=' ';
	printf("%s\t\t\t            ", str);
}
