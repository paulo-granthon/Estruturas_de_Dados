if [ "-d compiled/\"$1\"" ]; then rm compiled/"$1"; fi
if [ ! -d "compiled" ]; then mkdir compiled; fi
gcc -g src/"$1".c -o compiled/"$1"
chmod u+x ./compiled/"$1"
./compiled/"$1"
