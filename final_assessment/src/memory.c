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
  for(i = 0; i < size; i++) {
    set_value(ptr, i, value);
  }
}

void clear_all(char * ptr, unsigned int size){
  set_all(ptr, 0, size);
}

uint8_t * my_memmove(uint8_t * src, uint8_t * dst, size_t length){

}

uint8_t * my_memcopy(uint8_t * src, uint8_t * dst, size_t length){

}

uint8_t * my_memset(uint8_t * src, size_t length, uint8_t value){

}

uint8_t * my_memzero(uint8_t * src, size_t length){

}

uint8_t * my_reverse(uint8_t * src, size_t length){

}

int32_t * reserve_words(size_t length){

}

void free_words(int32_t * src){

}

