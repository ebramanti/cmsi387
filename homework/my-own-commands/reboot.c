//  reboot.c, a system call that will restart computer.
//  Man page: http://linux.die.net/man/2/reboot
//	Interesting note about the "magic numbers" of Linux Reboot system calls.
//  http://stackoverflow.com/questions/4808748/magic-numbers-of-the-linux-reboot-system-call
//  Also from man pages: "Only the superuser may call reboot()."

//	Recommended implementation from man pages.
#include <unistd.h>
#include <linux/reboot.h>

int main(int argc, char *argv[]) {
    syscall(88,  LINUX_REBOOT_MAGIC1,  LINUX_REBOOT_MAGIC2, LINUX_REBOOT_CMD_RESTART);
    //	From man pages: "Successful call to reboot does not return."
    // JD: LOL obviously right?  Glad you enjoyed the magic number learnage.
    //
    // JD: But if unsuccessful...(like if the user is not super)...a little
    //     acknowledgement would have been nice.
}