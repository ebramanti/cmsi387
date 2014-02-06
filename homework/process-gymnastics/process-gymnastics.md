Process Survey
==================

##1. What root-owned processes are you running?

#####Answer

Using bash and ps, I was able to determine a few of the processes that were currently being running at root. Most are the core frameworks and services of Mac OS X Mavericks.

#####Command

    Edwards-MacBook-Air:process-gymnastics Edward$ ps -u root

    
#####Text Dump


    UID PID TTY           TIME CMD
    0     1 ??         1:15.58 /sbin/launchd
    0    11 ??         0:13.11 /usr/libexec/UserEventAgent (System)
    0    12 ??         0:09.65 /usr/libexec/kextd
    0    13 ??         0:07.06 /usr/libexec/taskgated -s
    0    14 ??         0:16.29 /usr/sbin/notifyd
    0    15 ??         0:14.72 /usr/sbin/securityd -i
    0    16 ??         0:13.38 /System/Library/CoreServices/powerd.bundle/powerd
    0    17 ??         2:07.90 /usr/sbin/syslogd
    0    18 ??         0:04.14 /usr/libexec/diskarbitrationd
    0    19 ??         0:37.93 /usr/libexec/configd
    0    21 ??         0:09.36 /usr/sbin/distnoted daemon
    0    22 ??         0:23.37 /usr/libexec/opendirectoryd
    0    41 ??         0:01.81 com.apple.authd
    0    42 ??         0:19.60 /System/Library/CoreServices/coreservicesd
    0    51 ??         0:55.73 /System/Library/Frameworks/CoreServices.framework/Versions/A/Frameworks/CarbonCore.framework
    0    52 ??         0:01.91 /usr/libexec/usbd
    0    55 ??         0:04.20 /usr/sbin/blued
    0    56 ??         3:45.96 sysmond
    0    59 ??         0:00.76 /usr/libexec/networkd_privileged
    0    62 ??         0:00.95 /usr/sbin/ntpd -c /private/etc/ntp-restrict.conf -n -g -p /var/run/ntpd.pid -f /var/db/ntp.d
    0    64 ??         0:00.96 /usr/libexec/warmd
    0    67 ??         0:00.24 /sbin/SystemStarter
    0    69 ??         0:00.32 /usr/libexec/stackshot -t
    0    72 ??         0:02.11 /System/Library/CoreServices/SleepServicesD
    0    74 ??         0:00.70 /System/Library/PrivateFrameworks/GenerationalStorage.framework/Versions/A/Support/revisiond
    0    77 ??         0:06.91 /usr/libexec/pacemaker -b -e 0.0001 -a 10
    0    80 ??        12:02.90 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Support/mds
    501    83 ??         0:28.92 /System/Library/CoreServices/loginwindow.app/Contents/MacOS/loginwindow console
    0    84 ??         0:00.18 /System/Library/CoreServices/logind
    0    86 ??         0:00.05 /usr/sbin/KernelEventAgent
    0    87 ??         0:00.82 /System/Library/PrivateFrameworks/Heimdal.framework/Helpers/kdc
    0    89 ??         5:51.72 /usr/libexec/hidd
    0    91 ??         0:00.06 /sbin/dynamic_pager -F /private/var/vm/swapfile
    0    94 ??         0:17.64 /System/Library/CoreServices/launchservicesd
    0    99 ??         0:00.32 autofsd
    0   102 ??         0:37.67 /usr/libexec/airportd
    0   103 ??         0:00.16 /bin/sh /Library/Parallels/Parallels Service.app/Contents/Resources/ParallelsDispatcherServi
    0   104 ??         0:00.08 /opt/nova/bin/tcprelay
    0   105 ??         0:00.45 /opt/nova/bin/novacomd
    0   106 ??         0:00.05 /Library/Application Support/Glims/Agent/Glims Agent.app/Contents/MacOS/Glims Agent -helper
    88   213 ??        63:40.56 /System/Library/Frameworks/ApplicationServices.framework/Frameworks/CoreGraphics.framework/R
    0   243 ??         0:00.42 /System/Library/Frameworks/OpenGL.framework/Versions/A/Libraries/CVMServer
    0   264 ??         3:42.77 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    0   379 ??         0:00.47 /Library/Parallels/Parallels Service.app/Contents/PlugIns/Parallels NAPT Service.app/Content
    0   393 ??         6:54.43 /Library/Parallels/Parallels Service.app/Contents/MacOS/prl_disp_service -e --logfile /var/l
    0   482 ??         0:00.56 /usr/libexec/securityd_service
    0   645 ??         0:08.30 /System/Library/PrivateFrameworks/ApplePushService.framework/apsd
    0   657 ??         0:00.90 /usr/sbin/filecoordinationd
    0   727 ??         0:00.97 /System/Library/Frameworks/CoreMediaIO.framework/Resources/VDC.plugin/Contents/Resources/VDC
    0   851 ??         0:00.81 /usr/libexec/syspolicyd
    0   931 ??         0:42.44 /usr/sbin/diskmanagementd
    0  1621 ??         0:00.17 /sbin/launchd
    0  1623 ??         0:00.03 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    0  7130 ??         0:03.21 /System/Library/PrivateFrameworks/DiskImages.framework/Resources/diskimages-helper -uuid 05C
    0  7135 ??         0:00.15 /System/Library/PrivateFrameworks/DiskImages.framework/Resources/hdiejectd
    0 10802 ??         0:00.08 com.apple.CodeSigningHelper
    0 10803 ??         0:00.04 /usr/libexec/xpcd
    0 10809 ??         0:01.19 /usr/sbin/cfprefsd daemon
    0 10825 ??         0:04.89 /usr/sbin/ocspd
    0 10851 ??         0:00.13 /usr/libexec/sandboxd -n PluginProcess -n 
    0 10852 ??         0:00.29 /System/Library/PrivateFrameworks/CoreSymbolication.framework/coresymbolicationd
    0 10880 ??         0:03.37 /usr/libexec/systemstatsd
    0 10993 ??         0:07.93 /System/Library/PrivateFrameworks/PackageKit.framework/Resources/installd
    0 11254 ??         0:00.17 /System/Library/PrivateFrameworks/SoftwareUpdate.framework/Resources/suhelperd

