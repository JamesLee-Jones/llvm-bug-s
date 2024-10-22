SCRIPT_DIR=$(dirname "$0")
cd $SCRIPT_DIR
OUTPUT1=$($CC error.c -c -fPIE -O1 -o error.o; gcc error.o -o a.out; ./a.out)
RETURN1=$?
OUTPUT2=$($CC noerror.c -c -fPIE -O1 -o noerror.o; gcc noerror.o -o a.out; ./a.out)
RETURN2=$?
if [ "$OUTPUT1" != "$OUTPUT2" ] || [ "$RETURN1" != "$RETURN2" ]; then
  exit 1
fi

