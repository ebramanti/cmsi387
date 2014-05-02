CSI: FS
========

## Part 1: Terminal Commands

    jadengore@Vubuntu-Air:~/Desktop/cmsi387/homework/csi-fs$ dd if=/dev/zero of=image count=1024
    1024+0 records in
    1024+0 records out
    524288 bytes (524 kB) copied, 0.00355111 s, 148 MB/s
    jadengore@Vubuntu-Air:~/Desktop/cmsi387/homework/csi-fs$ mke2fs image
    mke2fs 1.42 (29-Nov-2011)
    image is not a block special device.
    Proceed anyway? (y,n) y 
    Discarding device blocks: done                            
    Filesystem label=
    OS type: Linux
    Block size=1024 (log=0)
    Fragment size=1024 (log=0)
    Stride=0 blocks, Stripe width=0 blocks
    64 inodes, 512 blocks
    25 blocks (4.88%) reserved for the super user
    First data block=1
    Maximum filesystem blocks=524288
    1 block group
    8192 blocks per group, 8192 fragments per group
    64 inodes per group
    Allocating group tables: done                            
    Writing inode tables: done                            
    Writing superblocks and filesystem accounting information: done
    jadengore@Vubuntu-Air:~/Desktop/cmsi387/homework/csi-fs$ sudo mount -o loop -o nosuid -o nodev image ~/Desktop/sys
    jadengore@Vubuntu-Air:~/Desktop/cmsi387/homework/csi-fs$ df
    Filesystem     1K-blocks     Used Available Use% Mounted on
    /dev/sda1       23606716 10738048  11646476  48% /
    udev              498996        4    498992   1% /dev
    tmpfs             203428      760    202668   1% /run
    none                5120        0      5120   0% /run/lock
    none              508560      124    508436   1% /run/shm
    /dev/loop0           499       15       459   4% /home/jadengore/Desktop/sys    
    jadengore@Vubuntu-Air:~/Desktop/cmsi387/homework/csi-fs$ cd ../../../sys/
    jadengore@Vubuntu-Air:~/Desktop/sys$ ls
    lost+found
    jadengore@Vubuntu-Air:~/Desktop/sys$ touch text1.txt
    jadengore@Vubuntu-Air:~/Desktop/sys$ mkdir willy
    jadengore@Vubuntu-Air:~/Desktop/sys$ cd willy/
    jadengore@Vubuntu-Air:~/Desktop/sys/willy$ touch willy.txt
    jadengore@Vubuntu-Air:~/Desktop/sys/willy$ ln -s ../
    lost+found/ text1.txt   willy/      
    jadengore@Vubuntu-Air:~/Desktop/sys/willy$ ln -s ../
    lost+found/ text1.txt   willy/      
    jadengore@Vubuntu-Air:~/Desktop/sys/willy$ ln -s ../text1.txt willylinker
    jadengore@Vubuntu-Air:~/Desktop/sys/willy$ ls
    willylinker  willy.txt
    jadengore@Vubuntu-Air:~/Desktop/sys/willy$ cd ..
    jadengore@Vubuntu-Air:~/Desktop/sys$ ln willy/willy.txt willylink
    jadengore@Vubuntu-Air:~/Desktop/sys$ ls
    lost+found  text1.txt  willy  willylink
    jadengore@Vubuntu-Air:~/Desktop/sys$ ls -l
    total 13
    drwx------ 2 root      root      12288 May  1 19:02 lost+found
    -rw-rw-r-- 1 jadengore jadengore     0 May  1 19:07 text1.txt
    drwxrwxr-x 2 jadengore jadengore  1024 May  1 19:09 willy
    -rw-rw-r-- 2 jadengore jadengore     0 May  1 19:08 willylink
