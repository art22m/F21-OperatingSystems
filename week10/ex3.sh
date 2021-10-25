touch _ex3.txt
echo 'Murashko Artem' > _ex3.txt
chmod -x _ex3.txt
ls -l _ex3.txt > ex3.txt
chmod uo=rwx _ex3.txt
ls -l _ex3.txt >> ex3.txt
chmod g=u _ex3.txt
ls -l _ex3.txt >> ex3.txt
echo '660 is the same as -rw-rw---- | Means only owner and group have permission to read/write' >> ex3.txt
echo '775 is the same as -rwxrwxr-x | Means owner and group have all permissions and others only read/execute' >> ex3.txt
echo '777 is the same as -rwxrwxrwx | Means owner, group and others have all permissions ' >> ex3.txt