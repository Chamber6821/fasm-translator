inp=source.cpp
temp=temp.cpp
out=source.txt

#g++ -DTRANSLATE -w -E -o $out $inp
g++ -DTRANSLATE -w -E -o $temp $inp
g++ -DTRANSLATE    -E -o $out $temp
rm $temp

cat $out | grep '[^[:blank:]]' | grep '^[^#]' > $out

cat $out
