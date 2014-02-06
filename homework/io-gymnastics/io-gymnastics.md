I/O Gymnastics
==========

##1. Create an `ssh` tunnel from this computer to a service that is visible from another `ssh`-capable computer (but, of course, not necessarily visible from the computer you’re using). Then, access that service from your computer through localhost and the tunneled port number. 

    ssh -L 2001:my.cs.lmu.edu:80 tbramant@my.cs.lmu.edu

Submit a screenshot of your successful connection to the remote service via the tunnel.

![Screenshot](https://raw.github.com/jadengore/cmsi387/master/homework/io-gymnastics/ssh-tunnel.png)
