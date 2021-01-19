#include <iostream>
#include "String.h"
#include <stdbool.h>
#include<string.h>
using namespace std;

/*String() - C'tor*/
String::String() {};
/*String(const String &str)*/
String::String(const String &str) : 
	data(str.data), length (str.length) {};
/*String& operator=(const String &rhs)*/
String& String::operator=(const String &rhs) {
	data = rhs.data;
	length = rhs.length;
	return *this;
}

/*String& operator=(const char *str);*/
String& String::operator=(const char *str) {
	strcpy(data,str);
	length = strlen(str);
	return *this;
}
/*String(const char *str)*/
String::String(const char *str){
    this->length=(strlen(str));
    this->data=strdup(str);
}
/*~String() - D'tor*/
String::~String() {};


/*bool equals(const String &rhs) const*/

bool String::equals(const String &rhs) const {
	if (!(strcmp(data,rhs.data)) && (rhs.length == length)) {
		return true;
		}
	else {
		return false;
	}
}
	/**
	 * @brief Returns true iff the contents of this equals to rhs
	 */
/* *bool equals(const char *rhs) const*/
bool String::equals(const char *rhs) const {
	if (!strcmp(data, rhs)) {
		return true;
	}
	else {
		return false;
	}
}

	/**
	 * @brief Splits this to several sub-strings according to delimiters.
	 * Allocates memory for output that the user must delete (using delete[]).
	 * @note Does not affect this.
	 * @note If "output" is set to NULL, do not allocated memory, only
	 * compute "size".
	 */
/*void split(const char *delimiters, String **output, size_t *size) const*/
void String::split(const char *delimiters, String **output, size_t *size) const {
	char *temp;
    int cnt=0;
	char *str=this->data;
	String *new_strings = new String[18];
    temp=strtok(str,delimiters);
    while(temp!=NULL){
        cout<<temp<<endl;
        new_strings[cnt].data=temp;
		new_strings[cnt].length=strlen(temp);
        cnt++;
        temp=strtok(NULL,delimiters);

    }
	/*String *new_strings = new String[cnt];
	cnt=0;
    temp=strtok(str,delimiters);
    while(temp!=NULL){
        cout<<temp<<endl;
		new_strings[cnt].data=temp;
		new_strings[cnt].length=strlen(temp);
        temp=strtok(NULL,delimiters);
        cnt++;
    }*/
	output=new_strings;
	*size=cnt;
}

	/**
	 * @brief Try to convert this to an integer. Returns 0 on error.
	 * think how to return 0 on error..??
	 */
int String::to_integer() const {
	const char zero = '0';
	int became_int = 0;
	int radix = 1;
	int len=this->length;
	for (int i = len; i >= 0; i--) {
		became_int= became_int + radix * (this->data[i] - zero);
		radix = radix * 10;
	}
	return became_int;
	}

	
	//String trim() const;
	/**
	 * @brief make a new str and go over the given str if the curr char isnt
	 * ' ' copy the char to the new str else we continue
	 */
	String String::trim() const {
		char space = ' ';
		int temp = 1;
		char *temp_str = new char[strlen(data)+1];
		int j = 0;
		int len=this->length;
		for (int i = 0; i <= len; i++) {
			if (data[i] != space) {
				temp_str[j] = data[i];
				j++;
			}

		}
		return temp_str;
	}
  
