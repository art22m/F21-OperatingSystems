sudo chmod 777 lofsdisk

cd lofsdisk

echo "Murashko Artem [1]" >> file1 && echo "Murashko Artem [2]" >> file2
mkdir bin && mkdir lib && mkdir lib/x86_64-linux-gnu && mkdir lib64
cp /bin/bash bin/bash && cp /bin/ls bin/ls && cp /bin/cat bin/cat && cp /bin/echo bin/echo
cmd=("bash" "ls" "cat" "echo")

for i in $cmd
do
   list="$(ldd /bin/$i | awk 'NF == 4 {print $3}; NF == 2 {print $1}' | grep /lib)"
   for j in $list
   do
      cp -v "$j" ".$j"
   done
done

gcc ex2.c -o ex2.o
sudo chroot . ./ex2.o >> ex2.txt