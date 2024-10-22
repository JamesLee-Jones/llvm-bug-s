SCRIPT_DIR=$(dirname "$0")
cd $SCRIPT_DIR
OUTPUT1=$($CXX -c -O0 bug.c -fPIE -o bug.o; gcc bug.o -o a.out; ./a.out)
RETURN1=$?
OUTPUT2=$($CXX -c -O1 bug.c -fPIE -o bug.o; gcc bug.o -o a.out; ./a.out)
RETURN2=$?
if [ "$OUTPUT1" != "$OUTPUT2" ] || [ "$RETURN1" != "$RETURN2" ]; then
  exit 1
fi

