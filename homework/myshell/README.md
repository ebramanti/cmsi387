Points to Ponder
================

1. The `cd` command received special mention in this assignment because the `exec()` command does not work with `cd`. `cd` does not have an executable file; instead, the command updates the directory pointer of what directory the shell is currently looking at. Because of this, `exec()` would not work in this instance, which is why I used `chdir()` to pass my arguments in my code instead.

> JD: Wellllll...actually the absence of an executable is circumstantial, and is not
>     the core reason (e.g., OS X has a `/usr/bin/cd`—go check).
>
>     The second part of your answer looks closer to what we're looking for, but isn't
>     quite phrased precisely, making me uncertain if you genuinely arrived at the
>     true reason for the special treatment.

2. The answer to this question is tricky: no, it can not run scripts that are programs. Since only `execvp()`, `chdir()`, and `exit` are possible commands, there is no way to compile and run a script that is a program. Nevertheless, it can run a script that is a list of commands and arguments. For example, if I were to pass the following code below, it would run it.
        
        ls -l
        cd ..
        pwd
        ls

> JD: The qualification that you give is noted, but you did hit on the key concept,
>     which is that a "script" can be as simple as a file with commands in it.
>     Other elements like control structures or variables can come later.

3. `CTRL+D` does exit my shell. Since I have a loop searching for an end-of-file(`EOF`), using `CTRL+D` signals to the shell that it is at the end of file, and should exit the loop.

> JD: Yes, yes it does.
