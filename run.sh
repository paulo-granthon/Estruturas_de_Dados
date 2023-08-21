rm compiled/insert
mkdir compiled
gcc -g src/insert.c -o compiled/insert
chmod u+x ./compiled/insert
./compiled/insert
