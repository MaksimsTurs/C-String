#include "SBString.h"

SB_Return_Code sb_string_create(SB_String* self, SB_CString string) {
	SB_ULLong length = sb_string_length(string);
	
	self->length = length;
	self->value = (SB_VString)malloc(length);
	if(self->value == NULL)
		return SB_ERROR_MEMALLOC;
	
	memcpy(self->value, string, length);
	self->value[length] = '\0';

	return SB_SUCCESS;
}

SB_Return_Code sb_string_delete(SB_String* self) {
	if(self == NULL || self->value == NULL)
		return SB_ERROR_NULL_PTR;

	free(self->value);

	return SB_SUCCESS;
}

SB_Return_Code sb_string_append(SB_String* self, SB_CString append_string, SB_UShort count) {
	SB_ULLong append_length = sb_string_length(append_string);
	SB_ULLong string_new_length = self->length + append_length * count;
	SB_UShort append_count = !count ? 1 : count;

	self->value = (SB_VString)realloc(self->value, string_new_length * append_count);
	if(self->value == NULL)
		return SB_ERROR_MEMALLOC;
	
	self->value += self->length;
	if(append_count == 1) {
		memcpy(self->value, append_string, append_length);
	} else {
		SB_UShort index = 0;

		while(index < append_count) {
			memcpy(self->value + (append_length * index), append_string, append_length);
			index++;
		}
	}
	self->value -= self->length;
	
	self->length = string_new_length;
	self->value[self->length] = '\0';

	return SB_SUCCESS;
}

SB_Return_Code sb_string_repeat(SB_String* self, SB_CString repeater, SB_UShort count) {
	if(count == 0) 
		return SB_ERROR_INVALID_COUNT;

	SB_ULLong repeater_length = sb_string_length(repeater);
	SB_ULLong new_string_length = self->length + (count * repeater_length);
	SB_UShort index = 0;

	self->value = (SB_VString)realloc(self->value, new_string_length);
	if(self->value == NULL)
		return SB_ERROR_MEMALLOC;

	self->value += self->length;
	if(count == 1) {
		memcpy(self->value + (repeater_length * index), repeater, repeater_length);
	} else {
		while(index < count) {
			memcpy(self->value + (repeater_length * index), repeater, repeater_length);
			index++;
		}
	}
	self->value -= self->length;

	self->length = new_string_length;
	self->value[new_string_length] = '\0';

	return SB_SUCCESS;
}

SB_ULLong sb_string_index_of(SB_String* self, SB_CChar ch, SB_ULLong start_position) {
	for(SB_ULLong position = start_position; position < self->length; position++) {
		if(self->value[position] == ch)
			return position;
	}

	return 0;
}

SB_Return_Code sb_string_slice(SB_String* self, SB_ULLong start, SB_ULLong end) {
	if(start > self->length || end > self->length || start > end)
		return SB_ERROR_INVALID_POSITION;

	SB_ULLong new_string_length = (end - start);

	self->length = new_string_length;
	SB_VString new_str = (SB_VString)malloc(new_string_length + 1);
	if(self->value == NULL)
		return SB_ERROR_MEMALLOC;

	memcpy(new_str, self->value + start, new_string_length + 1);
	free(self->value);
	self->value = new_str;
	self->value[self->length] = '\0';

	return SB_SUCCESS;
}

SB_ULLong sb_string_length(SB_CString self) {
	SB_ULLong length = 0;
	SB_CString string_cp = self;

	while(*string_cp++ != SB_NULL_TERMINATOR)
		length++;

	return length;
}

SB_Boolean sb_string_compare(SB_CString str_one, SB_CString str_two) {
	return strcmp(str_one, str_two) == 0;
}