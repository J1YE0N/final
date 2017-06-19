#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define STRMAX 256

int showResult(char * input);
char *replaceValue(char *strInput, const char *strTarget, const char *strChange);

int main()
{
 char strInput[STRMAX];
 char strTarget[STRMAX];
 char strChange[STRMAX];
 char strResult[STRMAX];
 memset(strInput, 0, sizeof(STRMAX));
 memset(strResult, 0,sizeof(STRMAX));

 printf("input string: ");
 fgets(strInput,sizeof(strInput),stdin);
 //gets(strInput);
 printf("chage string: ");
 fgets(strTarget,sizeof(strTarget),stdin);
 //gets(strTarget);
 printf("changed string: ");
 fgets(strChange,sizeof(strChange),stdin);
 //gets(strChange);

 sprintf(strResult, "%s", replaceValue(strInput, strTarget, strChange));

 showResult(strResult);

 return 0;
}

int showResult(char * input){
 if(input == NULL)
	return -1;

 printf("RESULT: %s\n", input);

 return 0;
}


char *replaceValue(char *strInput, const char *strTarget, const char *strChange)
{
 char* strResult;
 char* strTemp;
 int i=0;
 int nCount=0;
 int nTargetLength = strlen(strTarget);
 
 if( nTargetLength < 1 )
	return strInput;
 int nChangeLength = strlen(strChange);

 if( nChangeLength != nTargetLength){
	for( i=0; strInput[i] != '\0'; ){
		if( memcmp(&strInput[i], strTarget, nTargetLength)==0 ){
			nCount++;
			i += nTargetLength;
		}
	}
 }
 else{
	i = strlen(strInput);
 }

 strResult = (char *) malloc(i+1+ nCount *(nChangeLength - nTargetLength));

 if( strResult == NULL ) return NULL;

 strTemp = strResult;
 while( *strInput){
	if( memcmp(strInput, strTarget, nTargetLength) == 0){
		memcpy(strTemp, strChange, nChangeLength);
		strTemp += nChangeLength;
		strInput += nTargetLength;
	}
	else{
		*strTemp++ = *strInput++;
	}
 }
 
 *strTemp = '\0';

 return strResult;

}

