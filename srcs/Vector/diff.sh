#!/bin/sh

./vector > ft.txt; ./cmp > std.txt;
diff ft.txt std.txt
