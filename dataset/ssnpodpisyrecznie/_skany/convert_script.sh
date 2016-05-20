#!/bin/bash
for file in *.bmp;
do
	convert "$file" -monochrome "`basename $file .bmp`BlackWhite.bmp"
done

