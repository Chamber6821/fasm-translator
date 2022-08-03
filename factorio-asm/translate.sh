in_file=$1
out_file=$2
temporary=__temp_of_translation__.cpp

echo "Translate '$in_file' file to '$out_file' file"

out_dir=$(dirname "$out_file")
mkdir -p $out_dir

g++ -DTRANSLATE -w -E -Ifactorio-asm  -o $temporary $in_file
g++ -DTRANSLATE    -E -o $out_file $temporary
rm $temporary

cat $out_file | grep '[^[:blank:]]' | grep '^[^#]' > $out_file
