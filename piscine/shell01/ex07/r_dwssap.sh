cat /etc/passwd | sed '/^#/d' | awk '{FS=":"} (NR+1)%2 {print $1}' | rev | sort -r | awk "NR>=$FT_LINE1 && NR<=$FT_LINE2" | tr -s '\n' ',' | sed 's/,/, /g' | sed 's/\, $/./' | tr -d '\n'
