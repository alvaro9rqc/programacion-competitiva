echo "$1 $2"
i="$1"
while(( "$i" <= "$2" )); do
  echo "$i" | ./h2.out| python3 hv.py "$i"
  if [ "$?" -ne "0" ]; then
    break
  fi
  (( i += 7))
done

