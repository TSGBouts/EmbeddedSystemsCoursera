

void set_value(char * ptr, unsigned int index, char value){
  ptr[index] = value;
}

void clear_value(char * ptr, unsigned int index){
  set_value(ptr, index, 0);
}

char get_value(char * ptr, unsigned int index){
  return ptr[index];
}

void set_all(char * ptr, char value, unsigned int size){
  unsigned int i;
  for(i = 0; i < size; i++){
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){
    if (dst < src){
        uint8_t *d = dst;
        uint8_t *s = src;
        while (length--){
            *d++ = *s++;
        }
    }
    else {
        uint8_t *d = dst + length - 1;
        uint8_t *s = src + length - 1;
        while (length--){
            *d-- = *s--;
        }
    }
    return dst;
}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){
    uint8_t *d = dst;
    uint8_t *s = src;
    while (length--){
        *d++ = *s++;
    }
    return dst;
}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){
    uint8_t *p = src;
    while (length--){
        *p++ = value;
    }
    return src;
}

uint8_t * my_memzero(uint8_t * src, size_t length){
    uint8_t *p = src;
    while (length--){
        *p++ = 0;
    }
    return src;
}

uint8_t * my_reverse(uint8_t * src, size_t length){
    if (length < 2){
        return src;
    }
    uint8_t *front = src;
    uint8_t *back  = src + length - 1;
    uint8_t  tmp;
    while (front < back) {
        tmp      = *front;
        *front++ = *back;
        *back--  = tmp;
    }
    return src;
}

int32_t * reserve_words(size_t length){
    int32_t *ptr = (int32_t *)malloc(length * sizeof(int32_t));
    if (ptr == NULL){
        return NULL;
    }
    return ptr;
}

void free_words(int32_t * src){
    free(src);
}

