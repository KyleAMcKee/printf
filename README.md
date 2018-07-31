# 42 Project: Printf

This program was made to mimic the functionality of printf. Writing well-structured and extensible code was necessary to complete this project. The concept of variadic functions was also introduced.

* Types handled:
	- `%s / %S  (string and wide-string)`
  - `%c / %C  (char and wide-char)`
  - `%x / %X  (hexidecimal lower and upper case)`
  - `%d / %i  (integer)`
  - `%o       (octal)`
  - `%p       (pointer)`
  - `%u       (unsigned integer)`
* Flags handled:
	- `+        (prepends + for positive numbers)`
  - `0        (prepends zeros)`
  - `-        (left-align)`
  - `#        (0x prepended to hex and octal types)`
  - `space    (prepends space for positive numbers)`
* Modifiers handled:
	- `l        (long)`
  - `ll       (long long)`
  - `h        (short)`
  - `hh       (char)`
  - `j        (intmax_t)`
  - `z        (size_t)`
* Additional functionality added:
	- `%b       (binary)`
  - `Color    (binary)`
