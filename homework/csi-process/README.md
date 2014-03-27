CSI: Process
============

Use long-running invocations (i.e., huge numbers) of the `thread-java` and/or `thread-posix` sample programs to do the following on at least two operating systems chosen from Linux, Mac OS X, and Microsoft Windows. The chosen two can be different for each task, depending on what is possible or easy for each operating system:

1. Invoke the long-running program, send it to the background, and run another program that produces output.Take a screenshot of that big hot terminal mess.

2. Invoke the long-running program, and use a process monitor on the operating system platform to see that program's threads. How do the different operating systems represent the threads? Note any major similarities and differences, accompanied by screenshot evidence.

####Mac OS

I ram `thread-java` on my Mac first, suspending the process temporarily with `CTRL-Z`. Next, I ran the command `bg && ping localhost` in order to send thread-java to the background as well as run the endlessly running `ping` command in the terminal as well. Screenshot below:
![Mac Process Terminal](MacTerminal.png)

I opened up Activity Monitor, and found the command running under `java`. At the moment I checked it, it had 78 threads, which is given in the Activity Monitor of OS X.

![Mac Process Activity Monitor](MacActivityMonitor.png)