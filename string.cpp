#include <iostream>
#include "string.h"
#include <stdbool.h>
#include<string.h>
using namespace std;

/*String() - C'tor*/
String::String()
: data(NULL) ,length(0){}

/*String(const String &str)*/
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

/*String(const char *str)*/
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
/*String& operator=(const String &rhs)*/
String& String::operator=(const String &rhs) {
	free(data);
	if(rhs.data){
		(data=strdup(rhs.data))?(length = rhs.length):(length = 0);
	}
	else{
		data=NULL;
		length = 0;
	}
	return *this;
}

/*String& operator=(const char *str);*/
String& String::operator=(const char *str) {
	free(data);
	if(str){
		(data=strdup(str))?(length = strlen(str)):(length = 0);
	}
	else{
		data=NULL;
		length = 0;
	}
	return *this;
}

/*bool equals(const String &rhs) const*/

bool String::equals(const String &rhs) const {
	if((data) && (rhs.data)){
		if (!(strcmp(data,rhs.data)) && (rhs.length == length)) {
			return true;
			}
		else {
			return false;
		}
	}
	else if(!(data) && (rhs.data)){
		return false;
	}
	else if((data) && !(rhs.data)){
		return false;
	}
	else{
		return true;
	}
}
/* bool equals(const char *rhs) const*/
bool String::equals(const char *rhs) const {
	if((data) && (rhs)){
		if (!strcmp(data, rhs)) {
			return true;
		}
		else {
			return false;
		}
	}
	else if(!(data) && (rhs)){
		return false;
	}
	else if((data) && !(rhs)){
		return false;
	}
	else{
		return true;
	}
}
/*void split(const char *delimiters, String **output, size_t *size) const*/
void String::split(const char *delimiters, String **output, size_t *size) const{
	if (length==0){
		*size=0;
		exit;
	}
	else{
	char *temp={NULL};
    int cnt=0;
	char *str=strdup(data);
	
    temp=strtok(str,delimiters);
    while(temp!=NULL){
        cnt++;
        temp=strtok(NULL,delimiters);
    }
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


	/**
	 * @brief Try to convert this to an integer. Returns 0 on error.
	 * think how to return 0 on error..??
	 */
int String::to_integer() const {
	const char nine ='9';
	const char zero = '0';
	int became_int = 0;
	int radix = 1;
	int len=this->length;
	for (int i = (len-1); i >= 0; i--) {
		if ((data[i]>zero) && (data[i]<nine)){
			became_int= became_int + radix * (data[i] - zero);
			radix = radix * 10;
		}
		else{
			return 0;
		}
	}
	return became_int;
	}

	
	//String trim() const;
	/**
	 * @brief make a new str and go over the given str if the curr char isnt
	 * ' ' copy the char to the new str else we continue
	 */
	String String::trim() const {
		if(NULL == data){
			return NULL;
		}
	   	char space = ' ';
		//int temp = 1;
		//char *temp_str = new char[strlen(data)+1];
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