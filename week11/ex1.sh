sudo fallocate -l 50M lofs.img
sudo losetup -f lof.img
sudo losetup -f lofs.img
losetup -a
sudo mkfs.ext4 "$(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)"
mkdir lofsdisk
sudo mount "$(losetup -a | grep 'lofs.img' | awk '{print $1}' | cut -d ':' -f 1)" ./lofsdisk