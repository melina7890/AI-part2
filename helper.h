#pragma once
#include <stddef.h>
#include <assert.h>

/*
Rotates x bitwise to the left, by n bits
*/
size_t rotl32c(size_t x, char n) {
    // Adapted from https://blog.regehr.org/archives/1063
    assert(n<32);
    return (x<<n) | (x>>(-n&31));
}