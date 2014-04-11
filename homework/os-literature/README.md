Operating Systems Literature Analysis
=====================================

### Article 1: Limitations of Dijkstra's Semaphore Primitives and Petri nets by S. Rao Kosaraju

This article is connected to the original work because it studies the limitations of Dijkstra's semaphore primitives that he postulates about in his original work in 1965. They expand upon Dijkstra's findings by focusing on areas of his original research that have been improved upon and through discussion of the work of multiple researchers who have studied Dijkstra's solution.

This article approaches the original work in an entirely different way. While Dijkstra's original method was to use P and V primitives, they are considered to be indivisible in this work. Kosaraju studies a better approach through a work by Patil and his discovery, which he calls "CSP," or the "Cigarette Smoker's Problem." Patil suggests a generalization of the P primitive as a better method. Patil's work is even expanded upon, with Parnas' work to further the study of Patil's "Cigarette Smoker's Problem," showing that using an array of semaphores brings this issue Patil discovered back. Parnas solves this problem by making arrays of semaphores that are finite and bounded.

I believe that this article is well-written for a few reasons. It demonstrates an attention to multiple research projects regarding Dijkstra's original paper, and compiles them in a way to effectively show the limitations of his work. Kosaraju, the original writer of this piece, recognizes solutions people have come up for the limitations of cooperating sequential processes. The ACM Digital Library has published this work as well, which leads me to believe it is trustworthy research on Dijkstra's original problem.

### Article 2: A new solution to the critical section problem by Howard P. Katseff

This article is connected with Knuth's original work because it is improved and expanded upon by Eisenberg and McGuire in 1972. This is discussed in the new solution. The article also cites and makes mention of Dijkstra's work from 1965, which is another included article in the collection of works we are trying to connect to.

Katseff offers up the idea of allowing processes to enter their critical sections on a first-come, first-serve basis. It is useful to the field because it solves the problem where processes that repeatedly die and wake might prevent other processes from entering their critical sections. He also expands on Eisenberg and McGuire's solution, citing that they have an issue when two processes are in each other's behind-of list. He says that this could lead to a problem for processes that are subject to critical sections, and says that to correct this problem, you need to introduce additional variables to determine which process has last begun its protocol. 

Katseff is citing previous work of his own in the field, which leads me to believe that he is addressing this with a mentality of going over his own work. Once again, since this is found on ACM's Digital Library, the work proves its validity. It cites multiple researchers who have done work on this problem, and provided examples of problems with each. This makes Katseff's presentation of the issue more valid.

### Article 3: A New Solution to Lamport's Concurrent Programming Problem Using Small Shared Variables by Gary L. Peterson

The article is connected to Lamport's solution to Dijkstra's concurrent programming problem. It also cites both of the previous works that we compared to, both Knuth's comments on concurrent programming control and Dijkstra's solution from 1965.

Peterson's new solution to concurrent programming control prevents process failures and restarts by using a new algorithm. The algorithm uses four values of shared memory per process, as shown by the title of "using small shared variables." Peterson argues that using this method will help lower the rate of failures. He also argues that if failures are rare, then the clock will most likely stabilize and the processes are more likely to tick in unison than before. He does contend that while his algorithm allows for a more stable clock, the number of values when using small shared variables is worse than exponential.

Peterson's work is not as strong as the previous work studied. It has less references, and while it does build upon previous solutions of Dijkstra, Knuth, and Lamport, there is still room to improve upon the work, especially since the small shared variables is worse than exponential. Nevertheless, Peterson's work improves upon some of the problems that Lamport ran into, and using shared variables provides a solid solution to both process failures and forced restarts. Peterson doesn't even have to worry about those types of errors like Lamport's solution.





