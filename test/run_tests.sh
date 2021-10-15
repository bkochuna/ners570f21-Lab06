# Build file with main to run all tests
f="scratch_run_file.cpp"
rm -rf "$f"
touch "$f"
echo "#include \"unit_test_framework.h\"" >> "$f"

# Automatically include tests from any cpp file that starts with "test"
for fTest in test*.cpp; do
    printf "#include \"%s\"\n" "$fTest" >> "$f"
done

printf "\nTEST_MAIN()\n" >> "$f"


echo "=============================================================="
echo "                    Single precision tests                    "
echo "=============================================================="
g++ -Wall -Werror -pedantic -O1 -std=c++11 -DFP_TYPE=float "$f" -o test_single.exe
./test_single.exe
printf "\n"
echo "=============================================================="
echo "                    Double precision tests                    "
echo "=============================================================="
g++ -Wall -Werror -pedantic -O1 -std=c++11 -DFP_TYPE=double "$f" -o test_double.exe
./test_double.exe

rm -rf test_single.exe
rm -rf test_double.exe
rm -rf "$f"