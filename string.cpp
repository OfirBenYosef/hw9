#include <iostream>
#include "string.h"
#include <stdbool.h>
#include<string.h>
using namespace std;

/* *
*String() - default constructor 
*/
String::String()
: data(NULL) ,length(0){}

/**
*String(const String &str) - copy constructor
*/
String::String(const String &str) : 
    length (str.length) {
		if(length==0){
			data=NULL;
		}
		else{
			/*if return error set len to 0*/
			(data=strdup(str.data))? (length=length):(length=0);
		}
}

/**
* String(const char *str)
*/
String::String(const char *str){
	/*is str isnt NULL*/
	if(str){
		/*if return error set len to 0 else set to the str len */
		(data=strdup(str))?(length=(strlen(str))):(length=0);
	}
	else{
		length=0;
		data=NULL;	
	}
}

/**
 * ~String() - D'tor
 * free the allocated memory
 */
String::~String() {
	(free(data));
}
/**
*String& operator=(const String &rhs)
*/
String& String::operator=(const String &rhs) {
	free(data);
	if(rhs.data){
	/*allocte memory to this->data if success set length else set lenght to 0*/
		(data=strdup(rhs.data))?(length = rhs.length):(length = 0);
	}
	else{
	/*if rhs.data ==NULL set data to NULL ans length to 0*/
		data=NULL;
		length = 0;
	}
	return *this;
}

/**
*String& operator=(const char *str)
*/
String& String::operator=(const char *str) {
	free(data);
	if(str){
	/*allocte memory to this->data if success set length else set lenght to 0*/
		(data=strdup(str))?(length = strlen(str)):(length = 0);
	}
	else{
	/*if rhs.data ==NULL set data to NULL ans length to 0*/
		data=NULL;
		length = 0;
	}
	return *this;
}

/**
*bool equals(const String &rhs) const
*/

bool String::equals(const String &rhs) const {
/*if data and rhs != NULL check if data and str is equals*/
	if((data) && (rhs.data)){
		if (!(strcmp(data,rhs.data)) && (rhs.length == length)) {
			return true;
			}
		else {
			return false;
		}
	}
/*if data or rhs==NULL*/
	else if(!(data) && (rhs.data)){
		return false;
	}
	else if((data) && !(rhs.data)){
		return false;
	}
/*if data and rhs==NULL*/
	else{
		return true;
	}
}
/**
*bool equals(const char *rhs) const
*/
bool String::equals(const char *rhs) const {
/*if data and rhs != NULL check if data and str is equals*/
	if((data) && (rhs)){
		if (!strcmp(data, rhs)) {
			return true;
		}
		else {
			return false;
		}
	}
/*if data or rhs==NULL*/
	else if(!(data) && (rhs)){
		return false;
	}
	else if((data) && !(rhs)){
		return false;
	}
/*if data and rhs ==NULL */
	else{
		return true;
	}
}
/**
*void split(const char *delimiters, String **output, size_t *size) const
*/
void String::split(const char *delimiters, String **output, size_t *size) const{
/*check if length is 0 set size to 0*/
	if (length==0){
		*size=0;
	}
	else{
		char *temp={NULL};
	    int cnt=0;
		char *str=strdup(data);
/*count the nu, of sub strings*/
	    temp=strtok(str,delimiters);
	    while(temp!=NULL){
	        cnt++;
	        temp=strtok(NULL,delimiters);
	    }
/*allocte memory to the sub string and copy it to out*/
	    free(str);
	    unsigned int num_of_strings=cnt;
	    *size=(size_t)num_of_strings;
	    char *temp2={NULL};
		*output=(new String[num_of_strings+1]);
		cnt=0;
		char *temp_str=strdup(data);
	    temp2=strtok(temp_str,delimiters);
	    while(temp2!=NULL){
	        (*output)[cnt]=String(temp2);
	        temp2=strtok(NULL,delimiters);
	        cnt++;
	    }
	    (*output)[cnt]=String(temp2);
	    free(temp_str);
	}
}

int String::to_integer() const {
	const char nine ='9';
	const char zero = '0';
	int became_int = 0;
	int radix = 1;
	int len=this->length;
	for (int i = (len-1); i >= 0; i--) {
		if ((data[i]>=zero) && (data[i]<=nine)){
			became_int= became_int + radix * (data[i] - zero);
			radix = radix * 10;
		}
		else{
			return 0;
		}
	}
	return became_int;
	}

	String String::trim() const {
/*check if data==NULL */
		if(NULL == data){
			return NULL;
		}
	   	char space = ' ';
		char temp_str[length]; 
		int j = 0;
		int len=length;
		for (int i = 0; i <= len; i++) {
			if (data[i] != space) {
				temp_str[j] = data[i];
				j++;
			}

		}
		return temp_str;
	}