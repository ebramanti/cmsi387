I/O Gymnastics
==========

##1. Create an `ssh` tunnel from this computer to a service that is visible from another `ssh`-capable computer (but, of course, not necessarily visible from the computer you’re using). Then, access that service from your computer through localhost and the tunneled port number. 

    ssh -L 2001:my.cs.lmu.edu:80 tbramant@my.cs.lmu.edu

Submit a screenshot of your successful connection to the remote service via the tunnel.

![Screenshot](https://raw.github.com/jadengore/cmsi387/master/homework/io-gymnastics/ssh-tunnel.png)

##2. Run something lengthy (`ping`, `vm_stat/vmstat`, loooooong download, finding the quadrillionth prime number...) inside `screen`; logout of that computer entirely, login again, and reconnect to `screen` to prove to yourself that the process has continued to run without interruption.

    ssh tbramant@my.cs.lmu.edu
    tbramant@my.cs.lmu.edu's password: 
    screen
    CTRL + AD
    [detached from 5410.pts-3.ab201]
    CTRL + D
    logout
    Connection to my.cs.lmu.edu closed.

    ssh tbramant@my.cs.lmu.edu
    tbramant@my.cs.lmu.edu's password:
    screen -r

Submit screenshots of your long-running command before you logged out, then after you reconnected to it.