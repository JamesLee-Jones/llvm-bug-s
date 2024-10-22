SCRIPT_DIR=$(dirname "$0")
cd $SCRIPT_DIR
OUTPUT1=$($CC test.c -c -fPIE -O1 -o test.o; gcc test.o -o a.out; ./a.out)
RETURN1=$?
if [ "$RETURN1" != 0 ]; then
  exit 1
fi

