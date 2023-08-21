rm compiled/"$1"
mkdir compiled
gcc -g src/"$1".c -o compiled/"$1"
chmod u+x ./compiled/"$1"
./compiled/"$1"
