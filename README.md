# C String

Counts length of `SB_CString string`, allocates new memory for it and stores both size and pointer to memory in `SB_String* self` structure.
```c
SB_Return_Code sb_string_create(SB_String* self, SB_CString string);
```

Frees the allocated memory `SB_String* self->value`.
```c
SB_Return_Code sb_string_delete(SB_String* self);
```

Returns size of `SB_CString self`.
```c
SB_ULLong sb_string_length(SB_CString self);
```

Adds `SB_CString append_string` to `SB_String* self->value`
`SB_UShort count` times.
```c
SB_Return_Code sb_string_append(SB_String* self, SB_CString append_string, SB_UShort count);
```

Returns first index of found `SB_CChar ch` in `SB_String* self->value`, the start position can be specified with `SB_ULLong start_position`.
```c
SB_ULLong sb_string_index_of(SB_String* self, SB_CChar ch, SB_ULLong start_position);
```

Stores substring in `SB_String* self`, from `SB_ULLong start` to `SB_ULLong end`.
```c
SB_Return_Code sb_string_slice(SB_String* self, SB_ULLong start, SB_ULLong end);
```

Repeats `SB_CString repeater` `SB_UShort count` times and stores new string in `SB_String* self->value`.
```c
SB_Return_Code sb_string_repeat(SB_String* self, SB_CString repeater, SB_UShort count);
```

Compare `SB_CString str_one` with `SB_CString str_two`.
```c
SB_Boolean sb_string_compare(SB_CString str_one, SB_CString str_two);
```

## Example
```c
#include "SBString.h"

#include <stdio.h>

int main(void) {
	SB_String name = {0};

	sb_string_create(&name, "Max Bubkin\0");
	printf("%s %lli\n", name.value, name.length);
	sb_string_append(&name, " Ne Bubkin\0", 1);
	printf("%s %lli\n", name.value, name.length);
	sb_string_append(&name, " Ne Bubkin \0", 5);
	printf("%s %lli\n", name.value, name.length);
	sb_string_append(&name, " Ne Bubkin \0", 120);
	printf("%s %lli\n", name.value, name.length);
	sb_string_repeat(&name, " Ne Bubkin", 120);
	printf("%s %lli\n", name.value, name.length);
	printf("%lli", sb_string_index_of(&name, 'r', 0));
	sb_string_slice(&name, 1, name.length - 5);
	printf("%s %lli", name.value, name.length);

	return 0;
}
```