# C String

Create a new `String` struct.
```c
String string_create(const char* string_value);
```
Count length of string with use of a `\0`.
```c
size_t string_length(const char* string);
```
Append a `append_string` to the `string->value`.
```c
size_t string_append(String* string, const char* append_string);
```
Get first index of `character` in `string->value`, `start_position` can be passed as param.
```c
size_t string_index_of(String* string, const char character, size_t start_position);
```
Slice string from `start` to `end`.
```c
size_t string_slice(String* string, size_t start, size_t end);
```
Repeat a `repeater` with `repeater_count` count.
```c
size_t string_repeat(String* string, const char* repeater, size_t repeater_count);
```
Compare two strings.
```c
unsigned char string_compare(const char* str_one, const char* str_two);
```
## Example
```c
#include "String.h"

int main(void) {
	String str = string_create("Some string\0");

	string_append(&str, "append");
	string_compare(str.value, "compare");
	string_index_of(&str, 's', 0);
	string_length(str.value);
	string_repeat(&str, "repeat", 10);
	string_slice(&str, 2, str.length);

	return 0;
}
```