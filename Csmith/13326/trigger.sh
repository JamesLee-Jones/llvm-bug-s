SCRIPT_DIR=$(dirname "$0")
cd $SCRIPT_DIR
OUTPUT1=$($CC -c -O1 small.c -fPIE -o small.o; gcc small.o -o a.out; ./a.out)
RETURN1=$?
OUTPUT2=$($CC -c -O small.c -fPIE -o small.o; gcc small.o -o a.out; ./a.out)
RETURN2=$?
if [ "$OUTPUT1" != "$OUTPUT2" ] || [ "$RETURN1" != "$RETURN2" ]; then
  exit 1
fi