##2. What processes are running on your account? 

#####Answer

A lot of the applications that are currently running are my working applications: Sublime Text, MS Processing programs, Chrome, etc.

#####Command

    Edwards-MacBook-Air:process-gymnastics Edward$ ps -u Edward

#####Text Dump

    UID   PID TTY           TIME CMD
    501   462 ??         0:09.00 /sbin/launchd
    501   468 ??         1:09.08 /usr/sbin/distnoted agent
    501   597 ??         0:07.91 /usr/libexec/UserEventAgent (Aqua)
    501   601 ??       101:36.60 /Applications/Google Chrome.app/Contents/MacOS/Google Chrome -psn_0_28679
    501   605 ??         1:20.76 /Applications/Utilities/Terminal.app/Contents/MacOS/Terminal -psn_0_36873
    501   607 ??         4:17.06 /Applications/Sublime Text.app/Contents/MacOS/Sublime Text -psn_0_45067
    501   608 ??         0:24.30 /Applications/Microsoft Office 2011/Microsoft Excel.app/Contents/MacOS/Microsoft Excel -psn_
    501   612 ??         0:22.18 /Applications/Cyberduck.app/Contents/MacOS/Cyberduck -psn_0_61455
    501   613 ??         8:12.96 /Applications/Utilities/Activity Monitor.app/Contents/MacOS/Activity Monitor -psn_0_65552
    501   614 ??         0:24.49 /Applications/App Store.app/Contents/MacOS/App Store -psn_0_69649
    501   615 ??         0:05.12 /Applications/iBooks.app/Contents/MacOS/iBooks -psn_0_73746
    501   617 ??         0:02.48 /System/Library/CoreServices/talagent
    501   618 ??         0:45.52 /System/Library/CoreServices/Dock.app/Contents/MacOS/Dock
    501   619 ??         3:09.99 /System/Library/CoreServices/SystemUIServer.app/Contents/MacOS/SystemUIServer
    501   620 ??         1:57.81 /System/Library/CoreServices/Finder.app/Contents/MacOS/Finder
    501   623 ??         0:00.03 /usr/sbin/pboard
    501   627 ??         0:17.61 /System/Library/Frameworks/ApplicationServices.framework/Frameworks/ATS.framework/Support/fo
    501   640 ??         0:02.78 /usr/sbin/usernoted
    501   641 ??         0:10.52 /System/Library/CoreServices/NotificationCenter.app/Contents/MacOS/NotificationCenter
    501   642 ??         0:02.88 /usr/libexec/sharingd
    501   646 ??         0:01.80 /usr/libexec/librariand
    501   647 ??         0:03.02 /System/Library/PrivateFrameworks/Ubiquity.framework/Versions/A/Support/ubd
    501   649 ??         0:03.12 /System/Library/PrivateFrameworks/MessagesKit.framework/Resources/soagent.app/Contents/MacOS
    501   651 ??         0:04.04 /System/Library/PrivateFrameworks/IMCore.framework/imagent.app/Contents/MacOS/imagent
    501   656 ??         0:02.32 com.apple.dock.extra
    501   666 ??         0:03.76 /System/Library/PrivateFrameworks/IDSCore.framework/identityservicesd.app/Contents/MacOS/ide
    501   668 ??         0:00.96 /usr/libexec/lsboxd
    501   676 ??         0:01.29 /System/Library/CoreServices/SocialPushAgent.app/Contents/MacOS/SocialPushAgent
    501   680 ??         1:13.26 /System/Library/PrivateFrameworks/CalendarAgent.framework/Executables/CalendarAgent
    501   682 ??         1:29.08 /System/Library/PrivateFrameworks/CommerceKit.framework/Versions/A/Resources/storeagent
    501   698 ??         0:04.73 /System/Library/PrivateFrameworks/CommerceKit.framework/Versions/A/Resources/bookstoreagent
    501   699 ??         0:06.42 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    501   709 ??         0:00.38 /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/SpeechSynthes
    501   712 ??         0:08.72 com.apple.WebKit.WebContent
    501   715 ??        20:49.28 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   717 ??         0:21.03 /Applications/Sublime Text.app/Contents/MacOS/plugin_host 607
    501   724 ??         0:02.98 /System/Library/Image Capture/Support/Image Capture Extension.app/Contents/MacOS/Image Captu
    501   734 ??         0:23.31 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   735 ??         2:08.70 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   736 ??        10:35.17 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   740 ??         0:06.86 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   742 ??         0:15.88 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   743 ??         0:01.49 /Library/Application Support/Microsoft/MAU2.0/Microsoft AutoUpdate.app/Contents/MacOS/Micros
    501   745 ??         0:04.15 com.apple.WebKit.WebContent
    501   746 ??         0:03.56 com.apple.WebKit.WebContent
    501   747 ??         0:04.66 com.apple.WebKit.WebContent
    501   748 ??         0:07.50 com.apple.WebKit.WebContent
    501   749 ??         0:19.35 /Library/Application Support/Microsoft/MAU2.0/Microsoft AutoUpdate.app/Contents/MacOS/Micros
    501   760 ??         0:02.57 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper EH.app/
    501   761 ??         0:00.65 /usr/bin/ssh-agent -l
    501   774 ??         0:49.43 /Library/Application Support/Google/GoogleTalkPlugin.app/Contents/MacOS/GoogleTalkPlugin
    501   790 ??         0:05.78 /Library/PreferencePanes/Growl.prefPane/Contents/Resources/GrowlHelperApp.app/Contents/MacOS
    501   791 ??         0:04.16 /System/Library/Services/AppleSpell.service/Contents/MacOS/AppleSpell -psn_0_217141
    501   794 ??         0:20.31 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   795 ??        12:05.27 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   796 ??         4:18.66 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   797 ??         2:12.70 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   798 ??         1:03.45 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   799 ??         1:14.92 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   800 ??        28:19.63 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   804 ??         0:04.08 /Applications/iPhoto.app/Contents/Library/LoginItems/PhotoStreamAgent.app/Contents/MacOS/Pho
    501   814 ??         0:00.32 /Library/Parallels/Parallels Service.app/Contents/PlugIns/Parallels NAPT Service.app/Content
    501   816 ??         0:07.35 /Library/PrivilegedHelperTools/MadCatzSmartTechnology.app/Contents/MacOS/MadCatzSmartTechnol
    501   817 ??         0:01.54 /Library/Application Support/Glims/Agent/Glims Agent.app/Contents/MacOS/Glims Agent -launche
    501   823 ??         0:04.55 /Users/Edward/Library/Application Support/Spotify/SpotifyWebHelper
    501   828 ??         0:01.82 /Library/Application Support/Pharos/Popup.app/Contents/MacOS/Popup
    501   829 ??         3:36.55 /Applications/Flux.app/Contents/MacOS/Flux
    501   831 ??         2:27.17 /Applications/smcFanControl.app/Contents/MacOS/smcFanControl
    501   832 ??         0:02.43 /Library/PreferencePanes/Growl.prefPane/Contents/Resources/GrowlMenu.app/Contents/MacOS/Grow
    501   833 ??         0:01.65 /System/Library/Frameworks/ApplicationServices.framework/Versions/A/Frameworks/SpeechSynthes
    501   835 ??         0:07.13 /Applications/Caffeine.app/Contents/MacOS/Caffeine
    501   840 ??        72:52.78 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   841 ??         0:36.58 /Applications/Mint QuickView.app/Contents/MacOS/Mint QuickView
    501   882 ??         2:22.54 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   890 ??         0:15.39 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   891 ??         1:36.86 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   892 ??         0:58.15 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   899 ??         1:25.06 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   900 ??        18:37.43 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   918 ??         3:09.18 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   923 ??         0:00.08 /System/Library/PrivateFrameworks/KerberosHelper/Helpers/DiskUnmountWatcher
    501   924 ??         4:24.47 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   930 ??         8:11.50 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   936 ??         1:06.06 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   939 ??         0:26.59 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   940 ??         1:46.59 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   941 ??         3:00.59 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   942 ??         1:29.62 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   943 ??        12:18.41 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   944 ??         9:06.50 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   945 ??         0:36.62 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   948 ??         0:00.14 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    501   950 ??         2:03.10 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   957 ??         5:27.82 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   960 ??         3:18.36 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   961 ??         0:37.68 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   962 ??         6:12.60 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   963 ??         1:12.16 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   964 ??         7:54.93 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   965 ??         2:03.16 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   966 ??         0:06.59 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   967 ??         1:08.42 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   968 ??         0:15.69 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   969 ??        29:53.79 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper EH.app/
    501   970 ??         0:18.13 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   971 ??         0:55.35 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501   974 ??         0:00.00 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper EH.app/
    501   975 ??         1:12.74 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  1006 ??         0:00.27 adb -P 5037 fork-server server
    501  1058 ??         0:00.07 /usr/libexec/USBAgent
    501  1088 ??         0:00.12 /System/Library/Frameworks/DiskArbitration.framework/Versions/A/Support/DiskArbitrationAgent
    501  1114 ??         0:06.24 /Applications/Utilities/Disk Utility.app/Contents/MacOS/Disk Utility
    501  1648 ??         0:01.47 /System/Library/PrivateFrameworks/CommerceKit.framework/Resources/LaterAgent.app/Contents/Ma
    501  1661 ??         0:01.55 /System/Library/PrivateFrameworks/CloudServices.framework/Resources/EscrowSecurityAlert.app/
    501  1757 ??         2:42.58 /Applications/Firefox.app/Contents/MacOS/firefox
    501  4279 ??         0:12.06 /System/Library/CoreServices/Dock.app/Contents/Resources/DashboardClient.app/Contents/MacOS/
    501  4395 ??         6:36.49 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  4751 ??         3:28.51 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  4780 ??         3:50.96 /Applications/iPhoto.app/Contents/MacOS/iPhoto
    501  4787 ??         0:01.17 com.apple.qtkitserver
    501  4802 ??        18:28.73 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  6133 ??         0:36.56 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  6855 ??         5:21.83 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  7100 ??         0:13.65 /Applications/Preview.app/Contents/MacOS/Preview
    501  7568 ??         2:03.82 /Applications/Tweetbot.app/Contents/MacOS/Tweetbot
    501  7822 ??         1:52.13 /Applications/GitHub.app/Contents/MacOS/GitHub -psn_0_872661
    501  7831 ??         0:01.31 /Applications/GitHub.app/Contents/Library/LoginItems/GitHub Conduit.app/Contents/MacOS/GitHu
    501  8498 ??         0:01.76 com.apple.geod
    501  8515 ??         0:13.81 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501  8855 ??         0:00.69 /System/Library/PrivateFrameworks/UniversalAccess.framework/Versions/A/Resources/universalAc
    501  8910 ??         0:00.11 /System/Library/PrivateFrameworks/HelpData.framework/Versions/A/Resources/helpd
    501  9129 ??         0:00.00 (open)
    501  9618 ??         0:21.53 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501 10710 ??         2:20.36 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501 10715 ??         0:00.76 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper EH.app/
    501 10766 ??         0:01.20 /usr/sbin/cfprefsd agent
    501 10799 ??         0:00.70 /System/Library/Frameworks/GameKit.framework/Versions/A/Resources/gamed
    501 10800 ??         0:00.13 /System/Library/Frameworks/Accounts.framework/Versions/A/Support/accountsd
    501 10801 ??         0:00.29 /usr/libexec/secd
    501 10804 ??         0:00.16 /usr/libexec/WiFiKeychainProxy
    501 10805 ??         0:00.02 /System/Library/Frameworks/Security.framework/Versions/A/Resources/CloudKeychainProxy.bundle
    501 10807 ??         0:00.29 /usr/libexec/xpcd
    501 10810 ??         0:01.14 com.apple.internetaccounts
    501 10811 ??         0:00.03 /System/Library/PrivateFrameworks/TCC.framework/Resources/tccd
    501 10813 ??         0:00.08 com.apple.NotesMigratorService
    501 10815 ??         0:00.29 /System/Library/CoreServices/pbs
    501 10817 ??         0:06.36 com.apple.IconServicesAgent
    501 10876 ??         0:00.08 /System/Library/CoreServices/ScopedBookmarkAgent
    501 10913 ??         0:00.10 com.apple.InputMethodKit.UserDictionary
    501 10931 ??         0:00.02 com.apple.menuextra.airport.keychainproxy
    501 10933 ??         0:00.03 /System/Library/CoreServices/AirPort Base Station Agent.app/Contents/MacOS/AirPort Base Stat
    501 10955 ??         0:20.33 /System/Library/PrivateFrameworks/DiskImages.framework/Resources/diskimages-helper -uuid 587
    501 11161 ??         0:19.90 /Applications/VirtualBox.app/Contents/MacOS/VirtualBox
    501 11164 ??         0:00.74 /Applications/VirtualBox.app/Contents/MacOS/VBoxXPCOMIPCD
    501 11166 ??         0:09.32 /Applications/VirtualBox.app/Contents/MacOS/VBoxSVC --auto-shutdown
    501 11375 ??         0:00.02 ssh -f tbramant@my.cs.lmu.edu -L 2000:my.cs.lmu.edu:25 -N
    501 11385 ??         0:00.00 ssh -f tbramant@my.cs.lmu.edu -L 2000:my.cs.lmu.edu:25 -N
    501 11387 ??         0:00.00 ssh -f tbramant@my.cs.lmu.edu -L 2000:my.cs.lmu.edu:25 -N
    501 11504 ??         0:00.04 /System/Library/Frameworks/CFNetwork.framework/Versions/A/Support/cookied
    501 11532 ??         0:00.48 com.apple.iCloudHelper
    501 11546 ??         0:00.38 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    501 11548 ??         0:00.20 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    501 11553 ??         0:01.26 /Applications/Google Chrome.app/Contents/Versions/32.0.1700.102/Google Chrome Helper.app/Con
    501 11554 ??         0:00.08 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    501 11555 ??         0:00.06 /System/Library/Frameworks/CoreServices.framework/Frameworks/Metadata.framework/Versions/A/S
    0   701 ttys001    0:00.02 login -pfl Edward /bin/bash -c exec -la bash /bin/bash
    501   702 ttys001    0:00.20 -bash
    0 11556 ttys001    0:00.01 ps -u Edward

##4. Login to my.cs.lmu.edu. Who else, other than root and you, has processes running at that time? 

#####Answer

For this command, I used 5 commands piped together. `ps aux` shows all processes for all users. From there, I used `grep` to narrow my search space. I gave a pattern that checked at the beginning of each line and removed all those containing tbramant and root (required as part of question). From there, I returned only USER from the normal dump of text. From there, I combined `sort | uniq` to return only once each process running.

#####Command

    ps aux | grep ^[^tbramant^root] | awk '{print$1}' | sort | uniq

#####Text Dump

    1000
    102
    cblokker
    daemon
    dondi
    jpiatos
    postfix
    statd
    syslog
    USER
    www-data
    zkansil