#!/bin/sh

./list > ft.txt; ./cmp > std.txt;
diff ft.txt std.txt

