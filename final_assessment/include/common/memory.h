#ifndef __MEMORY_H__
#define __MEMORY_H__

void set_value(char * ptr, unsigned int index, char value);

void clear_value(char * ptr, unsigned int index);

char get_value(char * ptr, unsigned int index);

void set_all(char * ptr, char value, unsigned int size);

void clear_all(char * ptr, unsigned int size);

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length);

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length);

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value);

uint8_t * my_memzero(uint8_t * src, size_t length);

uint8_t * my_reverse(uint8_t * src, size_t length);

int32_t * reserve_words(size_t length);

void free_words(int32_t * src);

#endif /* __MEMORY_H__ */
