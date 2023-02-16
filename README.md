
LeakSanitizer - https://github.com/mhahnFr/LeakSanitizer

commands for LeakSanitizer:

cc *.c -L../LeakSanitizer -llsan -lc++   -Wno-gnu-include-next -I ../LeakSanitizer && ./a.out

cc *.c -fsanitize=address && ./a.out




for paco strict increase timeout period to 500 seconds:

paco --strict --timeout 500
