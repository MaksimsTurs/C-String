#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#include "String.h"

String string_create(const char *string_value) {
	String new_string = {0};
	size_t length = string_length(string_value);
	
	new_string.length = length;
	new_string.value = (char*)malloc(length);
	if(new_string.value == NULL) {
		return new_string;
	}
	
	memmove(new_string.value, string_value, length);
	return new_string;
}

size_t string_append(String* string, const char* append_string) {
	size_t append_length = string_length(append_string);
	size_t new_length = string->length + append_length;

	char* new_string = (char*)realloc(string->value, new_length);
	if(string->value == NULL) {
		return string->length;
	}

	memmove(new_string + string->length, append_string, append_length);

	string->length = new_length;
	string->value = new_string;

	return new_length;
}

size_t string_index_of(String* string, const char character, size_t start_position) {
	for(size_t position = start_position; position < string->length; position++) {
		if(string->value[position] == character) {
			return position;
		}
	}
	return 0;
}

size_t string_slice(String* string, size_t start, size_t end) {
	if(start > string->length || end > string->length) {
		return 0;
	}

	size_t base = start + llabs((long long)(end - string->length));
	size_t new_string_length = string->length - base;

	char* new_string = (char*)malloc(new_string_length);
	if(new_string == NULL) {
		return 0;
	}

	memmove(new_string, string->value + start, new_string_length);
	new_string[new_string_length] = '\0';
	free(string->value);

	string->value = new_string;
	string->length = new_string_length;
	return new_string_length;
}

size_t string_repeat(String* string, const char* repeater, size_t repeater_count) {
	size_t repeater_length = string_length(repeater);
	size_t new_string_length = string->length + (repeater_count * repeater_length);
	size_t index = 0;

	string->value = (char*)realloc(string->value, new_string_length);
	if(string->value == NULL) {
		return string->length;
	}

	string->value += string->length;
	while(repeater_count > index) {
		memmove(string->value, repeater, repeater_length);
		string->value += ((index || 1) * repeater_length);
		index++;
	}

	string->length = new_string_length;
	string->value -= new_string_length;
	string->value[new_string_length] = '\0';
	return new_string_length;
}

size_t string_length(const char *str) {
	size_t length = 0;
	while(*str++) {
		length++;
	}
	str -= length;
	return length;
}

unsigned char string_compare(const char* string_one, const char* string_two) {
	return strcmp(string_one, string_two) == 0;
}