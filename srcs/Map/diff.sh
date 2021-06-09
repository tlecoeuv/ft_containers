#!/bin/sh

./map > ft.txt; ./cmp > std.txt;
diff ft.txt std.txt
