uint8_t my_itoa(int32_t data, uint8_t * ptr, uint32_t base){
    if (data == 0) {
        *ptr++ = '0';
        *ptr   = '\0';
        return 2;
    }
    uint8_t *start = ptr;
    int64_t val    = data;
    if (val < 0) {
        val = -val;
    }
    while (val != 0) {
        uint32_t rem = val % base;
        val /= base;
        *ptr++ = (rem < 10)
                    ? (uint8_t)('0' + rem)
                    : (uint8_t)('A' + (rem - 10));
    }
    if (data < 0) {
        *ptr++ = '-';
    }
    *ptr = '\0';
    uint8_t len = (uint8_t)((ptr - start) + 1);
    uint8_t *lo = start;
    uint8_t *hi = ptr - 1;
    while (lo < hi) {
        uint8_t tmp = *lo;
        *lo++ = *hi;
        *hi-- = tmp;
    }
    return len;
}

int32_t my_atoi(uint8_t * ptr, uint8_t digits, uint32_t base){
    if (ptr == NULL || digits == 0 || base < 2 || base > 16) {
        return 0;
    }
    int sign = 1;
    uint8_t *p = ptr;
    if (*p == '-') {
        sign = -1;
        p++;
        digits--;
    }
    else if (*p == '+') {
        p++;
        digits--;
    }
    int32_t result = 0;
    while (digits--) {
        uint8_t ch = *p++;
        uint32_t value;
        if (ch >= '0' && ch <= '9') {
            value = ch - '0';
        }
        else if (ch >= 'A' && ch <= 'F') {
            value = ch - 'A' + 10;
        }
        else if (ch >= 'a' && ch <= 'f') {
            value = ch - 'a' + 10;
        }
        else {
            break;
        }
        result = result * (int32_t)base + (int32_t)value;
    }
    return sign * result;
}
