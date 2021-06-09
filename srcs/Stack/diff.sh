#!/bin/sh

./stack > ft.txt; ./cmp > std.txt;
diff ft.txt std.txt
