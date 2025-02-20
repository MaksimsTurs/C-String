# C String

Counts length of `const SB_String_Ptr string`, allocates new memory for it and stores both size and pointer to memory in `SB_String* self` structure.
```c
SB_Return_Code sb_build(SB_String* self, const SB_String_Ptr string);
```

Frees the allocated memory `SB_String* self->value`.
```c
SB_Return_Code sb_free(SB_String* self);
```

Returns size of `const SB_String_Ptr self`.
```c
SB_ULLong sb_length(const SB_String_Ptr self);
```

Adds `SB_String_Ptr append_string` to `SB_String* self->value`
`const SB_UChar count` times.
```c
SB_Return_Code sb_append(SB_String* self, SB_String_Ptr append_string, const SB_UChar count);
```

Returns first index of found `const SB_Char ch` in `SB_String* self->value`, the start position can be specified with `const SB_ULLong start_position`.
```c
SB_LLong sb_index_of(SB_String* self, const SB_Char ch, const SB_ULLong start_position);
```

Stores substring in `SB_String* self`, from `const SB_ULLong start` to `const SB_ULLong end`.
```c
SB_Return_Code sb_slice(SB_String* self, const SB_ULLong start, const SB_ULLong end);
```

Compare `const SB_String_Ptr str_one` with `const SB_String_Ptr str_two`.
```c
SB_Bool sb_compare(const SB_String_Ptr str_one, const SB_String_Ptr str_two);
```

Create slice of strings, separate a string in to string array with `const SB_Char spliter`.
```c
SB_Return_Code sb_split(SB_Slices* self, const SB_String_Ptr to_split, const SB_Char spliter);
```

Delete array of sliced strings.
```c
SB_Return_Code sb_split_free(SB_Slices* self);
```

## Example
```c
#include "SBString.h"

#include <stdio.h>

SB_String a = {0};
SB_Slices slice = {0};

void TEST_sb_build() {
	sb_build(&a, "Simple string");
	printf("TEST(1):[%s %lli]\n", a.value, a.length);
	sb_free(&a);

	sb_build(&a, "Simple string but bigger lol kek cheburek hahah");
	printf("TEST(2):[%s %lli]\n", a.value, a.length);
	sb_free(&a);

	sb_build(&a, "Simple string more kdcklscksdkscknskcsncklsdncksdcnskldcsnklcnsknclksdncskldcnsdklncscnsklcsncskldncsklcnskcsldcnsdklcsndcdkncklsc");
	printf("TEST(3):[%s %lli]\n", a.value, a.length);
	sb_free(&a);

	sb_build(&a, "Simple string okkklllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllllkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkklkcsksdkcnkldclsdclsdncsdknkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkkk");
	printf("TEST(4):[%s %lli]\n", a.value, a.length);
	sb_free(&a);
}

void TEST_sb_append() {
	sb_build(&a, "Scum");

	sb_append(&a, "SUS", 1);
	printf("TEST(1):[%s %lli]\n", a.value, a.length);

	sb_append(&a, "SUS", 50);
	printf("TEST(2):[%s %lli]\n", a.value, a.length);

	sb_append(&a, "SUS", 255);
	printf("TEST(3):[%s %lli]\n", a.value, a.length);

	sb_free(&a);
	sb_build(&a, "Scum");

	sb_append(&a, a.value, 5);
	printf("TEST(4):[%s %lli]\n", a.value, a.length);

	sb_append(&a, a.value, 50);
	printf("TEST(5):[%s %lli]\n", a.value, a.length);

	sb_append(&a, a.value, 255);
	printf("TEST(6):[%s %lli]\n", a.value, a.length);
}

void TEST_sb_split() {
	sb_split(&slice, "Suskdckc c ekcelrlkcnerlkc elrcrekcnreckreclrekckl eclecekck ecle roekree Sus dick kurwa cock", ' ');
	for(int index = 0; index < slice.size; index++)
		printf("%.*s\n", slice.items[index].length, slice.items[index].start);
}

void TEST_sb_slice() {
	sb_build(&a, "Suck");
	printf("%s\n", a.value);
	sb_slice(&a, 1, a.length-2);
	printf("%s\n", a.value);
}

int main(void) {
	TEST_sb_build();
	printf("\n#############################################################################################################################\n");
	TEST_sb_append();
	printf("\n#############################################################################################################################\n");
	TEST_sb_split();
	printf("\n#############################################################################################################################\n");
	TEST_sb_slice();
	printf("\n#############################################################################################################################\n");
	
	return 0;
}
```