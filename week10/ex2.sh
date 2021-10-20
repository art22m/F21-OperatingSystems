touch ../week01/file.txt
echo 'Murashko Artem' >> ../week01/file.txt
link ../week01/file.txt _ex2.txt
find .. -inum "$(ls -i _ex2.txt | awk '{print $1}')"  > ex2.txt
find .. -inum "$(ls -i _ex2.txt | awk '{print $1}')" -exec rm {} \; >> ex2.txt