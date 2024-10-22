SCRIPT_DIR=$(dirname "$0")
cd $SCRIPT_DIR
OUTPUT1=$($CC -c small.c -fPIE -o small.o; gcc small.o -o a.out; ./a.out)
RETURN1=$?
if [ "$OUTPUT1" != 0 ] || [ "$RETURN1" != 0 ]; then
  exit 1
fi

