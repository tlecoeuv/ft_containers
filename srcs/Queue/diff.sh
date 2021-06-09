#!/bin/sh

./queue > ft.txt; ./cmp > std.txt;
diff ft.txt std.txt
