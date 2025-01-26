typedef struct String {
	char *value;
	size_t length;
} String;

String string_create(const char* string_value);
size_t string_length(const char* string);
size_t string_append(String* string, const char* append_string);
size_t string_index_of(String* string, const char character, size_t start_position);
size_t string_slice(String* string, size_t start, size_t end);
unsigned char string_compare(const char* str_one, const char* str_two);