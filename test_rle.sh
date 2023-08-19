cc -Werror -Wextra -Wall rle.c -o rle
./rle "AAAbbCCddEEEEfGhIJJJkkkLLmmNoo" | hexdump -C
